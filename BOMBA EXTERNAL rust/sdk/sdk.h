#include <intrin.h>



enum PlayerFlags : int
{
	Unused1 = 1,
	Unused2 = 2,
	IsAdmin = 4,
	ReceivingSnapshot = 8,
	Sleeping = 16,
	Spectating = 32,
	Wounded = 64,
	IsDeveloper = 128,
	Connected = 256,
	ThirdPersonViewmode = 1024,
	EyesViewmode = 2048,
	ChatMute = 4096,
	NoSprint = 8192,
	Aiming = 16384,
	DisplaySash = 32768,
	Relaxed = 65536,
	SafeZone = 131072,
	ServerFall = 262144,
	Incapacitated = 524288,
	Workbench1 = 1048576,
	Workbench2 = 2097152,
	Workbench3 = 4194304,
};
/*enum Flag : int
{
	Ducked = 1,
	Jumped = 2,
	OnGround = 4,
	Sleeping = 8,
	Sprinting = 16,
	OnLadder = 32,
	Flying = 64,
	Aiming = 128,
	Prone = 256,
	Mounted = 512,
	Relaxed = 1024
};*/
enum BoneList : int
{
	pelvis = 0,
	l_hip = 1,
	l_knee = 2,
	l_foot = 3,
	l_toe = 4,
	l_ankle_scale = 5,
	penis = 6,
	GenitalCensor = 7,
	GenitalCensor_LOD0 = 8,
	Inner_LOD0 = 9,
	GenitalCensor_LOD1 = 11,
	GenitalCensor_LOD2 = 12,
	r_hip = 13,
	r_knee = 14,
	r_foot = 15,
	r_toe = 16,
	r_ankle_scale = 17,
	spine1 = 18,
	spine1_scale = 19,
	spine2 = 20,
	spine3 = 21,
	spine4 = 22,
	l_clavicle = 23,
	l_upperarm = 24,
	l_forearm = 25,
	l_hand = 26,
	l_index1 = 27,
	l_index2 = 28,
	l_index3 = 29,
	l_little1 = 30,
	l_little2 = 31,
	l_little3 = 32,
	l_middle1 = 33,
	l_middle2 = 34,
	l_middle3 = 35,
	l_prop = 36,
	l_ring1 = 37,
	l_ring2 = 38,
	l_ring3 = 39,
	l_thumb1 = 40,
	l_thumb2 = 41,
	l_thumb3 = 42,
	IKtarget_righthand_min = 43,
	IKtarget_righthand_max = 44,
	l_ulna = 45,
	neck = 46,
	head = 47,
	jaw = 48,
	eyeTranform = 49,
	l_eye = 50,
	l_Eyelid = 51,
	r_eye = 52,
	r_Eyelid = 53,
	r_clavicle = 54,
	r_upperarm = 55,
	r_forearm = 56,
	r_hand = 57,
	r_index1 = 58,
	r_index2 = 59,
	r_index3 = 60,
	r_little1 = 61,
	r_little2 = 62,
	r_little3 = 63,
	r_middle2 = 65,
	r_middle3 = 66,
	r_prop = 67,
	r_ring1 = 68,
	r_ring2 = 69,
	r_ring3 = 70,
	r_thumb1 = 71,
	r_thumb2 = 72,
	r_thumb3 = 73,
	IKtarget_lefthand_min = 74,
	IKtarget_lefthand_max = 75,
	r_ulna = 76,
	l_breast = 77,
	r_breast = 78,
	BoobCensor = 79,
	BreastCensor_LOD0 = 80,
	BreastCensor_LOD1 = 83,
	BreastCensor_LOD2 = 84
};

class RecoilProperties {
public:
	void recoilYawMin(Vector2 d) {
		safe_write((const uintptr_t)this + O::RecoilProperties::recoilYawMin, d, Vector2);
	}
	void recoilYawMax(Vector2 d) {
		safe_write((const uintptr_t)this + O::RecoilProperties::recoilYawMax, d, Vector2);
	}
	void recoilPitchMin(Vector2 d) {
		safe_write((const uintptr_t)this + O::RecoilProperties::recoilPitchMin, d, Vector2);
	}
	void recoilPitchMax(Vector2 d) {
		safe_write((const uintptr_t)this + O::RecoilProperties::recoilPitchMax, d, Vector2);
	}
	void ADSScale(Vector2 d) {
		safe_write((const uintptr_t)this + O::RecoilProperties::ADSScale, d, Vector2);
	}
	void movementPenalty(Vector2 d) {
		safe_write((const uintptr_t)this + O::RecoilProperties::movementPenalty, d, Vector2);
	}
};

class BaseProjectile {
public:
	void automatic(bool d) {
		safe_write((const uintptr_t)this + O::BaseProjectile::automatic, d, bool);
	}
	void repeatDelay(float d) {
		safe_write((const uintptr_t)this + O::AttackEntity::repeatDelay, d, float);
	}
	void successFraction(float d) {
		safe_write((const uintptr_t)this + O::FlintStrikeWeapon::successFraction, d, float);
	}
	void _didSparkThisFrame(bool d) {
		safe_write((const uintptr_t)this + O::FlintStrikeWeapon::_didSparkThisFrame, d, bool);
	}
	void attackready(bool d) {
		safe_write((const uintptr_t)this + O::BowWeapon::attackReady, d, bool);
	}
	DWORD64 createdProjectiles( ) {
		return safe_read((const uintptr_t)this + O::BaseProjectile::createdProjectiles, DWORD64);
	}
	RecoilProperties* recoil( ) {
		return (RecoilProperties*)safe_read((const uintptr_t)this + O::BaseProjectile::recoil, DWORD64);
	}
	void StancePenalty(float d) {
		safe_write((const uintptr_t)this + O::BaseProjectile::stancePenalty, d, float);
	}
	void AimconePenalty(float d) {
		safe_write((const uintptr_t)this + O::BaseProjectile::aimconePenalty, d, float);
	}
	void AimCone(float d) {
		safe_write((const uintptr_t)this + O::BaseProjectile::aimCone, d, float);
	}
	void HipAimCone(float d) {
		safe_write((const uintptr_t)this + O::BaseProjectile::hipAimCone, d, float);
	}
	void AimconePenaltyPerShot(float d) {
		safe_write((const uintptr_t)this + O::BaseProjectile::aimconePenaltyPerShot, d, float);
	}
	void projectileVelocityScale(float d) {
		safe_write((const uintptr_t)this + O::BaseProjectile::projectileVelocityScale, d, float);
	}
};

class baseprojectile {
public:

	int GetID( )
	{
		const auto Info = safe_read((const uintptr_t)this + 0x20, DWORD64);
		const int ID = safe_read(Info + 0x18, int);
		return ID;
	}
	BaseProjectile* heldEntity( ) {
		return (BaseProjectile*)safe_read((const uintptr_t)this + O::Item::heldEntity, DWORD64);
	}
	int get_uid( )
	{
		return safe_read((const uintptr_t)this + 0x28, int);
	}
	Weapon Info( ) {
		int ID = GetID( );
		for (Weapon k : info228) {
			if (k.id == ID) {
				return k;
			}
		}
		return Weapon{ 0 };
	}
	int LoadedAmmo( )
	{
		const auto Held = safe_read((const uintptr_t)this + O::Item::heldEntity, DWORD64);
		if (Held <= 0)
			return 0;
		const auto Magazine = safe_read(Held + O::BaseProjectile::primaryMagazine, DWORD64);
		if (Magazine <= 0 || Magazine == 0x3F000000)
		{
			return 0;
		}
		const auto ammoType = safe_read(Magazine + 0x20, DWORD64);
		if (ammoType <= 0 || ammoType == 0x3F000000)
		{
			return 0;
		}
		const int ammo = safe_read(ammoType + 0x18, int);
		return ammo;
	}

};

class MOV {
public:

	float groundAngle( ) {
		return safe_read((const uintptr_t)this + O::PlayerWalkMovement::groundAngle, float);
	}
	float groundAngleNew( ) {
		return safe_read((const uintptr_t)this + O::PlayerWalkMovement::groundAngleNew, float);
	}

	void groundAngle(float d) {
		safe_write((const uintptr_t)this + O::PlayerWalkMovement::groundAngle, d, float);
	}
	void groundAngleNew(float d) {
		safe_write((const uintptr_t)this + O::PlayerWalkMovement::groundAngleNew, d, float);
	}

	Vector3 vector_groundAngle( ) {
		return safe_read((const uintptr_t)this + O::PlayerWalkMovement::groundAngleNew, Vector3);
	}
	Vector3 vector_groundAngleNew( ) {
		return safe_read((const uintptr_t)this + O::PlayerWalkMovement::groundAngleNew, Vector3);
	}

	void vector_groundAngle(Vector3 d) {
		safe_write((const uintptr_t)this + O::PlayerWalkMovement::groundAngle, d, Vector3);
	}
	void vector_groundAngleNew(Vector3 d) {
		safe_write((const uintptr_t)this + O::PlayerWalkMovement::groundAngleNew, d, Vector3);
	}
	void sprintForced(bool d) {
		safe_write((const uintptr_t)this + O::PlayerWalkMovement::sprintForced, d, bool);
	}
	void grounded(float d) {
		safe_write((const uintptr_t)this + O::BaseMovement::Groundedk__BackingField, d, float);
	}
	Vector3 TargetMovement( ) {
		return safe_read((const uintptr_t)this + O::BaseMovement::TargetMovementk__BackingField, Vector3);
	}
	void TargetMovement(Vector3 d) {
		safe_write((const uintptr_t)this + O::BaseMovement::TargetMovementk__BackingField, d, Vector3);
	}

	bool swimming( ) {
		return safe_read((const uintptr_t)this + O::PlayerWalkMovement::swimming, bool);
	}
	bool jumping( ) {
		return safe_read((const uintptr_t)this + O::PlayerWalkMovement::jumping, bool);
	}
	float Duckingk__BackingField( ) {
		return safe_read((const uintptr_t)this + O::BaseMovement::Duckingk__BackingField, float);
	}
	void Running(float d) {
		safe_write((const uintptr_t)this + O::BaseMovement::Runningk__BackingField, d, float);
	}

};

class playereyes {
public:

	Vector3 viewoffset( ) {
		return safe_read((const uintptr_t)this + O::PlayerEyes::viewOffset, Vector3);
	}
	void viewoffset(Vector3 d) {
		safe_write((const uintptr_t)this + O::PlayerEyes::viewOffset, d, Vector3);
	}
	void bodyrotation(Vector4 d) {
		safe_write((const uintptr_t)this + O::PlayerEyes::bodyRotationk__BackingField, d, Vector4);
	}

};
class baseplayer;
class SkinSet {
public:
	void HeadMaterial(uintptr_t d) {
		safe_write((const uintptr_t)this + 0x68, d, uintptr_t);
	}
	void BodyMaterial(uintptr_t d) {
		safe_write((const uintptr_t)this + 0x70, d, uintptr_t);
	}
	void EyeMaterial(uintptr_t d) {
		safe_write((const uintptr_t)this + 0x78, d, uintptr_t);
	}
};

class SkinSetCollection {
public:
	SkinSet* Skins( ) {
		return (SkinSet*)safe_read((const uintptr_t)this + 0x18, DWORD64);
	}
};

class SkinnedMultiMesh {
public:
	void parts(uintptr_t d) {
		safe_write((const uintptr_t)this + 0x30, d, uintptr_t);
	}
	void createdParts(uintptr_t d) {
		safe_write((const uintptr_t)this + 0x38, d, uintptr_t);
	}
	
};

class playermodel {
public:
	bool isnpc( ) {
		return safe_read((const uintptr_t)this + O::PlayerModel::IsNpck__BackingField, bool);
	}
	Vector3 newVelocity( ) {
		return safe_read((const uintptr_t)this + O::PlayerModel::newVelocity, Vector3);
	}
	bool visible( ) {
		return safe_read((const uintptr_t)this + O::PlayerModel::visible, bool);
	}
	SkinSetCollection* MaleSkin( ) {
		return (SkinSetCollection*)safe_read((const uintptr_t)this + O::PlayerModel::MaleSkin, DWORD64);
	}
	SkinSetCollection* FemaleSkin( ) {
		return (SkinSetCollection*)safe_read((const uintptr_t)this + O::PlayerModel::FemaleSkin, DWORD64);
	}
	SkinnedMultiMesh* _multiMesh( ) {
		return (SkinnedMultiMesh*)safe_read((const uintptr_t)this + O::PlayerModel::_multiMesh, uintptr_t);
	}
	uintptr_t multiMesh( ) {
		return safe_read((const uintptr_t)this + O::PlayerModel::_multiMesh, uintptr_t);
	}
	bool wasCrawling( ) {
		return safe_read((const uintptr_t)this + O::PlayerModel::wasCrawling, bool);
	}
};
	
class playerinput {
public:
	Vector2 bodyangles() {
		return safe_read((const uintptr_t)this + O::PlayerInput::bodyAngles, Vector2);
	}
	void bodyangles(Vector2 d) {
		safe_write((const uintptr_t)this + O::PlayerInput::bodyAngles, d, Vector2);
	}
	Vector2 recoilAngles( ) {
		return safe_read((const uintptr_t)this + O::PlayerInput::recoilAngles, Vector2);
	}
};

class ItemContainer {
public:
	DWORD64 itemList( ) {
		return safe_read((const uintptr_t)this + O::ItemContainer::itemList, DWORD64);
	}
};


class playerinventory {
public:
	ItemContainer* containerBelt( ) {
		return (ItemContainer*)safe_read((const uintptr_t)this + O::PlayerInventory::containerBelt, DWORD64);
	}
	ItemContainer* containerWear( ) {
		return (ItemContainer*)safe_read((const uintptr_t)this + O::PlayerInventory::containerWear, DWORD64);
	}
};

class Transform {
public:

};

class ModelState {
public:
	int flags( ) {
		return safe_read((const uintptr_t)this + O::ModelState::flags, int);
	}
	float waterlevel( ) {
		return safe_read((const uintptr_t)this + O::ModelState::waterLevel, float);
	}
	void setflag(int f, bool b)
	{
		auto flags = safe_read((const uintptr_t)this + O::ModelState::flags, int);
		if (b)
			flags |= (int)f;
		else
			flags &= ~(int)f;

		safe_write((const uintptr_t)this + O::ModelState::flags, flags, int);
	}
	void setsprinting(bool value) {
		setflag(16, true);
	}
};

class BaseMountable {
public:
	void canWieldItems(bool d) {
		safe_write((const uintptr_t)this + O::BaseMountable::canWieldItems, d, bool);
	}
};

class BaseEntity {
public:
	DWORD64 boneTransforms( ) {
		return safe_read((const uintptr_t)this + O::Model::boneTransforms, DWORD64);
	}
};

class EntCount {
public:
	int count( ) {
		return safe_read((const uintptr_t)this + 0x10, int);
	}
	DWORD64 buffer( ) {
		return safe_read((const uintptr_t)this + 0x18, DWORD64);
	}
};

class ListDictionary
{
public:
	char pad_0000[0x20];
	class BufferList* keys;
	class BufferList* vals;
	EntCount* ClientEntities_values( ) {
		return (EntCount*)safe_read((const uintptr_t)this + 0x28, UINT64);
	}
	UINT64 Entities_values( ) {
		return safe_read((const uintptr_t)this + 0x28, UINT64);
	}
};

class EntityRealm {
public:
	ListDictionary* entityList( ) {
		return (ListDictionary*)safe_read((const uintptr_t)this + 0x10, UINT64);
	}
};

class BaseNetworkable {
public:

	static EntityRealm* clientEntities( ) {
		auto bn = safe_read(game_assembly_base_adress + 53412336, UINT64);
		return (EntityRealm*)safe_read(bn + 0xb8, UINT64);
	}

};

class Graphics {
public:
	void fov(float d) {
		safe_write((const uintptr_t)this + 0x18, d, float);
	}
};

class Admin {
public:
	void admintime(float d) {
		safe_write((const uintptr_t)this + 0x0, d, float);
	}
};

class Client {
public:
	void camlerp(float d) {
		safe_write((const uintptr_t)this + O::ConVar_Client::camlerp, d, float);
	}
	void camspeed(float d) {
		safe_write((const uintptr_t)this + O::ConVar_Client::camspeed, d, float);
	}
};

class ConsoleSystem {
public:

};

class ConVars {
public:
	static Graphics* convar_graphics( ) {
		DWORD64 convar = safe_read(game_assembly_base_adress + 53403368, DWORD64);
		return (Graphics*)safe_read(convar + 0xb8, DWORD64);
	}
	static Admin* convar_admin() {
		DWORD64 convar = safe_read(game_assembly_base_adress + 53386968, DWORD64);
		return(Admin*)safe_read(convar + 0xb8, DWORD64);
	}
	static Client* convar_client( ) {
		DWORD64 convar = safe_read(game_assembly_base_adress + 53408344, DWORD64);
		return(Client*)safe_read(convar + 0xb8, DWORD64);
	}
	static ConsoleSystem* convar_console( ) {
		DWORD64 convar = safe_read(game_assembly_base_adress + 53514512, DWORD64);
		return (ConsoleSystem*)safe_read(convar + 0xb8, DWORD64);
	}
};

class baseplayer {
public:

	float get_health( ) {
		return safe_read((const uintptr_t)this + O::BaseCombatEntity::_health, float);
	}
	MOV* movement( ) {
		return (MOV*)safe_read((const uintptr_t)this + O::BasePlayer::movement, DWORD64);
	}
	playermodel* ply_model( ) {
		return (playermodel*)safe_read((const uintptr_t)this + O::BasePlayer::playerModel, DWORD64);
	}
	BaseEntity* get_model( ) {
		return (BaseEntity*)safe_read((const uintptr_t)this + O::BaseEntity::model, DWORD64);
	}
	bool playerflags(int Flg) {
		return (safe_read((const uintptr_t)this + O::BasePlayer::playerFlags, int) & Flg);
	}
	bool entityflags(int Flg) {
		return (safe_read((const uintptr_t)this + O::BaseEntity::flags, int) & Flg);
	}
	playereyes* eyes( ) {
		return (playereyes*)safe_read((const uintptr_t)this + O::BasePlayer::eyes, DWORD64);
	}
	std::string getplayername( ) {
		wchar_t wBuffer[0x100]{};
		uint64_t shorts = safe_read((const uintptr_t)this + O::BasePlayer::_displayName, uint64_t);
		std::string name = readstring(shorts);
		return name;
	}
	float clientTickInterval( ) {
		return safe_read((const uintptr_t)this + O::BasePlayer::clientTickInterval, float);
	}
	void clientTickInterval(float d) {
		safe_write((const uintptr_t)this + O::BasePlayer::clientTickInterval, d, float);
	}

	DWORD64 userid( ) {
		return safe_read((const uintptr_t)this + O::BasePlayer::userID, DWORD64);
	}

	playerinput* input( ) {
		return (playerinput*)safe_read((const uintptr_t)this + O::BasePlayer::input, DWORD64);
	}

	playerinventory* inventory( ) {
		return (playerinventory*)safe_read((const uintptr_t)this + O::BasePlayer::inventory, DWORD64);
	}

	baseprojectile* weaponinfo(int i) {
		DWORD64 Items = safe_read(inventory( )->containerBelt( )->itemList( ) + 0x10, DWORD64);
		return (baseprojectile*)safe_read(Items + 0x20 + (i * 0x8), DWORD64);
	}

	baseprojectile* GetActiveWeapon( )
	{
		int act_w_uid = safe_read((const uintptr_t)this + O::BasePlayer::clActiveItem, int);
		if (!act_w_uid) return nullptr;
		baseprojectile* act_w;
		for (int i = 0; i < 6; i++)
			if (act_w_uid == (act_w = weaponinfo(i))->get_uid( )) {
				return act_w;
			}
		return nullptr;
	}
	bool Has_modelstate_flags(int Flg) {
		return (safe_read((const uintptr_t)modelstate( ) + O::ModelState::flags, int) & Flg);
	}
	void modelflag(int flag) {
		int flags = safe_read((const uintptr_t)modelstate( ) + O::ModelState::flags, int);
		safe_write((const uintptr_t)modelstate( )+ O::ModelState::flags, flags |= flag, int);
	}

	static EntityRealm* BasePlayer( ) {
		auto bs = safe_read(game_assembly_base_adress + 53415224, UINT64);
		return (EntityRealm*)safe_read(bs + 0xb8, UINT64);
	}

	std::string getitemname( )
	{
		uint64_t info = safe_read((const uintptr_t)this->GetActiveWeapon( ) + 0x20, uint64_t);

		uint64_t display_name = Read<uint64_t>(info + 0x20);

		std::string wide_name = readstring(display_name);

		if (!wide_name.empty( ))
			return std::string(wide_name.begin( ), wide_name.end( )).c_str();
		return XorStr("No Item");
	}

	ModelState* modelstate( ) {
		return (ModelState*)safe_read((const uintptr_t)this + O::BasePlayer::modelState, DWORD64);
	}

	BaseMountable* mounted( ) {
		return (BaseMountable*)safe_read((const uintptr_t)this + O::BasePlayer::mounted, DWORD64);
	}
	
	struct TransformAccessReadOnly
	{
		uint64_t pTransformData;
	};

	struct TransformData
	{
		uint64_t pTransformArray;
		uint64_t pTransformIndices;
	};

	struct Matrix34
	{
		Vector4 vec0;
		Vector4 vec1;
		Vector4 vec2;
	};

	Vector3 GetBone(ULONG_PTR pTransform)
	{
		__m128 result;

		const __m128 mulVec0 = { -2.000, 2.000, -2.000, 0.000 };
		const __m128 mulVec1 = { 2.000, -2.000, -2.000, 0.000 };
		const __m128 mulVec2 = { -2.000, -2.000, 2.000, 0.000 };

		TransformAccessReadOnly pTransformAccessReadOnly = safe_read(pTransform + 0x38, TransformAccessReadOnly);
		unsigned int index = safe_read(pTransform + 0x40, unsigned int);
		TransformData transformData = safe_read(pTransformAccessReadOnly.pTransformData + 0x18, TransformData);

		if (transformData.pTransformArray && transformData.pTransformIndices)
		{
			result = safe_read(transformData.pTransformArray + 0x30 * index, __m128);
			int transformIndex = safe_read(transformData.pTransformIndices + 0x4 * index, int);
			int pSafe = 0;
			while (transformIndex >= 0 && pSafe++ < 200)
			{
				Matrix34 matrix34 = safe_read(transformData.pTransformArray + 0x30 * transformIndex, Matrix34);

				__m128 xxxx = _mm_castsi128_ps(_mm_shuffle_epi32(*(__m128i*)(&matrix34.vec1), 0x00));	// xxxx
				__m128 yyyy = _mm_castsi128_ps(_mm_shuffle_epi32(*(__m128i*)(&matrix34.vec1), 0x55));	// yyyy
				__m128 zwxy = _mm_castsi128_ps(_mm_shuffle_epi32(*(__m128i*)(&matrix34.vec1), 0x8E));	// zwxy
				__m128 wzyw = _mm_castsi128_ps(_mm_shuffle_epi32(*(__m128i*)(&matrix34.vec1), 0xDB));	// wzyw
				__m128 zzzz = _mm_castsi128_ps(_mm_shuffle_epi32(*(__m128i*)(&matrix34.vec1), 0xAA));	// zzzz
				__m128 yxwy = _mm_castsi128_ps(_mm_shuffle_epi32(*(__m128i*)(&matrix34.vec1), 0x71));	// yxwy
				__m128 tmp7 = _mm_mul_ps(*(__m128*)(&matrix34.vec2), result);

				result = _mm_add_ps(
					_mm_add_ps(
						_mm_add_ps(
							_mm_mul_ps(
								_mm_sub_ps(
									_mm_mul_ps(_mm_mul_ps(xxxx, mulVec1), zwxy),
									_mm_mul_ps(_mm_mul_ps(yyyy, mulVec2), wzyw)),
								_mm_castsi128_ps(_mm_shuffle_epi32(_mm_castps_si128(tmp7), 0xAA))),
							_mm_mul_ps(
								_mm_sub_ps(
									_mm_mul_ps(_mm_mul_ps(zzzz, mulVec2), wzyw),
									_mm_mul_ps(_mm_mul_ps(xxxx, mulVec0), yxwy)),
								_mm_castsi128_ps(_mm_shuffle_epi32(_mm_castps_si128(tmp7), 0x55)))),
						_mm_add_ps(
							_mm_mul_ps(
								_mm_sub_ps(
									_mm_mul_ps(_mm_mul_ps(yyyy, mulVec0), yxwy),
									_mm_mul_ps(_mm_mul_ps(zzzz, mulVec1), zwxy)),
								_mm_castsi128_ps(_mm_shuffle_epi32(_mm_castps_si128(tmp7), 0x00))),
							tmp7)), *(__m128*)(&matrix34.vec0));

				transformIndex = safe_read(transformData.pTransformIndices + 0x4 * transformIndex, int);
			}
		}

		return Vector3(result.m128_f32[0], result.m128_f32[1], result.m128_f32[2]);
	}
	Vector3 GetTransform(int i)
	{
		uintptr_t BoneValue = safe_read(get_model( )->boneTransforms( ) + 0x20 + i * 0x8, uintptr_t);
		uintptr_t bone = safe_read(BoneValue + 0x10, uintptr_t);
		return GetBone(bone);
	}
};

class Ploco {
public:

	baseplayer* player = nullptr;
	UINT64 TodCycle = 0;
	UINT64 atmosphere = 0;

	Matrix4x4* pViewMatrix = nullptr;
	bool WorldToScreen(const Vector3& EntityPos, Vector2& ScreenPos)
	{
		if (!pViewMatrix) return false;
		Vector3 TransVec = Vector3(safe_read((ULONG64)&pViewMatrix->_14, float), safe_read((ULONG64)&pViewMatrix->_24, float), safe_read((ULONG64)&pViewMatrix->_34, float));
		Vector3 RightVec = Vector3(safe_read((ULONG64)&pViewMatrix->_11, float), safe_read((ULONG64)&pViewMatrix->_21, float), safe_read((ULONG64)&pViewMatrix->_31, float));
		Vector3 UpVec = Vector3(safe_read((ULONG64)&pViewMatrix->_12, float), safe_read((ULONG64)&pViewMatrix->_22, float), safe_read((ULONG64)&pViewMatrix->_32, float));
		float w = Math::Dot(TransVec, EntityPos) + safe_read((ULONG64)&pViewMatrix->_44, float);
		if (w < 0.098f) return false;
		float y = Math::Dot(UpVec, EntityPos) + safe_read((ULONG64)&pViewMatrix->_42, float);
		float x = Math::Dot(RightVec, EntityPos) + safe_read((ULONG64)&pViewMatrix->_41, float);

		ScreenPos = Vector2((screen::Width / 2) * (1.f + x / w), (screen::Height / 2) * (1.f - y / w));
		return true;
	}
};
Ploco loco;

void projectile_functions() {
	if (misc::fatbullet) {
		auto list = loco.player->GetActiveWeapon( )->heldEntity( )->createdProjectiles( );
		list = safe_read(list + 0x10, DWORD64);
		for (int i = 0; i < 8; i++) {
			UINT64 Item = safe_read(list + 0x20 + (i * 0x8), UINT64);
			safe_write(Item + 0x2C, 1.5f, float);
		}
	}
	else if (!misc::fatbullet) {}

	if (misc::fastbullet) {
		Weapon target = loco.player->GetActiveWeapon( )->Info( );
		auto bpr = loco.player->GetActiveWeapon( )->heldEntity( );
		if (misc::fastbullet) {
			if (target.id == -75944661) { //eoka
				bpr->projectileVelocityScale(1.48f);
				aim::velocity == 1.48f;
			}
			if (target.id == 1545779598) { //ak
				bpr->projectileVelocityScale(1.48f);
				aim::velocity == 1.48f;
			}
			if (target.id == 1796682209) { //smg
				bpr->projectileVelocityScale(1.f);
				aim::velocity == 1.f;
			}
			if (target.id == 1318558775) { //mp5
				bpr->projectileVelocityScale(1.1f);
				aim::velocity == 1.1f;
			}
			if (target.id == -1758372725) { //thompson
				bpr->projectileVelocityScale(1.48f);
				aim::velocity == 1.48f;
			}
			if (target.id == -2069578888) { //m249
				bpr->projectileVelocityScale(1.48f);
				aim::velocity == 1.48f;
			}
			if (target.id == -1812555177) { //lr300
				bpr->projectileVelocityScale(1.48f);
				aim::velocity == 1.48f;
			}
			if (target.id == 1588298435) { //bolt
				bpr->projectileVelocityScale(1.48f);
				aim::velocity == 1.48f;
			}
			if (target.id == -778367295) { //l96
				bpr->projectileVelocityScale(1.48f);
				aim::velocity == 1.48f;
			}
			if (target.id == 1443579727) { //bow
				bpr->projectileVelocityScale(1.48f);
				aim::velocity == 1.48f;
			}
			if (target.id == 1965232394) { //crossbow
				bpr->projectileVelocityScale(1.48f);
				aim::velocity == 1.48f;
			}
			if (target.id == 884424049) { //comp
				bpr->projectileVelocityScale(1.48f);
				aim::velocity == 1.48f;
			}
			if (target.id == 1953903201) { //nailgun
				bpr->projectileVelocityScale(1.48f);
				aim::velocity == 1.48f;
			}
			if (target.id == -765183617) { //double shotgun
				bpr->projectileVelocityScale(1.48f);
				aim::velocity == 1.48f;
			}
			if (target.id == 795371088) { //pump shotgun
				bpr->projectileVelocityScale(1.48f);
				aim::velocity == 1.48f;
			}
			if (target.id == -41440462) { //spas shotgun
				bpr->projectileVelocityScale(1.48f);
				aim::velocity == 1.48f;
			}
			if (target.id == -1367281941) { //water shotgun
				bpr->projectileVelocityScale(1.48f);
				aim::velocity == 1.48f;
			}
			if (target.id == -904863145) { //semi rifle
				bpr->projectileVelocityScale(1.48f);
				aim::velocity == 1.48f;
			}
			if (target.id == 818877484) { //semi pistol
				bpr->projectileVelocityScale(1.48f);
				aim::velocity == 1.48f;
			}
			if (target.id == -852563019) { //m92
				bpr->projectileVelocityScale(1.48f);
				aim::velocity == 1.48f;
			}
			if (target.id == 28201841) { //m39
				bpr->projectileVelocityScale(1.48f);
				aim::velocity == 1.48f;
			}
			if (target.id == 649912614) { //revolver
				bpr->projectileVelocityScale(1.48f);
				aim::velocity == 1.48f;
			}
			if (target.id == 1373971859) { //python
				bpr->projectileVelocityScale(1.48f);
				aim::velocity == 1.48f;
			}
			if (target.id == -1517740219) { //speargun
				bpr->projectileVelocityScale(1.48f);
				aim::velocity == 1.48f;
			}
		}
		else
		{
			bpr->projectileVelocityScale(0.75f);
			aim::velocity == 0.75f;
		}
	}
}

bool visiblecheck(baseplayer* a1, baseplayer* a2) { // better 
	return a1->ply_model( )->visible( ), a2->ply_model( )->visible( ) && a2->ply_model( )->visible( ), a1->ply_model( )->visible( );
}

void chams(baseplayer* ply) {
	auto models = ply->ply_model( )->FemaleSkin( ) && ply->ply_model( )->MaleSkin( );

	if (player::chams) {
		if (ply->ply_model( )) {
			if (models) {
				


			}
		}
	}else if (!player::chams){}
}

void localplayer_functions( ) {

	if (misc::fakeadmin) {
		loco.player->playerflags(PlayerFlags::IsAdmin);
	}

	if (misc::omnisprint) {
		loco.player->modelflag(0x10);
		loco.player->movement( )->Running(1.f);
		float speed = (loco.player->movement( )->swimming( ) || loco.player->movement( )->Duckingk__BackingField( ) > 0.5f) ? 1.7f : (loco.player->movement( )->jumping( ) ? 8.f : 5.5f);
		Vector3 vel = loco.player->movement( )->TargetMovement( );
		speed = max(speed, vel.Length( ));
		if (loco.player->ply_model( )->wasCrawling( )) {}
		else {
			float len = vel.Length( );
			if (len > 0.f) {
				vel = Vector3(vel.x / len * speed, vel.y, vel.z / len * speed);
				loco.player->movement( )->TargetMovement(vel);
			}
		}
	}

	if (misc::inifinityjump) {
		if (GetAsyncKeyState(VK_SPACE)) {
			loco.player->movement( )->vector_groundAngleNew(Vector3(0, 100000, 0));
			loco.player->movement( )->vector_groundAngle(Vector3(99999, 99999, 99999));
		}
	}

	ConVars::convar_admin( )->admintime(misc::time);

	ConVars::convar_client( )->camlerp(1.f);
	ConVars::convar_client( )->camspeed(1.f);

	if (GetAsyncKeyState(VK_CAPITAL) && misc::zoom) {
		ConVars::convar_graphics( )->fov(12.f);
	}
	else {
		ConVars::convar_graphics( )->fov(misc::Fov);
	}

	if (misc::shootanywhere) {
		loco.player->modelflag(4);
		loco.player->movement( )->grounded(1.f);
	}

	if (misc::spiderman) {
		loco.player->movement( )->groundAngle(0.f);
		loco.player->movement( )->groundAngleNew(0.f);
	}

	if (GetAsyncKeyState(0x58) && misc::longneck) {
		loco.player->eyes( )->viewoffset(Vector3(0, 5, 0));
	}

	if (GetAsyncKeyState(0x58) && misc::longneck) {
		loco.player->clientTickInterval(1.f);
	}
	else { loco.player->clientTickInterval(0.05f); }

	if (misc::canWieldItems) {
		if (loco.player->mounted( )) {
			loco.player->mounted( )->canWieldItems(true);
		}
		else if (!loco.player->mounted( )){}
	}

	if (misc::autosprint) {
		loco.player->movement( )->sprintForced(true);
	}else if (!misc::autosprint){}	

	//shit method pls change, using a classes;
	auto weapon = loco.player->GetActiveWeapon( );
	auto held = weapon->heldEntity( );
	if (weapon == nullptr) return;
	Weapon target = weapon->Info( );
	if (!target.id) return;
	if (!target.category) return;

	if (target.category == 1) { //-3 - hammer, -2 - bows, -1 - eoka, 0-nopatch, 1 - meele, 2 - semiautomatic, 3 - automatic 4 - speargun

		return;
	}
	if (target.category == -2) {
		if (misc::fastbow) {
			held->attackready(true);
		}else if (!misc::fastbow){}
		projectile_functions( );
		if (misc::norecoil) {
			held->recoil( )->recoilYawMin(Vector2( ));
			held->recoil( )->recoilYawMax(Vector2( ));
			held->recoil( )->recoilPitchMin(Vector2( ));
			held->recoil( )->recoilPitchMax(Vector2( ));
			held->recoil( )->ADSScale(Vector2( ));
			held->recoil( )->movementPenalty(Vector2( ));
		}
		else if (!misc::norecoil) {}
		if (misc::nospread) {
			held->StancePenalty(0.f);
			held->AimconePenalty(0.f);
			held->AimCone(0.f);
			held->HipAimCone(0.f);
			held->AimconePenaltyPerShot(0.f);
		}
		else if (!misc::nospread) {}
		return;
	}
	if (misc::fastshots) {
		held->repeatDelay(0.09f);
	}else if (!misc::fastshots){}
	projectile_functions( );
	if (misc::norecoil) {
		held->recoil( )->recoilYawMin(Vector2( ));
		held->recoil( )->recoilYawMax(Vector2( ));
		held->recoil( )->recoilPitchMin(Vector2( ));
		held->recoil( )->recoilPitchMax(Vector2( ));
		held->recoil( )->ADSScale(Vector2( ));
		held->recoil( )->movementPenalty(Vector2( ));
	}else if (!misc::norecoil){}
	if (misc::nospread) {
		held->StancePenalty(0.f);
		held->AimconePenalty(0.f);
		held->AimCone(0.f);
		held->HipAimCone(0.f);
		held->AimconePenaltyPerShot(0.f);
	}
	else if (!misc::nospread) {}
	if (target.category == 2) {
		if (misc::automatic) {
			held->automatic(true);
		}else if (!misc::automatic){}
		if (misc::fastshots) {
			held->repeatDelay(0.09f);
		}else if (!misc::fastshots){}
		projectile_functions( );
		if (misc::norecoil) {
			held->recoil( )->recoilYawMin(Vector2( ));
			held->recoil( )->recoilYawMax(Vector2( ));
			held->recoil( )->recoilPitchMin(Vector2( ));
			held->recoil( )->recoilPitchMax(Vector2( ));
			held->recoil( )->ADSScale(Vector2( ));
			held->recoil( )->movementPenalty(Vector2( ));
		}
		else if (!misc::norecoil) {}
		if (misc::nospread) {
			held->StancePenalty(0.f);
			held->AimconePenalty(0.f);
			held->AimCone(0.f);
			held->HipAimCone(0.f);
			held->AimconePenaltyPerShot(0.f);
		}
		else if (!misc::nospread) {}
	}
	else if (target.category == -1) {
		if (misc::nospread) {
			held->StancePenalty(0.f);
			held->AimconePenalty(0.f);
			held->AimCone(0.f);
			held->HipAimCone(0.f);
			held->AimconePenaltyPerShot(0.f);
		}
		else if (!misc::nospread) {}
		projectile_functions( );
	}
}

namespace draw {
	std::array<int, 20> valid_bones = {
		1, 2, 3, 5, 6, 14, 15, 17, 18, 21, 23, 24, 25, 26, 27, 48, 55, 56, 57, 76
	};
	struct box_bounds {
		float left, right, top, bottom;

		bool empty( ) {
			if (this->left == 0 && this->right == 0 && this->top == 0 && this->bottom == 0)
				return true;

			if (this->left == FLT_MAX || this->right == FLT_MIN || this->top == FLT_MAX || this->bottom == FLT_MIN)
				return true;

			return false;
		}
		static box_bounds null( ) {
			return { 0, 0, 0, 0 };
		}
	};
	box_bounds get_bounds(baseplayer* ply, float expand = 0.f) {
		box_bounds bounds = { FLT_MAX, FLT_MIN, FLT_MAX, FLT_MIN };

		for (auto j : valid_bones) {
			Vector3 bone = ply->GetTransform(j);
			Vector2 sc;
			if (loco.WorldToScreen(bone, sc)) {
				Vector2 bone_screen = sc;
				if (bone_screen.x < bounds.left)
					bounds.left = bone_screen.x;
				if (bone_screen.x > bounds.right)
					bounds.right = bone_screen.x;
				if (bone_screen.y < bounds.top)
					bounds.top = bone_screen.y;
				if (bone_screen.y > bounds.bottom)
					bounds.bottom = bone_screen.y;
			}
		}

		if (bounds.left == FLT_MAX)
			return box_bounds::null( );
		if (bounds.right == FLT_MIN)
			return box_bounds::null( );
		if (bounds.top == FLT_MAX)
			return box_bounds::null( );
		if (bounds.bottom == FLT_MIN)
			return box_bounds::null( );

		bounds.left -= expand;
		bounds.right += expand;
		bounds.top -= expand;
		bounds.bottom += expand;

		return bounds;
	};
	void players(baseplayer* ply) {
		box_bounds bounds = get_bounds(ply, 2.f);
		if (!bounds.empty( )) {
			float box_width = bounds.right - bounds.left;
			float box_height = bounds.bottom - bounds.top;
			Vector2 footPos = { bounds.left + (box_width / 2), bounds.bottom + 7.47f };
			Vector2 headPos = { bounds.left + (box_width / 2), bounds.top - 9.54f };
			if (player::box && !ply->ply_model( )->isnpc( )) {
				ImGui::GetOverlayDrawList( )->AddLine({ bounds.left, bounds.top }, { bounds.left + (box_width / 4.5f), bounds.top }, IM_COL32(255, 255, 255, 255), 1.f);
				ImGui::GetOverlayDrawList( )->AddLine({ bounds.right, bounds.top }, { bounds.right - (box_width / 4.5f), bounds.top }, IM_COL32(255, 255, 255, 255), 1.f);

				ImGui::GetOverlayDrawList( )->AddLine({ bounds.left, bounds.bottom }, { bounds.left + (box_width / 4.5f), bounds.bottom }, IM_COL32(255, 255, 255, 255), 1.f);
				ImGui::GetOverlayDrawList( )->AddLine({ bounds.right, bounds.bottom }, { bounds.right - (box_width / 4.5f), bounds.bottom }, IM_COL32(255, 255, 255, 255), 1.f);

				ImGui::GetOverlayDrawList( )->AddLine({ bounds.left, bounds.top }, { bounds.left, bounds.top + (box_width / 4.5f) }, IM_COL32(255, 255, 255, 255), 1.f);
				ImGui::GetOverlayDrawList( )->AddLine({ bounds.right, bounds.top }, { bounds.right, bounds.top + (box_width / 4.5f) }, IM_COL32(255, 255, 255, 255), 1.f);

				ImGui::GetOverlayDrawList( )->AddLine({ bounds.left, bounds.bottom }, { bounds.left, bounds.bottom - (box_width / 4.5f) }, IM_COL32(255, 255, 255, 255), 1.f);
				ImGui::GetOverlayDrawList( )->AddLine({ bounds.right, bounds.bottom }, { bounds.right, bounds.bottom - (box_width / 4.5f) }, IM_COL32(255, 255, 255, 255), 1.f);
			}
			if (player::name && !ply->ply_model( )->isnpc( )) {
				DrawOutlinedText(m_pFont, ply->getplayername( ), ImVec2(bounds.left + (box_width / 2), bounds.bottom + 8.f), 10.f, IM_COL32(255, 255, 255, 255), true);
			}
			int health = (int)ply->get_health( );
			float maxhealth = 100.f;
			if (player::health && !ply->ply_model( )->isnpc( )) {
				filled_rect2(ImVec2{ headPos.x - 15.f , headPos.y }, ImVec2{ 30, 5 }, ImColor(0, 0, 0, 255), false);
				if ((int)ply->get_health( ) <= 33)
				{
					filled_rect2(ImVec2{ headPos.x - 15.f , headPos.y }, ImVec2{ 30 * (health / maxhealth), 5 }, ImColor(255, 0, 0, 255), false);
				}
				if ((int)ply->get_health( ) >= 34 && (int)ply->get_health() <= 66)
				{
					filled_rect2(ImVec2{ headPos.x - 15.f , headPos.y }, ImVec2{ 30 * (health / maxhealth), 5 }, ImColor(255, 202, 0, 255), false);
				}
				if ((int)ply->get_health( ) >= 67)
				{
					filled_rect2(ImVec2{ headPos.x - 15.f , headPos.y }, ImVec2{ 30 * (health / maxhealth), 5 }, ImColor(0, 255, 0, 255), false);
				}
				DrawOutlinedText(m_pFont, (std::to_string(health)), ImVec2((headPos.x - 15.f) + (30 * (health / maxhealth)), headPos.y), 10.f, ImColor(255, 255, 255, 255), true);
			}
			int dist = (int)Math::Calc3D_Dist(loco.player->GetTransform(head), ply->GetTransform(head));
			if (player::dist && !ply->ply_model( )->isnpc( )) {
				DrawOutlinedText(m_pFont, (std::to_string(dist)), ImVec2(bounds.left + (box_width / 2), bounds.bottom + 22.f), 10.f, IM_COL32(255, 255, 255, 255), true);
			}
			if (player::showweapon && !ply->ply_model( )->isnpc( )) {
				DrawOutlinedText(m_pFont, ply->getitemname( ), ImVec2(bounds.left + (box_width / 2), bounds.bottom + 15.f), 10.f, IM_COL32(255, 255, 255, 255), true);
			}
		}
	}
}


float getfov(baseplayer* Entity) {
	Vector2 ScreenPos;
	if (!loco.WorldToScreen(Entity->GetTransform(head), ScreenPos)) return 1000.f;
	return Math::Calc2D_Dist(Vector2(screen::Width / 2, screen::Height / 2), ScreenPos);
}

baseplayer* find_target( ) {

		
	static UINT64 oPlayerList = 0;
	if (!oPlayerList) {
		oPlayerList = baseplayer::BasePlayer( )->entityList( )->Entities_values( );
	}

	int EntityCount = safe_read(oPlayerList + 0x10, int);
	UINT64 EntityBuffer = safe_read(oPlayerList + 0x18, UINT64);

	for (int i = 0; i < EntityCount; i++)
	{
		baseplayer* Player = (baseplayer*)safe_read(EntityBuffer + 0x20 + (i * 0x8), UINT64);
		if (!Player || Player == loco.player || Player->ply_model( )->isnpc( ) || Player->playerflags(PlayerFlags::Sleeping) || Player->get_health( ) < 0.08) {
			continue;
		}
		if (getfov(Player) > 120.f)
		continue;
		return Player;
	}
		
	return nullptr;
}

baseplayer* find_players( ) {


	static UINT64 oPlayerList = 0;
	if (!oPlayerList) {
		oPlayerList = baseplayer::BasePlayer( )->entityList( )->Entities_values( );
	}

	int EntityCount = safe_read(oPlayerList + 0x10, int);
	UINT64 EntityBuffer = safe_read(oPlayerList + 0x18, UINT64);

	for (int i = 0; i < EntityCount; i++)
	{
		baseplayer* Player = (baseplayer*)safe_read(EntityBuffer + 0x20 + (i * 0x8), UINT64);
		if (!Player || Player == loco.player || Player->ply_model( )->isnpc( ) || Player->playerflags(PlayerFlags::Sleeping) || Player->get_health( ) < 0.08) {
			continue;
		}
		draw::players(Player);
		continue;
		return Player;
	}

	return nullptr;
}

void find_bn( ) {
	bool func = false;
	if (!BaseNetworkable::clientEntities( )->entityList( )->ClientEntities_values( )) return;
	for (int i = 0; i <= BaseNetworkable::clientEntities( )->entityList( )->ClientEntities_values( )->count( ); i++) {
		auto entities_ = safe_read(BaseNetworkable::clientEntities( )->entityList( )->ClientEntities_values( )->buffer( ) + 0x20 + (i * 0x8), DWORD64);
		auto baseObject = safe_read(entities_ + 0x10, DWORD64);
		auto object = safe_read(baseObject + 0x30, DWORD64);
		auto tag = safe_read(object + 0x54, WORD);
		auto prefabName = safe_read(object + 0x60, uint64_t);
	}
}

void find_loco( ) {
	long long i = 0;
	bool isvalid_loco = false;
	process_id = get_process_id(XorStr("RustClient.exe").c_str( ));
	game_assembly_base_adress = get_module_base_address(xorstr("GameAssembly.dll"));
	unity_player_base_adress = get_module_base_address(xorstr("UnityPlayer.dll"));
	UINT64  ObjMgr = safe_read(unity_player_base_adress + 0x17C1F18, UINT64);
	UINT64  Obj = safe_read(ObjMgr + 0x8, UINT64);

	for (UINT64 Obj = safe_read(ObjMgr + 0x8, UINT64); (Obj && (Obj != safe_read(ObjMgr, UINT64))); Obj = safe_read(Obj + 0x8, UINT64))
	{
		UINT64 GameObject = safe_read(Obj + 0x10, UINT64);
		WORD Tag = safe_read(GameObject + 0x54, WORD);

		if (Tag == 6 || Tag == 5 || Tag == 20011)
		{
			UINT64 ObjClass = safe_read(GameObject + 0x30, UINT64);
			UINT64 Entity = safe_read(ObjClass + 0x18, UINT64);
			if (Tag == 6)
			{
				baseplayer* ply = (baseplayer*)safe_read(Entity + 0x28, UINT64);
				if (safe_read(safe_read(GameObject + 0x60, UINT64), UINT64) == 0x616C506C61636F4C)
				{
					isvalid_loco = true;
					loco.player = ply;
					i = Obj;
					if (loco.TodCycle && loco.pViewMatrix)
						return;
				}
			}
			else if (Tag == 5)
			{
				UINT64 ObjClass = safe_read(GameObject + 0x30, UINT64);
				UINT64 Entity = safe_read(ObjClass + 0x18, UINT64);
				loco.pViewMatrix = (Matrix4x4*)(Entity + 0x2E4);
			}
			else if (Tag == 20011)
			{
				UINT64 ObjClass = safe_read(GameObject + 0x30, UINT64);
				UINT64 Entity = safe_read(ObjClass + 0x18, UINT64);
				UINT64 Dome = safe_read(Entity + 0x28, UINT64);
				loco.TodCycle = safe_read(Dome + 0x38, UINT64);
				loco.atmosphere = safe_read(Dome + 0x48, UINT64);

			}
		}
	}
	SleepEx(2, true);
}