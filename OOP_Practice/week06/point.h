#ifndef __POINT_H__
#define __POINT_H__

#include <iostream>

class MyPoint2D
{
private:
	float x;
	float y;

public:
	// 생성자
	MyPoint2D();
	MyPoint2D(float px, float py);
	virtual ~MyPoint2D();

	float GetX() const;
	float GetY() const;
	void SetX(float dx);
	void SetY(float dy);

	// 다른 MyPoint2D와의 유클리드 거리 반환
	double distanceFrom(const MyPoint2D& other) const;
	
	// 멤버 변수 정보 문자열로 반환
	virtual std::string toString() const;

	// 현재 좌표에 dx, dy를 전달받아 더한다
	virtual void translate(float dx, float dy);

};


class MyPoint3D:public MyPoint2D
{
private:
	float z;

public:
	MyPoint3D();
	MyPoint3D(float px, float py, float pz);
	MyPoint3D(const MyPoint2D& other, float pz);
	~MyPoint3D();

	float GetZ() const;
	void SetZ(float dz);

	double distanceFrom(const MyPoint3D& other) const;
	std::string toString() const override;
	void translate(float dx, float dy, float dz) ;
};




#endif
