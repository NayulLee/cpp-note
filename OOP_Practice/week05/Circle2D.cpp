#include "Circle2D.h"
#include <cmath>

// --------------------Point2D--------------------
int Point2D::getX() const { return x; }
int Point2D::getY() const { return y; }

Point2D::Point2D() : x(0), y(0) {}
Point2D::Point2D(int px, int py) { x = px; y = py; }
Point2D::~Point2D() {}
// --------------------Circle2D--------------------

Circle2D::Circle2D(Point2D cnt, int rad)
{
	center = cnt;
	radius = rad;
}

Circle2D::~Circle2D()
{
	delete[] points;
}

// 깊은복사
Circle2D::Circle2D(const Circle2D& other)
{
	center = other.center;
	radius = other.radius;
	pCount = other.pCount;
	if (pCount > 0) // 복사하려는 배열이 존재하면
	{
		points = new Point2D[pCount];
		for (int i = 0; i < pCount; i++)
			points[i] = other.points[i];
	}
	else
		points = nullptr;
}

// getter
Point2D Circle2D::getCenter() const
{
	return center;
}

int Circle2D::getRadius() const
{
	return radius;
}

int Circle2D::getPCount() const
{
	return pCount;
}

const Point2D* Circle2D::getPerimeterPoints() const
{
	return points;
	// 반환값을 const로 만들어서 외부에서 배열 수정 못하게 막는다
}


// 원 둘레 점 좌표를 정수로 근사해서 저장하는 함수
void Circle2D::generatePoints(int count)
{
	// 기존 points배열 해제 후 초기화
	delete[] points;
	points = nullptr;

	// 새 배열 동적할당
	points = new Point2D[count];
	pCount = count; // 배열 크기 저장 pointCount

	// 원 둘레 점 계산 후 저장
	for (int i = 0; i < count; i++)
	{
		// round() : 반올림 후 double값 반환
		double theta = (2 * PI / count) * i;
		int px = static_cast<int>(round(center.getX() + radius * cos(theta)));
		int py = static_cast<int>(round(center.getY() + radius * sin(theta)));
		points[i] = Point2D(px, py);
	}
}