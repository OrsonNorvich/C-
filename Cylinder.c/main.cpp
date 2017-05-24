#include <iostream>

using namespace std;

class Cylinder
{
private:
    double height, radius;
public:
    static const double pi = 3.1415926;
    double GetPI();
    Cylinder(double height=0, double radius=0):height(height),radius(radius){}
    double GetRadius();
    double GetHeight();
    void SetRadius(double radius);
    void SetHeight(double height);
    double Volume();
    double Area();
};

int main()
{
    double radius, height;
    cin>>height>>radius;
    Cylinder fun(height, radius);
    cout <<"pi="<<fun.GetPI()<<", height="<<height<<", radius="<<radius<<":volume="<<fun.Volume()<<", area="<<fun.Area()<< endl;
    return 0;
}

double Cylinder::GetPI()
{
    return pi;
}

double Cylinder::GetRadius()
{
    return radius;
}

double Cylinder::GetHeight()
{
    return height;
}

void Cylinder::SetRadius(double radius)
{
    this->radius = radius;
}

void Cylinder::SetHeight(double height)
{
    this->height = height;
}

double Cylinder::Volume()
{
    return pi*radius*radius*height;
}

double Cylinder::Area()
{
    return (2*pi*radius*radius + 2*pi*radius*height);
}
