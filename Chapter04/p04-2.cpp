// 다음의 Point 클래스를 기반으로 하여 원을 의미하는 Circle 클래스를 정의하자
#include <iostream>

using namespace std;

class Point
{
private:
    int xpos, ypos; // 좌표값 멤버
    
public:
    void init(int x, int y)  // 좌표 초기화 함수
    {
        xpos = x;
        ypos = y;
    }

    void showPointInfo() const  // [x, y]좌표 출력 함수
    {
        cout << "[" << xpos << ", " << ypos << "]" << endl;
    }
};

// 원을 의미하는 Circle 클래스
class Circle
{
private:
    Point center;
    int radius;

public:
    void initCircle(Point& point, int rad)
    {
        if(rad <= 0) // 반지름 값이 0보다 작은지 검사
        {
            cout << "redius 값이 유효하지 않습니다";
            return;
        }
        center = point;
        radius = rad;
    }

    void showCircleInfo() const  // 중심좌표와 반지름의 길이 출력
    {
        cout << "중심좌표 : ";
        center.showPointInfo(); 
        cout << "반지름 : " << radius << endl;
    }
};

class Ring
{
private:
    Circle innerCircle; // 안쪽 원
    Circle outerCircle; // 바깥쪽 원

public:
    void init(int x1, int y1, int rad1, int x2, int y2, int rad2)
    {
        Point p1, p2;
        p1.init(x1, x2);
        p2.init(x2, y2);
        innerCircle.initCircle(p1, rad1);
        outerCircle.initCircle(p2, rad2);
    }

    void showRingInfo() const
    {
        cout << "----inner circle info...-----" << endl;
        innerCircle.showCircleInfo();
        cout << "----outer circle info...-----" << endl;
        outerCircle.showCircleInfo();
    }
};

int main()
{
    Ring ring;
    ring.init(1, 1, 4, 2, 2, 9);
    ring.showRingInfo();

    return 0;
}