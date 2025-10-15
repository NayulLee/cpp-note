#include <iostream>
#include "Circle2D.h"

int main()
{
	Point2D center(0, 0);
	Circle2D circle(center, 5);

	circle.generatePoints(5);

	const Point2D* points = circle.getPerimeterPoints();
	std::cout << "원 중심 (" << circle.getCenter().getX() 
		<< ", "<< circle.getCenter().getY() << ")" << std::endl;
	
	std::cout << "반지름 : " << circle.getRadius() << std::endl;
	
	std::cout << "원의 둘레 " << circle.getPCount() << "개 점 좌표" << std::endl;

	for (int i = 0; i < circle.getPCount(); i++)
	{
		std::cout << i << ". (" <<
			points[i].getX() << ", " <<
			points[i].getY() << ")" << std::endl;
	}

	return 0;
}
