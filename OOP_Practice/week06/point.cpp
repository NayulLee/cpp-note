#include "point.h"
#include <cmath>
#include <string>

using namespace std;

// 생성자
MyPoint2D::MyPoint2D() : x(0), y(0) {}

MyPoint2D::MyPoint2D(float px, float py): x(px), y(py) {}

MyPoint2D::~MyPoint2D() {}

float MyPoint2D::GetX() const { return x; }

float MyPoint2D::GetY() const { return y; }

void MyPoint2D::SetX(float dx) { x = dx;}

void MyPoint2D::SetY(float dy) { y = dy; }

double MyPoint2D::distanceFrom(const MyPoint2D& other) const
{
	// 두 점사이 직선거리 반환
	// sqrt(), pow()는 자동으로 double로 승격되어 계산
	return sqrt(pow((other.x - x), 2) + pow((other.y - y), 2));
}

string MyPoint2D::toString() const
{
	string returnString;
	returnString += "좌표:(";
	returnString += to_string(x);
	returnString += ", ";
	returnString += to_string(y);
	returnString += ")";

	return returnString;
}

void MyPoint2D::translate(float dx, float dy)
{
	x += dx;
	y += dy;
}

// -----------MyClass3D-----------
MyPoint3D::MyPoint3D() : MyPoint2D(), z(0) {}

MyPoint3D::MyPoint3D(float px, float py, float pz) : MyPoint2D(px, py), z(pz) {}

MyPoint3D::MyPoint3D(const MyPoint2D& other, float pz): z(pz)
{
	SetX(other.GetX());
	SetY(other.GetY());

}

MyPoint3D::~MyPoint3D() {}

float MyPoint3D::GetZ() const { return z; }
void MyPoint3D::SetZ(float dz) { z = dz; }

double MyPoint3D::distanceFrom(const MyPoint3D& other) const
{
	double d2 = MyPoint2D::distanceFrom(other);

	return sqrt(pow(d2, 2) + pow((other.z - z), 2));
}

string MyPoint3D::toString() const
{
	return "좌표: (" + to_string(MyPoint2D::GetX()) + ", "
					 + to_string(MyPoint2D::GetY()) + ", "
					 + to_string(z) + ")";
}

void MyPoint3D::translate(float dx, float dy, float dz)
{
	SetX(GetX() + dx);
	SetY(GetY() + dy);
	z += dz;
}