
namespace screen {
	int Width = GetSystemMetrics(SM_CXSCREEN);
	int Height = GetSystemMetrics(SM_CYSCREEN);
}

namespace aim {
	bool enablesmooth = true;
	float smooth = 1.f;
	bool aimbot = false;
	bool silentaim = false;
	float velocity = 1.48f;
}

namespace player {
	bool box = false;
	bool name = false;
	bool health = false;
	bool dist = false;
	bool showweapon = false;
	bool chams = false;
	bool showeyeview = false;
}

namespace misc {
	bool fakeadmin = false;
	bool spiderman = false;
	bool longneck = false;
	bool automatic = false;
	float Fov = 90.f;
	bool zoom = false;
	bool nospread = false;
	bool norecoil = false;
	bool fastshots = false;
	bool fastbow = false;
	bool inifinityjump = false;
	bool canWieldItems = false;
	bool fatbullet = false;
	bool fastbullet = false;
	bool autosprint = false;
	bool shootanywhere = false;
	bool omnisprint = false;
	float time = 12.f;
}
