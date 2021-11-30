#pragma warning(disable : 4996)

bool ShowMenu = false;

#include <windows.h>
#include <winternl.h>
#include <process.h>
#include <tlhelp32.h>
#include <inttypes.h>
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <chrono>
#include <sstream>
#include <memory>
#include <string_view>
#include <cstdint>
#include <string>
#include <cmath>
#include <thread>
#include <cassert>
#include <xstring>
#include <vector>
#include <map>
#include <array>
#include <sstream>
#include <fstream>
#include <direct.h>

#include "xor.h"
#include "1xor.h"
#include "settings.h"
#include "math/math.h"
#include "init/overlay.h"
#include "mem_driver/hello.h"
#include "offsets.h"
#include "sdk/sdk.h"
#include "sdk/aim.h"

void HelpMarker(const char* desc)
{
	ImGui::TextDisabled(xorstr("[?]"));
	if (ImGui::IsItemHovered( ))
	{
		ImGui::BeginTooltip( );
		ImGui::PushTextWrapPos(ImGui::GetFontSize( ) * 35.0f);
		ImGui::TextUnformatted(desc);
		ImGui::PopTextWrapPos( );
		ImGui::EndTooltip( );
	}
}

void drawings( ) {
	ImGui::SetNextWindowSize(ImVec2(GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN)));

	ImGui::SetNextWindowPos(ImVec2(0, 0));

	ImGui::Begin(xorstr("mainss"), NULL, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_None | ImGuiWindowFlags_NoInputs | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoFocusOnAppearing);
	{
		std::thread(find_players).join( );
	}
	ImGui::End( );
}

void hello_world( ) {
	ImGui_ImplDX9_NewFrame( );
	ImGui_ImplWin32_NewFrame( );
	ImGui::NewFrame( );
	drawings( );
	static bool isDown = false;
	static bool isClicked = false;
	if (GetAsyncKeyState(VK_INSERT)) {
		isClicked = false;
		isDown = true;
	}
	else if (!GetAsyncKeyState(VK_INSERT) && isDown) {
		isClicked = true;
		isDown = false;
	}
	else {
		isClicked = false;
		isDown = false;
	}

	if (isClicked) {
		ShowMenu = !ShowMenu;
	}

	if (ShowMenu)
	{
		ImGui::PushFont(m_pFont2);
		{
			if (ImGui::Begin(xorstr("Rust"), 0, ImGuiWindowFlags_NoTitleBar | NULL | NULL | NULL | ImGuiWindowFlags_NoResize | NULL | NULL | NULL | NULL))
			{

				ImGui::SetWindowPos(ImVec2(500, 500), ImGuiCond_Once);
				ImGui::SetWindowSize(ImVec2(500, 400), ImGuiCond_Once);
				static int tab = 0;
				if (ImGui::Button(xorstr("Misc")))
				{
					tab = 0;
				}
				ImGui::SameLine();
				if (ImGui::Button(xorstr("Players")))
				{
					tab = 1;
				}

				if (tab == 0) {
					ImGui::Checkbox(xorstr("silent aim"), &aim::silentaim);
					ImGui::Checkbox(xorstr("aim bot"), &aim::aimbot);
					ImGui::Checkbox(xorstr("no recoil"), &misc::norecoil);
					ImGui::Checkbox(xorstr("no spread"), &misc::nospread);
					ImGui::Checkbox(xorstr("auto sprint"), &misc::autosprint);
					//ImGui::Checkbox(xorstr("omni sprint"), &misc::omnisprint);
					ImGui::Checkbox(xorstr("shoot any where"), &misc::shootanywhere);
					ImGui::Checkbox(xorstr("fakeadmin"), &misc::fakeadmin);
					ImGui::Checkbox(xorstr("infinity jump"), &misc::inifinityjump);
					ImGui::Checkbox(xorstr("spiderman"), &misc::spiderman);
					ImGui::Checkbox(xorstr("long neck 5m"), &misc::longneck);
					ImGui::Checkbox(xorstr("fastbow"), &misc::fastbow);
					ImGui::Checkbox(xorstr("automatic"), &misc::automatic);
					ImGui::Checkbox(xorstr("fastshots"), &misc::fastshots);
					ImGui::Checkbox(xorstr("canWieldItems"), &misc::canWieldItems);
					ImGui::Checkbox(xorstr("fatbullet"), &misc::fatbullet);
					ImGui::Checkbox(xorstr("fastbullet"), &misc::fastbullet);
				}

				if (tab == 1) {
					ImGui::Checkbox(xorstr("box"), &player::box);
					ImGui::Checkbox(xorstr("name"), &player::name);
					ImGui::Checkbox(xorstr("health"), &player::health);
					ImGui::Checkbox(xorstr("dist"), &player::dist);
					ImGui::Checkbox(xorstr("show active item"), &player::showweapon);
					ImGui::Checkbox(xorstr("show eye direction"), &player::showeyeview);
					ImGui::SliderFloat(xorstr("fov"), &misc::Fov, 90.f, 120.f);
					ImGui::Checkbox(xorstr("zoom"), &misc::zoom);
					ImGui::SliderFloat(xorstr("custom time"), &misc::time, 0.f, 12.f);
					if (ImGui::Button(xorstr("init"))) {
					
					}
				}
				ImGui::SetCursorPos({ 450.f,330.f });
				if (ImGui::Button(xorstr("close"))) {
					exit(0);
				}
			}
		}
		ImGui::PopFont( );
		ImGui::End( );
	}


	ImGui::EndFrame( );
	D3dDevice->SetRenderState(D3DRS_ZENABLE, false);
	D3dDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, false);
	D3dDevice->SetRenderState(D3DRS_SCISSORTESTENABLE, false);
	D3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_ARGB(0, 0, 0, 0), 1.0f, 0);

	if (D3dDevice->BeginScene( ) >= 0)
	{
		ImGui::Render( );
		ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
		D3dDevice->EndScene( );
	}
	HRESULT result = D3dDevice->Present(NULL, NULL, NULL, NULL);

	if (result == D3DERR_DEVICELOST && D3dDevice->TestCooperativeLevel( ) == D3DERR_DEVICENOTRESET)
	{
		ImGui_ImplDX9_InvalidateDeviceObjects( );
		D3dDevice->Reset(&d3dpp);
		ImGui_ImplDX9_CreateDeviceObjects( );
	}
}

MSG Message = { NULL };
void Loop( )
{
	static RECT old_rc;
	ZeroMemory(&Message, sizeof(MSG));

	while (Message.message != WM_QUIT)
	{
		if (PeekMessage(&Message, Window, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&Message);
			DispatchMessage(&Message);
		}

		HWND hwnd_active = GetForegroundWindow();

		if (hwnd_active == hwnd) {
			HWND hwndtest = GetWindow(hwnd_active, GW_HWNDPREV);
			SetWindowPos(Window, hwndtest, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
		}

		RECT rc;
		POINT xy;

		ZeroMemory(&rc, sizeof(RECT));
		ZeroMemory(&xy, sizeof(POINT));
		GetClientRect(hwnd, &rc);
		ClientToScreen(hwnd, &xy);
		rc.left = xy.x;
		rc.top = xy.y;

		ImGuiIO& io = ImGui::GetIO();
		io.ImeWindowHandle = hwnd;
		io.DeltaTime = 1.0f / 60.0f;

		POINT p;
		GetCursorPos(&p);
		io.MousePos.x = (float)p.x - (float)xy.x;
		io.MousePos.y = (float)p.y - (float)xy.y;

		if (GetAsyncKeyState(VK_LBUTTON)) {
			io.MouseDown[0] = true;
			io.MouseClicked[0] = true;
			io.MouseClickedPos[0].x = io.MousePos.x;
			io.MouseClickedPos[0].x = io.MousePos.y;
		}
		else
			io.MouseDown[0] = false;

		if (rc.left != old_rc.left || rc.right != old_rc.right || rc.top != old_rc.top || rc.bottom != old_rc.bottom)
		{
			old_rc = rc;

			Width = rc.right;
			Height = rc.bottom;
			wLeft = rc.left;
			wTop = rc.top;

			d3dpp.BackBufferWidth = Width;
			d3dpp.BackBufferHeight = Height;
			SetWindowPos(Window, (HWND)0, xy.x, xy.y, Width, Height, SWP_NOREDRAW);
			D3dDevice->Reset(&d3dpp);
		}
		std::thread(localplayer_functions).detach( );
		hello_world( );
	}
	ImGui_ImplDX9_Shutdown( );
	ImGui_ImplWin32_Shutdown( );
	ImGui::DestroyContext( );

	DestroyWindow(Window);
}

void loadcheat( ) {
	std::thread(&find_loco).detach( );
	CreateThread(0, 0, LP22, 0, 0, 0);
}

void init_overlay( ) {	
	while (hwnd == NULL)
	{
		printf(xorstr("plese plese rust"));
		Sleep(50);
		system(xorstr("cls"));
		hwnd = FindWindow(xorstr("UnityWndClass"), xorstr("Rust"));
		Sleep(100);
	}
	MessageBox(0, xorstr("cheat loaded"), xorstr("Info"), 0);
	loadcheat( );
	CreateOWindow();
	InitializeD3D();
	Loop();
	Shutdown();
}

int main( ) {
	init_overlay( );
	//credits PIDARAS SOURCE I AM NOT GETTED MY MONEY AND SOURCE GO TO PUBLIC | XARIZ CRYING FOR THIS 1 HOURS FOR I GIVES HIM THIS; shmiga#5700
}