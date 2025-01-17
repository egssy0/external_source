

class Vector
{
public:

	Vector(void) : x(0.0f), y(0.0f), z(0.0f)
	{

	}

	Vector(float X, float Y, float Z)
		: x(X), y(Y), z(Z)
	{

	}

	Vector(float* p)
	{
		*this = p;
	};

	Vector(const Vector& in)
	{
		x = in.x;
		y = in.y;
		z = in.z;
	};

	~Vector()
	{

	}


	/*inline Vector(float XYZ)
		: x(XYZ), y(XYZ), z(XYZ)
	{
	}*/

	inline Vector& operator= (const Vector& in);
	inline Vector& operator= (float* p);
	inline Vector& operator= (float f);

	inline float& operator[] (int i) const;

	inline bool operator! (void) const;

	inline bool operator== (const Vector& other) const;

	inline bool operator!= (const Vector& other) const;

	inline Vector& operator+= (const Vector& other);
	inline Vector& operator+= (float* p);
	inline Vector& operator+= (float f);

	inline Vector& operator-= (const Vector& other);
	inline Vector& operator-= (float* p);
	inline Vector& operator-= (float f);

	inline Vector& operator*= (const Vector& other);
	inline Vector& operator*= (float* p);
	inline Vector& operator*= (float f);

	inline Vector& operator/= (const Vector& other);
	inline Vector& operator/= (float* p);
	inline Vector& operator/= (float f);

	inline Vector operator+ (const Vector& other) const;
	inline Vector operator+ (float* p) const;
	inline Vector operator+ (float f) const;

	inline Vector operator- (const Vector& other) const;
	inline Vector operator- (float* p) const;
	inline Vector operator- (float f) const;
	inline Vector operator- (void) const;

	inline Vector operator* (const Vector& other) const;
	inline Vector operator* (float* p) const;
	inline Vector operator* (float f) const;

	inline Vector operator/ (const Vector& other) const;
	inline Vector operator/ (float* p) const;
	inline Vector operator/ (float f) const;

	operator float* () { return &x; }
	operator const float* () const { return &x; }

	inline bool IsZero(void) const
	{
		return x == 0.0f && y == 0.0f && z == 0.0f;
	}

	inline bool IsZero2D(void)
	{
		return x == 0.0f && y == 0.0f;
	}

	inline Vector& Clear(void)
	{
		x = y = z = 0;

		return *this;
	}

	inline Vector& Init(float X, float Y, float Z)
	{
		x = X;
		y = Y;
		z = Z;

		return *this;
	}

	inline Vector& Init(float* p)
	{
		*this = p;

		return *this;
	}

	inline Vector& Negate(void)
	{
		x = -x;
		y = -y;
		z = -z;

		return *this;
	}

	inline float Dot(const Vector& other)
	{
		return x * other.x + y * other.y + z * other.z;
	}
	inline float Dot2D(const Vector& other)
	{
		return x * other.x + y * other.y;
	}

	inline float Length(void)
	{
		float Length = 0;

		Length = sqrt(LengthSqr());

		return Length;
	}

	inline float Length2D(void)
	{
		float Length = 0;

		Length = sqrt(LengthSqr2D());

		return Length;
	}

	inline float LengthSqr(void)
	{
		return x * x + y * y + z * z;
	}

	inline float LengthSqr2D(void)
	{
		return x * x + y * y;
	}

	inline float Distance(Vector& ToVector)
	{
		return (ToVector - *this).Length();
	}

	inline float Distance2D(Vector& ToVector)
	{
		return (ToVector - *this).Length2D();
	}

	inline float Normalize(void)
	{
		float RecipLength, VectorLength;

		VectorLength = Length();

		if (VectorLength != 0)
		{
			RecipLength = 1 / VectorLength;

			x *= RecipLength;
			y *= RecipLength;
			z *= RecipLength;
		}

		return VectorLength;
	}

	inline Vector Normalized(void)
	{
		float flLen = Length();
		if (flLen == 0) return Vector(0, 0, 1);
		flLen = 1 / flLen;
		return Vector(x * flLen, y * flLen, z * flLen);
	}

	inline float Normalize2D(void)
	{
		float Length = LengthSqr2D();
		float RecipLength;

		if (Length != 0)
		{
			RecipLength = 1 / Length;

			x *= RecipLength;
			y *= RecipLength;
		}

		return Length;
	}

#define IM_PII           3.14159265358979323846f

	inline float AngleBetween(Vector& other)
	{
		other.Normalize();
		Normalize();

		return acos(Dot(other)) * static_cast<float>(180.0 / IM_PII);
	}

	Vector& CrossProduct(const Vector& a, const Vector& b)
	{
		x = (a.y * b.z) - (a.z * b.y);
		y = (a.z * b.x) - (a.x * b.z);
		z = (a.x * b.y) - (a.y * b.x);

		return *this;
	}
	

	void VectorVectors(Vector& Right, Vector& Up)
	{
		Vector tmp;

		if (x == 0 && y == 0)
		{
			Right[0] = 1;
			Right[1] = 0;
			Right[2] = 0;
			Up[0] = -z;
			Up[1] = 0;
			Up[2] = 0;
			return;
		}

		tmp[0] = 0; tmp[1] = 0; tmp[2] = 1.0;
		CrossProduct(tmp, Right);
		Right.Normalize();
		Right.CrossProduct(*this, Up);
		Up.Normalize();
	}

	inline bool IsValid()
	{
		return isfinite(x) && isfinite(y) && isfinite(z);
	}

public:

	float x, y, z;
};
class Vector3
{
public:
	float x, y, z;

	inline Vector3() {
		x = y = z = 0.0f;
	}
	static Vector3 Zero() {
		return Vector3(0.0f, 0.0f, 0.0f);
	}
	Vector3 midPoint(Vector3 v2) { return Vector3((x + v2.x) / 2, (y + v2.y) / 2, (z + v2.z) / 2); }
	inline Vector3(float X, float Y, float Z) {
		x = X; y = Y; z = Z;
	}

	inline float operator[](int i) const {
		return ((float*)this)[i];
	}

	inline Vector3& operator-=(float v) {
		x -= v; y -= v; z -= v; return *this;
	}

	inline Vector3 operator*(float v) const {
		return Vector3(x * v, y * v, z * v);
	}

	inline Vector3 operator/(float v) const
	{
		return Vector3(x / v, y / v, z / v);
	}

	inline Vector3& operator-=(const Vector3& v) {
		x -= v.x; y -= v.y; z -= v.z; return *this;
	}

	inline Vector3& operator+=(const Vector3& v) {
		x += v.x; y += v.y; z += v.z; return *this;
	}

	inline Vector3 operator-(const Vector3& v) const {
		return Vector3(x - v.x, y - v.y, z - v.z);
	}

	inline Vector3 operator+(const Vector3& v) const {
		return Vector3(x + v.x, y + v.y, z + v.z);
	}
	float dot(const Vector3& vector)
	{
		return x * vector.x + y * vector.y + z * vector.z;
	}
	inline float Length() {
		return sqrtf(x * x + y * y + z * z);
	}
	Vector3 normalize() {
		float len = Length();
		return Vector3(x / len, y / len, z / len);
	}
	bool empty() const {
		return x == 0.f && y == 0.f && z == 0.f;
	}	
	float magnitude() {
		return sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
	}
	float MagnitudeXZ(Vector3 v)
	{
		return sqrt(v.x * v.x + v.z * v.z);
	}
	float Magnitude2D(Vector3 v)
	{
		return v.MagnitudeXZ(v);
	}
	float distance(Vector3 input) const {
		return (*this - input).Length();
	}
	float Magnitude() { return sqrt(this->x * this->x + this->y * this->y + this->z * this->z); }
	Vector3 Normalized() { float num = this->Magnitude(); if (num > 9.99999974737875E-06) { return { this->x / num, this->y / num, this->z / num }; } return Vector3(); }
};

class Vector2 {
public:
	float x, y;

	inline Vector2() {
		x = y = 0.0f;
	}

	inline Vector2 operator/(float v) const {
		return Vector2(x / v, y / v);
	}
	inline Vector2(float X, float Y) {
		x = X; y = Y;
	}

	inline Vector2 operator-(const Vector2& v) const {
		return Vector2(x - v.x, y - v.y);
	}
	inline Vector2& operator-=(const Vector2& v) {
		x -= v.x; y -= v.y; return *this;
	}
	inline Vector2 operator+(const Vector2& v) const {
		return Vector2(x + v.x, y + v.y);
	}

	inline Vector2& operator+=(const Vector2& v) {
		x += v.x; y += v.y; return *this;
	}

	inline bool Zero() const {
		return (x > -0.1f && x < 0.1f && y > -0.1f && y < 0.1f);
	}
};

class Vector4
{
public:
	float x;
	float y;
	float z;
	float w;

	Vector4()
	{}

	Vector4(float x, float y, float z, float w)
		: x(x), y(y), z(z), w(w)
	{}

	Vector3 forward()
	{
		Vector3  point = { 0, 0, 1 };
		float num = x * 2;
		float num2 = y * 2;
		float num3 = z * 2;
		float num4 = x * num;
		float num5 = y * num2;
		float num6 = z * num3;
		float num7 = x * num2;
		float num8 = x * num3;
		float num9 = y * num3;
		float num10 = w * num;
		float num11 = w * num2;
		float num12 = w * num3;
		Vector3  result;
		result.x = (1 - (num5 + num6)) * point.x + (num7 - num12) * point.y +
			(num8 + num11) * point.z;
		result.y = (num7 + num12) * point.x + (1 - (num4 + num6)) * point.y +
			(num9 - num10) * point.z;
		result.z = (num8 - num11) * point.x + (num9 + num10) * point.y +
			(1 - (num4 + num5)) * point.z;
		return result;
	}


	inline float dot(const Vector4& vector)
	{
		return x * vector.x + y * vector.y + z * vector.z + w * vector.w;
	}

	inline float distance(const Vector4& vector)
	{
		return sqrtf(
			(x - vector.x) * (x - vector.x) +
			(y - vector.y) * (y - vector.y) +
			(z - vector.z) * (z - vector.z) +
			(w - vector.w) * (w - vector.w));
	}

	bool operator==(const Vector4& vector) const
	{
		return x == vector.x && y == vector.y && z == vector.z && w == vector.w;
	}

	bool operator!=(const Vector4& vector) const
	{
		return x != vector.x || y != vector.y || z != vector.z || w != vector.w;
	}

	Vector4 operator+(const Vector4& vector) const
	{
		return Vector4(x + vector.x, y + vector.y, z + vector.z, w + vector.w);
	}

	Vector4 operator-(const Vector4& vector) const
	{
		return Vector4(x - vector.x, y - vector.y, z - vector.z, w - vector.w);
	}

	Vector4 operator-() const
	{
		return Vector4(-x, -y, -z, -w);
	}

	Vector4 operator*(float number) const
	{
		return Vector4(x * number, y * number, z * number, w * number);
	}

	Vector4 operator/(float number) const
	{
		return Vector4(x / number, y / number, z / number, w / number);
	}

	Vector4& operator+=(const Vector4& vector)
	{
		x += vector.x;
		y += vector.y;
		z += vector.z;
		w += vector.w;
		return *this;
	}

	Vector4& operator-=(const Vector4& vector)
	{
		x -= vector.x;
		y -= vector.y;
		z -= vector.z;
		w -= vector.w;
		return *this;
	}

	Vector4& operator*=(float number)
	{
		x *= number;
		y *= number;
		z *= number;
		w *= number;
		return *this;
	}

	Vector4& operator/=(float number)
	{
		x /= number;
		y /= number;
		z /= number;
		w /= number;
		return *this;
	}
};

class Quaternion {
public:
	float x, y, z, w;

	Quaternion() {
		this->x = 0.0f;
		this->y = 0.0f;
		this->z = 0.0f;
		this->w = 0.0f;
	}

	Quaternion(float x, float y, float z, float w) {
		this->x = x;
		this->y = y;
		this->z = z;
		this->w = w;
	}

	Quaternion operator*(Quaternion rhs) {
		return Quaternion(
			this->w * rhs.x + this->x * rhs.w + this->y * rhs.z - this->z * rhs.y,
			this->w * rhs.y + this->y * rhs.w + this->z * rhs.x - this->x * rhs.z,
			this->w * rhs.z + this->z * rhs.w + this->x * rhs.y - this->y * rhs.x,
			this->w * rhs.w - this->x * rhs.x - this->y * rhs.y - this->z * rhs.z
		);
	}

	float Dot(Quaternion b) {
		return x * x + y * y + z * z + w * w;
	}

	Vector3 operator*(Vector3 point) {
		float num = this->x * 2.f;
		float num2 = this->y * 2.f;
		float num3 = this->z * 2.f;
		float num4 = this->x * num;
		float num5 = this->y * num2;
		float num6 = this->z * num3;
		float num7 = this->x * num2;
		float num8 = this->x * num3;
		float num9 = this->y * num3;
		float num10 = this->w * num;
		float num11 = this->w * num2;
		float num12 = this->w * num3;
		Vector3 result;
		result.x = (1.f - (num5 + num6)) * point.x + (num7 - num12) * point.y + (num8 + num11) * point.z;
		result.y = (num7 + num12) * point.x + (1.f - (num4 + num6)) * point.y + (num9 - num10) * point.z;
		result.z = (num8 - num11) * point.x + (num9 + num10) * point.y + (1.f - (num4 + num5)) * point.z;
		return result;
	}
};


struct Matrix4x4 {
	union {
		struct {
			float        _11, _12, _13, _14;
			float        _21, _22, _23, _24;
			float        _31, _32, _33, _34;
			float        _41, _42, _43, _44;

		}; float m[4][4];
	};
};

namespace Math
{
#define M_PI 3.14159265358979323846f
#define M_RADPI	57.295779513082f
#define M_PI_F ((float)(M_PI))
#define RAD2DEG(x) ((float)(x) * (float)(180.f / M_PI_F))
#define DEG2RAD(x) ((float)(x) * (float)(M_PI_F / 180.f))
#define atan2(a, b) ((float)atan2((double)(a), (double)(b)))
static volatile const double Tiny = 0x1p-1022;
static volatile const double Infinity = INFINITY;
typedef struct { double d0, d1; } double2;

static inline double2 Mul112(double a, double b)
{
	static const double c = 0x1p27 + 1;

	double
		ap = a * c, bp = b * c,
		a0 = (a - ap) + ap, b0 = (b - bp) + bp,
		a1 = a - a0, b1 = b - b0,
		d0 = a * b,
		d1 = a0 * b0 - d0 + a0 * b1 + a1 * b0 + a1 * b1;
	return double2{ d0, d1 };
}

static inline double2 Mul222(double2 a, double2 b)
{
	static const double c = 0x1p27 + 1;

	double
		ap = a.d0 * c, bp = b.d0 * c,
		a0 = (a.d0 - ap) + ap, b0 = (b.d0 - bp) + bp,
		a1 = a.d0 - a0, b1 = b.d0 - b0,
		m0 = a.d0 * b.d0,
		m1 = a0 * b0 - m0 + a0 * b1 + a1 * b0 + a1 * b1 + (a.d0 * b.d1 + a.d1 * b.d0),
		d0 = m0 + m1,
		d1 = m0 - d0 + m1;
	return double2{ d0, d1 };
}

static inline double Mul121Special(double a, double2 b)
{
	static const double c = 0x1p27 + 1;

	double
		ap = a * c, bp = b.d0 * c,
		a0 = (a - ap) + ap, b0 = (b.d0 - bp) + bp,
		a1 = a - a0, b1 = b.d0 - b0,
		m1 = a0 * b0 - 1 + a0 * b1 + a1 * b0 + a1 * b1 + a * b.d1;
	return m1;
}

static inline double2 Add212RightSmaller(double2 a, double b)
{
	double
		c0 = a.d0 + b,
		c1 = a.d0 - c0 + b + a.d1,
		d0 = c0 + c1,
		d1 = c0 - d0 + c1;
	return double2{ d0, d1 };
}

static inline double Add221RightSmaller(double2 a, double2 b)
{
	double
		c0 = a.d0 + b.d0,
		c1 = a.d0 - c0 + b.d0 + b.d1 + a.d1,
		d0 = c0 + c1;
	return d0;
}

static double Tail(double x)
	{
		if (1 <= x)
			return 1 == x
			// If x is 1, generate inexact and return Pi/2 rounded down.
			? 0x3.243f6a8885a308d313198a2e03707344ap-1 + Tiny
			// If x is outside the domain, generate invalid and return NaN.
			: Infinity - Infinity;

		static const double p01 = 0.2145993335526539017488949;
		static const double p02 = -0.0890259194305537131666744;
		static const double p03 = 0.0506659694457588602631748;
		static const double p04 = -0.0331919619444009606270380;
		static const double p05 = 0.0229883479552557203133368;
		static const double p06 = -0.0156746038587246716524035;
		static const double p07 = 0.0097868293573384001221447;
		static const double p08 = -0.0052049731575223952626203;
		static const double p09 = 0.0021912255981979442677477;
		static const double p10 = -0.0006702485124770180942917;
		static const double p11 = 0.0001307564187657962919394;
		static const double p12 = -0.0000121189820098929624806;

		double polynomial = ((((((((((((
			+p12) * x
			+ p11) * x
			+ p10) * x
			+ p09) * x
			+ p08) * x
			+ p07) * x
			+ p06) * x
			+ p05) * x
			+ p04) * x
			+ p03) * x
			+ p02) * x
			+ p01) * x;

#if UseLongDouble
		static const long double HalfPi = 0x3.243f6a8885a308d313198a2ep-1L;
		static const long double p00 = -1.5707961988153774692344105L;

		return HalfPi + sqrtl(1 - x) * (polynomial + p00);
#else	// #if UseLongDouble
		static const double2
			HalfPi = { 0x1.921fb54442d18p+0, 0x1.1a62633145c07p-54 },
			p00 = { -0x1.921fb31e97d96p0, +0x1.eab77149ad27cp-54 };

		// Estimate 1 / sqrt(1-x).
		double e = 1 / sqrt(1 - x);

		double2 ex = Mul112(e, 1 - x);		// e * x.
		double e2x = Mul121Special(e, ex);	// e**2 * x - 1.

		// Set t0 to an improved approximation of sqrt(1-x) with Newton-Raphson.
		double2 t0 = Add212RightSmaller(ex, ex.d0 * -.5 * e2x);

		// Calculate pi/2 + sqrt(1-x) * p(x).
		return Add221RightSmaller(HalfPi, Mul222(
			t0,
			Add212RightSmaller(p00, polynomial)));
#endif	// #if UseLongDouble
	}


float abs(float a) {
	if (a < 0.f) return -a;
	else return a;
}

float asin(float x) {
	float negate = float(x < 0);
	x = abs(x);
	float ret = -0.0187293;
	ret *= x;
	ret += 0.0742610;
	ret *= x;
	ret -= 0.2121144;
	ret *= x;
	ret += 1.5707288;
	ret = 3.14159265358979 * 0.5 - sqrt(1.0 - x) * ret;
	return ret - 2 * negate * ret;
}

	__forceinline float Dot(const Vector3 & Vec1, const Vector3 & Vec2) {
		return Vec1[0] * Vec2[0] + Vec1[1] * Vec2[1] + Vec1[2] * Vec2[2];
	}

	__forceinline float Calc3D_Dist(const Vector3& Src, const Vector3& Dst) {
		return sqrtf(pow((Src.x - Dst.x), 2) + pow((Src.y - Dst.y), 2) + pow((Src.z - Dst.z), 2));
	}

	__forceinline float Calc2D_Dist(const Vector2& Src, const Vector2& Dst) {
		return sqrt(powf(Src.x - Dst.x, 2) + powf(Src.y - Dst.y, 2));
	}
	__forceinline Vector2 CalcAngle(const Vector3& Src, const Vector3& Dst) {
		Vector3 dir = Src - Dst;
		return Vector2{ RAD2DEG(asin(dir.y / dir.Length())), RAD2DEG(-atan2(dir.x, -dir.z)) };
	}
	float Clamp01(float value)
	{
		float result;
		if (value < 0.f)
		{
			result = 0.f;
		}
		else if (value > 1.f)
		{
			result = 1.f;
		}
		else
		{
			result = value;
		}
		return result;
	}
	float Lerp(Vector3 in)
	{
		return in.x + (in.y - in.x) * Clamp01(in.z);
	}
}

#define StrA
struct Ammo {
	int id[2];
	float speed;
};
struct Weapon {
	int id;
	const char* name;
	Ammo ammo[4];
	int category; //-3 - hammer, -2 - bows, -1 - eoka, 0-nopatch, 1 - meele, 2 - semiautomatic, 3 - automatic
};
Weapon info228[]{
Weapon{1588298435, StrA("Bolt Action Rifle"), { Ammo{{-1211166256}/*normal 5.56*/, 656}, Ammo{{1712070256} /*HV 5.56*/, 788 }, Ammo{{-1321651331, 605467368}/*inc, ex 5.56*/, 394}}, 2 },
Weapon{-778367295, StrA("L96 Rifle"), { Ammo{{-1211166256}/*normal 5.56*/, 1125}, Ammo{{1712070256} /*HV 5.56*/, 1350 }, Ammo{{-1321651331, 605467368}/*inc, ex 5.56*/, 675}}, 2 },
Weapon{-2069578888, StrA("M249"), { Ammo{{-1211166256}/*normal 5.56*/, 488}, Ammo{{1712070256} /*HV 5.56*/, 585 }, Ammo{{-1321651331, 605467368}/*inc, ex 5.56*/, 293}}, 3 },

Weapon{1318558775, StrA("MP5A4"), { Ammo{{785728077}/*normal pistol*/, 240}, Ammo{{-1691396643} /*HV pistol*/, 320}, Ammo{{51984655} /*inc pistol*/, 180}}, 3 },
Weapon{1796682209, StrA("Custom SMG"), { Ammo{{785728077}/*normal pistol*/, 240}, Ammo{{-1691396643} /*HV pistol*/, 320}, Ammo{{51984655} /*inc pistol*/, 180}}, 3 },

Weapon{-1367281941, StrA("Waterpipe Shotgun"), { Ammo{{-727717969, -1685290200}/*green, red*/, 225}, Ammo{{588596902, -1036635990}/*gray, blue*/, 100}}, 2 },
Weapon{-765183617, StrA("Double Barrel Shotgun"), { Ammo{{-727717969, -1685290200}/*green, red*/, 225}, Ammo{{588596902, -1036635990}/*gray, blue*/, 100}}, 2 },
Weapon{-41440462, StrA("Spas-12 Shotgun"), { Ammo{{-727717969, -1685290200}/*green, red*/, 225}, Ammo{{588596902, -1036635990}/*gray, blue*/, 100}}, 2 },
Weapon{795371088, StrA("Pump Shotgun"), { Ammo{{-727717969, -1685290200}/*green, red*/, 225}, Ammo{{588596902, -1036635990}/*gray, blue*/, 100}}, 2 },
Weapon{-75944661, StrA("Eoka Pistol"), { Ammo{{-727717969, -1685290200}/*green, red*/, 225}, Ammo{{588596902, -1036635990}/*gray, blue*/, 100}}, -1 },


Weapon{28201841, StrA("M39 Rifle"), { Ammo{{-1211166256}/*normal 5.56*/, 469}, Ammo{{1712070256} /*HV 5.56*/, 563 }, Ammo{{-1321651331, 605467368}/*inc, ex 5.56*/, 281}}, 2 },

Weapon{1965232394, StrA("Crossbow"), { Ammo{{-1234735557}/*normal arrow*/, 75.f}, Ammo{{14241751} /*fire arrow*/, 60}, Ammo{{215754713} /*bone arrow*/, 68}, Ammo{{-1023065463} /*HV arrow*/, 120}}, 2 },
Weapon{884424049, StrA("Compound Bow"), { Ammo{{-1234735557}/*normal arrow*/, 50}, Ammo{{14241751} /*fire arrow*/, 40}, Ammo{{215754713} /*bone arrow*/, 45}, Ammo{{-1023065463} /*HV arrow*/, 80}}, 2 }, //TODO on zoom velocity x2
Weapon{1443579727, StrA("Hunting Bow"), { Ammo{{-1234735557}/*normal arrow*/, 50.f}, Ammo{{14241751} /*fire arrow*/, 40}, Ammo{{215754713} /*bone arrow*/, 45}, Ammo{{-1023065463} /*HV arrow*/, 80} }, -2 },


Weapon{649912614, StrA("Revolver"), { Ammo{{785728077}/*normal pistol*/, 300}, Ammo{{-1691396643} /*HV pistol*/, 400}, Ammo{{51984655} /*inc pistol*/, 225}}, 2 },
Weapon{818877484, StrA("Semi-Automatic Pistol"), { Ammo{{785728077}/*normal pistol*/, 300}, Ammo{{-1691396643} /*HV pistol*/, 400}, Ammo{{51984655} /*inc pistol*/, 225}}, 2 },
Weapon{-852563019, StrA("M92 Pistol"), { Ammo{{785728077}/*normal pistol*/, 300}, Ammo{{-1691396643} /*HV pistol*/, 400}, Ammo{{51984655} /*inc pistol*/, 225}}, 2 },
Weapon{1373971859, StrA("Python Revolver"), { Ammo{{785728077}/*normal pistol*/, 300}, Ammo{{-1691396643} /*HV pistol*/, 400}, Ammo{{51984655} /*inc pistol 225*/, 210}}, 2 },
Weapon{-1758372725, StrA("Thompson"), { Ammo{{785728077}/*normal pistol*/, 300}, Ammo{{-1691396643} /*HV pistol*/, 400}, Ammo{{51984655} /*inc pistol*/, 225}}, 3 },

Weapon{-1812555177, StrA("LR-300 Assault Rifle"), { Ammo{{-1211166256}/*normal 5.56*/, 375}, Ammo{{1712070256} /*HV 5.56*/, 450 }, Ammo{{-1321651331, 605467368}/*inc, ex 5.56*/, 225}}, 3 },
Weapon{-904863145, StrA("Semi-Automatic Rifle"), { Ammo{{-1211166256}/*normal 5.56*/, 375}, Ammo{{1712070256} /*HV 5.56*/, 450 }, Ammo{{-1321651331, 605467368}/*inc, ex 5.56*/, 225}}, 2 },
Weapon{1545779598, StrA("Assault Rifle"), { Ammo{{-1211166256}/*normal 5.56*/, 375}, Ammo{{1712070256} /*HV 5.56*/, 450 }, Ammo{{-1321651331, 605467368}/*inc, ex 5.56*/, 225}}, 3 },


Weapon{1090916276, StrA("Pitchfork"), {Ammo{{0}, 25}}, 1 },
Weapon{1540934679, StrA("Wooden Spear"), {Ammo{{0}, 20}}, 1 },
Weapon{1814288539, StrA("Bone Knife"), {Ammo{{0}, 20}}, 1 },
Weapon{-363689972, StrA("Snowball"), {Ammo{{0}, 20}}, 1 },
Weapon{1789825282, StrA("Candy Cane Club"), {Ammo{{0}, 20}}, 1 },
Weapon{-1137865085, StrA("Machete"), {Ammo{{0}, 20}}, 1 },
Weapon{1711033574, StrA("Bone Club"), {Ammo{{0}, 20}}, 1 },
Weapon{-1966748496, StrA("Mace"), {Ammo{{0}, 18}}, 1 },
Weapon{-194509282, StrA("Butcher Knife"), {Ammo{{0}, 20}}, 1 },
Weapon{1326180354, StrA("Salvaged Sword"), {Ammo{{0}, 20}}, 1 },
Weapon{-1469578201, StrA("Longsword"), {Ammo{{0}, 18}}, 1 },
Weapon{-1978999529, StrA("Salvaged Cleaver"), {Ammo{{0}, 18}}, 1 },
Weapon{1602646136, StrA("Stone Spear"), {Ammo{{0}, 25}}, 1 },
Weapon{2040726127, StrA("Combat Knife"), {Ammo{{0}, 30}}, 1 },
Weapon{963906841, StrA("Rock"), {Ammo{{0}, 18}}, 1 },

Weapon{1953903201, StrA("Nailgun"), { Ammo{{-2097376851}/*nails*/, 50}}, 2 },
Weapon{-1123473824, StrA("Multiple Grenade Launcher"), { Ammo{{915408809, 349762871}/*smoke, exp*/, 100}, Ammo{{1055319033}, 225}/*shotgun*/}, 2 },
Weapon{442886268, StrA("Rocket Launcher"), 0, 0 },
Weapon{-1215753368, StrA("Flame Thrower"), 0, 0 },
Weapon{200773292, StrA("Hammer"), {0}, -3 }
};