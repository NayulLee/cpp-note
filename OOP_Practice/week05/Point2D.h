#ifndef __POINT2D_H__
#define __POINT2D_H__

class Point2D
{
private:
	int x, y; // xÁÂÇ¥, yÁÂÇ¥

public:
	Point2D();
	Point2D(int px, int py);
	~Point2D();
	int getX() const;
	int getY() const;

};



#endif