#define safe_read(Addr, Type) Read<Type>(Addr)
#define safe_write(Addr, Data, Type) write<Type>(Addr, Data)

HWND hWnd;
uintptr_t pID;

uintptr_t base_address = 0;
std::uint32_t process_id = 0;

uintptr_t game_assembly_base_adress;
uintptr_t unity_player_base_adress;




inline uintptr_t oBaseAddress = 0;
inline std::uint32_t oPID = 0;



typedef struct _NULL_MEMORY 
{
    void* buffer_address;
    UINT_PTR address;
    ULONGLONG size;
    ULONG pid;
    BOOLEAN write;
    BOOLEAN read;
    BOOLEAN req_base;
    void* output;
    const char* module_name;
    ULONG64 base_address;
}NULL_MEMORY;

template<typename ... Arg>
uint64_t call_hook(const Arg ... args)
{
    //NtGdiDdDDINetDispStopMiracastDisplayDevice
    void* hooked_func = GetProcAddress(LoadLibrary(xorstr("win32u.dll")), xorstr("NtGdiDdDDINetDispGetNextChunkInfo"));

    auto func = static_cast<uint64_t(_stdcall*)(Arg...)>(hooked_func);

    return func(args ...);
}
struct HandleDisposer
{
    using pointer = HANDLE;
    void operator()(HANDLE handle) const
    {
        if (handle != NULL || handle != INVALID_HANDLE_VALUE)
        {
            CloseHandle(handle);
        }
    }
};
using unique_handle = std::unique_ptr<HANDLE, HandleDisposer>;

std::uint32_t get_process_id(std::string_view process_name)
{
    PROCESSENTRY32 processentry;
    const unique_handle snapshot_handle(CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL));

    if (snapshot_handle.get() == INVALID_HANDLE_VALUE)
        return NULL;

    processentry.dwSize = sizeof(MODULEENTRY32);

    while (Process32Next(snapshot_handle.get(), &processentry) == TRUE)
    {
        if (process_name.compare(processentry.szExeFile) == NULL)
        {
            return processentry.th32ProcessID;
        }
    }
    return NULL;
}
static ULONG64 get_module_base_address(const char* module_name)
{
    NULL_MEMORY instructions = { 0 };
    instructions.pid = process_id;
    instructions.req_base = TRUE;
    instructions.read = FALSE;
    instructions.write = FALSE;
    instructions.module_name = module_name;
    call_hook(&instructions);

    ULONG64 base = NULL;
    base = instructions.base_address;
    return base;
}
template <class T>
T Read(uintptr_t read_address)
{
    T response{};
    NULL_MEMORY instructions;
    instructions.pid = process_id;
    instructions.size = sizeof(T);
    instructions.address = read_address;
    instructions.read = TRUE;
    instructions.write = FALSE;
    instructions.req_base = FALSE;
    instructions.output = &response;
    call_hook(&instructions);

    return response;
}
bool write_memory(UINT_PTR write_address, UINT_PTR source_address, SIZE_T write_size)
{
    NULL_MEMORY instructions;
    instructions.address = write_address;
    instructions.pid = process_id;
    instructions.write = TRUE;
    instructions.read = FALSE;
    instructions.req_base = FALSE;
    instructions.buffer_address = (void*)source_address;
    instructions.size = write_size;

    call_hook(&instructions);

    return true;
}
bool read(UINT_PTR address, void* buffer, SIZE_T size)
{

    NULL_MEMORY instructions;
    instructions.read = TRUE;
    instructions.write = FALSE;
    instructions.req_base = FALSE;

    instructions.pid = process_id;
    instructions.size = size;
    instructions.address = address;
    instructions.output = buffer;

    call_hook(&instructions);


    return true;

}
template<typename S>
bool write(UINT_PTR write_address, const S& value)
{
    return write_memory(write_address, (UINT_PTR)&value, sizeof(S));
}
static std::string read_string(UINT_PTR String_address, SIZE_T size, bool esp_driver = false)
{
    std::unique_ptr<char[]> buffer(new char[size]);
    read(String_address, buffer.get(), size);
    return std::string(buffer.get());
}

static std::wstring read_wstring(UINT_PTR String_address, SIZE_T size, bool esp_driver = false)
{
    const auto buffer = std::make_unique<wchar_t[]>(size);
    read(String_address, buffer.get(), size * 2);
    return std::wstring(buffer.get());
}
int length(uintptr_t addr) { return safe_read(addr + 0x10, int); }
std::string readstring(uintptr_t addr) {
    try {
        static char buff[128] = { 0 };
        buff[length(addr)] = '\0';

        for (int i = 0; i < length(addr); ++i) {
            if (buff[i] < 128) {
                buff[i] = safe_read(addr + 0x14 + (i * 2), UCHAR);
            }
            else {
                buff[i] = '?';
                if (buff[i] >= 0xD800 && buff[i] <= 0xD8FF)
                    i++;
            }
        }
        return std::string(&buff[0], &buff[length(addr)]);
    }
    catch (const std::exception& exc) {}
    return XorStr("Error");
}