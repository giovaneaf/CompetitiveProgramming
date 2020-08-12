struct Tvec
{
	long double x, y;
	Tvec(long double x = 0.0, long double y = 0.0) : x(x), y(y) {}
	Tvec operator+ (Tvec& v)					// get a point from a point + vector
	{
		return {x+v.x, y+v.y};
	}
	Tvec operator- (Tvec& v)					// (a-b) vector pointing from a to b
	{
		return Tvec(x-v.x, y-v.y);
	}
	Tvec operator* (long double scalar)			// scalar multiplication
	{
		return Tvec(x*scalar, y*scalar);
	}
	long double operator* (Tvec& v)				// dot
	{
		return x*v.x + y*v.y;
	}
	long double operator^ (Tvec& v)				// cross
	{
		return x*v.y - y*v.x;
	}
	long double operator~()						// length
	{
		return hypot(x, y);
	}
	void normalize()							// length = 1
	{
		long double norm = ~(*this);
		x /= norm; y /= norm;
	}
	Tvec rotate(long double angle)				// rotate counterclockwise
	{
		return Tvec(x*cos(angle) - y*sin(angle), x*sin(angle) + y*cos(angle));
	}
};