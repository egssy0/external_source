float GetBulletSpeedPS(Weapon tar, int ammo)
{
	if (ammo == 0) return tar.ammo[0].speed;
	for (Ammo am : tar.ammo) {
		for (int id : am.id) {
			if (id == ammo) {
				return am.speed;
			}
		}
		if (am.id[0] == 0) return am.speed;
	}
	return 250.f;
}

float GetGravityPS(int ammoid) {
	switch (ammoid) {
	case 14241751:
		return 1.f;
	case -1234735557:
		return 0.75f;
	case 215754713:
		return 0.75f;
	case -1023065463:
		return 0.5f;
	case -2097376851:
		return 0.75f;
	case -1321651331:
		return 1.25f;
	default:
		return 1.f;
	}
}

Vector3 PredictionPS(Vector3 LP_Pos, baseplayer* ply, BoneList Bone)
{
	Vector3 BonePos;
	BonePos = ply->GetTransform(head);
	auto active = loco.player->GetActiveWeapon( );
	Weapon tar = active->Info();
	int ammo = active->LoadedAmmo( );
	if (misc::longneck) {
		if (GetAsyncKeyState(0x58)) {
			BonePos = ply->GetTransform(head) - Vector3(0, 4.2f, 0);
		}
		else {
			BonePos = ply->GetTransform(head);
		}
	}
	float dist = Math::Calc3D_Dist(LP_Pos, BonePos);
	if (dist > 0.001f) {
		float speed = GetBulletSpeedPS(tar, ammo) * aim::velocity;
		if (!speed) speed = 250.f;
		float BulletTime = dist / speed;
		Vector3 vel = ply->ply_model( )->newVelocity( );
		Vector3 PredictVel = vel * BulletTime * 0.75f;
		BonePos += PredictVel;
		float gravity = GetGravityPS(ammo);
		BonePos.y += (4.905f * BulletTime * BulletTime) * gravity;
	}
	return BonePos;
}

void Normalize(float& Yaw, float& Pitch) {
	if (Pitch < -89) Pitch = -89;
	else if (Pitch > 89) Pitch = 89;
	if (Yaw < -360) Yaw += 360;
	else if (Yaw > 360) Yaw -= 360;
}

float Magnitude(Vector3 vector)
{
	return static_cast<float>(std::sqrt(vector.x * vector.x + vector.y * vector.y + vector.z * vector.z));
}

Vector3 monkey_normalize(Vector3 value)
{
	float mag = Magnitude(value);
	if (mag > 0.00001F)
	{
		return Vector3(value.x / mag, value.y / mag, value.z / mag);
	}
	else
	{
		return Vector3(0, 0, 0);
	}
}

Vector3 Cross(Vector3 lhs, Vector3 rhs)
{
	return Vector3(lhs.y * rhs.z - lhs.z * rhs.y, lhs.z * rhs.x - lhs.x * rhs.z, lhs.x * rhs.y - lhs.y * rhs.x);
}

Vector4 QuaternionLookRotation(Vector3 forward, Vector3 up)
{
	monkey_normalize(forward);

	Vector3 vector = monkey_normalize(forward);
	Vector3 vector2 = monkey_normalize(Cross(up, vector));
	Vector3 vector3 = Cross(vector, vector2);
	auto m00 = vector2.x;
	auto m01 = vector2.y;
	auto m02 = vector2.z;
	auto m10 = vector3.x;
	auto m11 = vector3.y;
	auto m12 = vector3.z;
	auto m20 = vector.x;
	auto m21 = vector.y;
	auto m22 = vector.z;


	float num8 = (m00 + m11) + m22;
	auto quaternion = Vector4();
	if (num8 > 0.0f)
	{
		auto num = static_cast<float>(std::sqrt(num8 + 1.0f));
		quaternion.w = num * 0.5f;
		num = 0.5f / num;
		quaternion.x = (m12 - m21) * num;
		quaternion.y = (m20 - m02) * num;
		quaternion.z = (m01 - m10) * num;

		return quaternion;
	}
	if ((m00 >= m11) && (m00 >= m22))
	{
		auto num7 = static_cast<float>(std::sqrt(((1.0f + m00) - m11) - m22));
		auto num4 = 0.5f / num7;
		quaternion.w = 0.5f * num7;
		quaternion.y = (m01 + m10) * num4;
		quaternion.z = (m02 + m20) * num4;
		quaternion.w = (m12 - m21) * num4;

		return quaternion;
	}
	if (m11 > m22)
	{
		auto num6 = static_cast<float>(std::sqrt(((1.0f + m11) - m00) - m22));
		auto num3 = 0.5f / num6;
		quaternion.x = (m10 + m01) * num3;
		quaternion.y = 0.5f * num6;
		quaternion.z = (m21 + m12) * num3;
		quaternion.w = (m20 - m02) * num3;

		return quaternion;
	}
	auto num5 = static_cast<float>(std::sqrt(((1.0f + m22) - m00) - m11));
	auto num2 = 0.5f / num5;
	quaternion.x = (m20 + m02) * num2;
	quaternion.y = (m21 + m12) * num2;
	quaternion.z = 0.5f * num5;
	quaternion.w = (m01 - m10) * num2;

	return quaternion;
}


void newSmoothing(Vector2& Angle, float smooth)
{
	Angle.x /= smooth;
	Angle.y /= smooth;
}

void target(baseplayer* player) {
	Vector3 Local = loco.player->GetTransform(head);
	Vector3 PlayerPos = player->GetTransform(head);
	PlayerPos = PredictionPS(Local, player, BoneList(head));
	Vector2 AngleToAim = Math::CalcAngle(Local, PlayerPos);
	Normalize(AngleToAim.y, AngleToAim.x);
	if (isnan(AngleToAim.x) || isnan(AngleToAim.y))
		return;
	if (aim::enablesmooth) {
		AngleToAim -= Vector2{ loco.player->input( )->bodyangles( ).x, loco.player->input()->bodyangles( ).y };
		newSmoothing(AngleToAim, aim::smooth);
		AngleToAim += Vector2{ loco.player->input( )->bodyangles( ).x, loco.player->input()->bodyangles( ).y };
	}

	loco.player->input( )->bodyangles(AngleToAim);


	Normalize(AngleToAim.y, AngleToAim.x);
	loco.player->input( )->bodyangles(AngleToAim);
}

void silenttarget(baseplayer* player) {
	if (!player) return;
	Vector3 Local = loco.player->GetTransform(head);
	Vector3 enemy_position = PredictionPS(Local, player, BoneList(head));
	Vector4 to_quat = QuaternionLookRotation((enemy_position - Local).Normalized( ), Vector3(0, 1, 0));
	loco.player->eyes( )->bodyrotation(to_quat);
}

DWORD WINAPI LP22(LPVOID lpParameter) {
	while (true) {
		if (aim::silentaim) {
			if (loco.player->GetActiveWeapon( )->heldEntity( )) {
				if (GetAsyncKeyState(VK_LBUTTON) || GetAsyncKeyState(VK_RBUTTON)) {
					silenttarget(find_target( ));
				}
			}
		}
	}
}

void Aim(baseplayer* player)
{
	if (!player) return;

	if (aim::aimbot)
	{
		if (!player->ply_model( )->isnpc( ) && !player->playerflags(PlayerFlags::Sleeping)) {
			if (GetAsyncKeyState(VK_RBUTTON)) {
				target(player);
			}
		}
	}
}