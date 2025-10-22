#ifndef __CIRCLE2D_H__
#define __CIRCLE2D_H__

#include "Point2D.h"

constexpr double PI = 3.1415;

class Circle2D
{
private:
	Point2D center;
	int radius; // 반지름(반경)

	Point2D* points; // 원의 둘레를 이루는 점들
	int pCount; // 배열 크기

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

	// points를 계산하는 함수
	// 이 함수 호출해준 뒤 getPerimeterPoints()를 사용한다.
	void generatePoints(int count);

};


#endif
