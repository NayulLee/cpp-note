// 연산자 오버로딩 이해를 위한 간단한 예제
#include <iostream>

class Point{
public:
    int x, y;

    Point(int a = 0, int b = 0) : x(a), y(b){}

    // + 연산자 오버로딩 (객체끼리 더하기)
    Point operator+(const Point& p) const
    {
        return Point(x + p.x, y + p.y);
    }

    // -연산자 오버로딩(객체끼리 빼기)
    Point operator-(const Point& p) const
    {
        return Point(x - p.x, y - p.y);
    }

    // << 연산자 오버로딩(출력용)
    friend std::ostream& operator<<(std::ostream& os, const Point& p) {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }
};

int main() {
    Point p1(3, 4);
    Point p2(1, 2);

    Point p3 = p1 + p2; // operator+() 호출
    Point p4 = p1 - p2; // operator-() 호출

    std::cout << "p1 + p2 = " << p3 << std::endl;
    std::cout << "p1 - p2 = " << p4 << std::endl;

    return 0;
}