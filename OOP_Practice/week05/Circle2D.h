#ifndef __CIRCLE2D_H__
#define __CIRCLE2D_H__

#include "Point2D.h"

constexpr double PI = 3.1415;

class Circle2D
{
private:
	Point2D center;
	int radius; // ������(�ݰ�)

	Point2D* points; // ���� �ѷ��� �̷�� ����
	int pCount; // �迭 ũ��

public:
	Circle2D(Point2D cnt, int rad);
	Circle2D(const Circle2D& other);
	~Circle2D();

	// getter
	Point2D getCenter() const;
	int getRadius() const;
	const Point2D* getPerimeterPoints () const;
	int getPCount() const;

	// setter
	void setCenter(Point2D sCenter);
	void setRadius(int sRadius);

	// points�� ����ϴ� �Լ�
	// �� �Լ� ȣ������ �� getPerimeterPoints()�� ����Ѵ�.
	void generatePoints(int count);

};


#endif
