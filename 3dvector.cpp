#include <iostream>

using namespace std;

class vector3d
{
public:
	double x, y, z;

	/// Default class constructor
	vector3d() : x(0), y(0), z(0) { }

	/// Class constructor from three values
	vector3d(int x, int y, int z) : x(x), y(y), z(z) { }

	/// Copy constructor
	vector3d(const vector3d& v) { x = v.x; y = v.y; z = v.z; }

	/// Assignment operator
	vector3d& operator=(const vector3d& a)
	{
		x = a.x;
		y = a.y;
		z = a.z;
		return *this;
	}

	/// Addition of vectors
	vector3d operator+(const vector3d& a) const
	{
		return vector3d(x + a.x, y + a.y, z + a.z);
	}

	/// Addition of vectors
	const vector3d& operator+=(const vector3d& a)
	{
		return *this = *this + a;
	}

	/// Subtraction of vectors
	vector3d operator-(const vector3d& a) const
	{
		return vector3d(x - a.x, y - a.y, z - a.z);
	}

	/// Subtraction of vectors
	const vector3d& operator-=(const vector3d& a)
	{
		return *this = *this - a;
	}

	/// Unary minus sign
	vector3d operator-() const
	{
		return vector3d(-x, -y, -z);
	}

	/// Scalar product of two vectors
	double operator*(const vector3d& a) const
	{
		return x*a.x + y*a.y + z*a.z;
	}

	/// Product of vector with scalar
	vector3d operator*(const double& b) const
	{
		return vector3d(x*b, y*b, z*b);
	}

	/// Product of a scalar with a vector
	friend vector3d operator*(const double& b, const vector3d& a)
	{
		return vector3d(a.x*b, a.y*b, a.z*b);
	}

	/// Multiplication of vector by scalar
	const vector3d& operator*=(const double& a)
	{
		return *this = *this * a;
	}

	/// Division of a vector by a scalar
	vector3d operator/(const double& a) const
	{
		return vector3d(x / a, y / a, z / a);
	}

	/// Division of vector by a scalar
	const vector3d& operator/=(const double& a)
	{
		return *this = *this / a;
	}

	/// The cross product of two vectors
	friend vector3d cross(const vector3d& a, const vector3d& b)
	{
		return vector3d(a.y*b.z - a.z*b.y, a.z*b.x - a.x*b.z, a.x*b.y - a.y*b.x);
	}

	/// Comparison
	bool operator==(const vector3d& b) const
	{
		return (x == b.x && y == b.y && z == b.z);
	}

	/// Comparison
	bool operator!=(const vector3d& b) const
	{
		return (x != b.x || y != b.y || z != b.z);
	}

	/// Send to output stream
	friend std::ostream& operator<<(std::ostream& os, const vector3d& v)
	{
		return os << '(' << v.x << ',' << v.y << ',' << v.z << ')';
	}
};

int main()
{
	int testsFailed = 0;
	// Implement a 3D vector class, providing a useful set of methods or functions for the class & any other related classes.
	//Discuss the design choices you make in your implementation. Share you code and design choices.
	vector3d a(1.0, 2.0, 3.0), b(-1, -1, -1), origin, tmp;
	tmp += b;
	if (tmp != b) testsFailed++;
	tmp -= b;
	if (tmp != origin) testsFailed++;
	origin *= 10;
	b /= 1;
	if (origin != vector3d(0, 0, 0)) testsFailed++;
	if (vector3d(a) != a) testsFailed++;
	if (a + b != vector3d(0, 1, 2)) testsFailed++;
	if (a - b != vector3d(2, 3, 4)) testsFailed++;
	if ((a != -1 * -a) || (a != -a * -1)) testsFailed++;
	if (b == -b) testsFailed++;
	if (b + -b != origin) testsFailed++;
	cout << a << " * " << b << " is " << a * b << endl;
	cout << a << " X " << b << " is " << cross(a, b) << " #cross" << endl;
#if 1
	if (testsFailed == 0)
		cout << "vector3d tests succesfull!" << endl;
	else
		cout << "One or more tests failed";
#else
	if (testsFailed == 0)
		printf("vector3d tests succesfull!\n");
	else
		printf("vector3d failed %d tests", testsFailed);
#endif 
	return testsFailed;
}
