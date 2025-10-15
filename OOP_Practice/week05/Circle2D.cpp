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

// ��������
Circle2D::Circle2D(const Circle2D& other)
{
	center = other.center;
	radius = other.radius;
	pCount = other.pCount;
	if (pCount > 0) // �����Ϸ��� �迭�� �����ϸ�
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
	// ��ȯ���� const�� ���� �ܺο��� �迭 ���� ���ϰ� ���´�
}


// �� �ѷ� �� ��ǥ�� ������ �ٻ��ؼ� �����ϴ� �Լ�
void Circle2D::generatePoints(int count)
{
	// ���� points�迭 ���� �� �ʱ�ȭ
	delete[] points;
	points = nullptr;

	// �� �迭 �����Ҵ�
	points = new Point2D[count];
	pCount = count; // �迭 ũ�� ���� pointCount

	// �� �ѷ� �� ��� �� ����
	for (int i = 0; i < count; i++)
	{
		// round() : �ݿø� �� double�� ��ȯ
		double theta = (2 * PI / count) * i;
		int px = static_cast<int>(round(center.getX() + radius * cos(theta)));
		int py = static_cast<int>(round(center.getY() + radius * sin(theta)));
		points[i] = Point2D(px, py);
	}
}