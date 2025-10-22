#ifndef __POINT_H__
#define __POINT_H__

#include <iostream>

class MyPoint2D
{
private:
	float x;
	float y;

public:
	// ������
	MyPoint2D();
	MyPoint2D(float px, float py);
	virtual ~MyPoint2D();

	float GetX() const;
	float GetY() const;
	void SetX(float dx);
	void SetY(float dy);

	// �ٸ� MyPoint2D���� ��Ŭ���� �Ÿ� ��ȯ
	double distanceFrom(const MyPoint2D& other) const;
	
	// ��� ���� ���� ���ڿ��� ��ȯ
	virtual std::string toString() const;

	// ���� ��ǥ�� dx, dy�� ���޹޾� ���Ѵ�
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
