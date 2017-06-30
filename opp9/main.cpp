#include <bits/stdc++.h>

using namespace std;

const double pi=3.1415926;

class Shape
{
public:
    Shape() {};
    virtual double Area()=0;
    virtual void Show()=0;
    virtual ~Shape() {};
    friend bool operator==(Shape& larea,Shape& rarea)
    {
        return abs(larea.Area()-rarea.Area())<=1.0e-8;
    }
    friend bool operator>(Shape& larea,Shape& rarea)
    {
        return (larea.Area()>rarea.Area());
    }
    friend bool operator<(Shape& larea,Shape& rarea)
    {
        return (larea.Area()<rarea.Area());
    }
};

class Rectangle:public Shape
{
protected:
    double rectWidth;
    double rectHeight;
public:
    Rectangle(double width, double height);
    double Area();
    void Show();
};
Rectangle::Rectangle(double width, double height):rectWidth(width),rectHeight(height) {};
void Rectangle::Show()
{
    cout<<"W: "<<rectWidth<<"; H:"<<rectHeight<<"; Area: "<<Area()<<endl;

}
double Rectangle::Area()
{
    return rectHeight*rectWidth;
}
class Ellipse:public Shape
{
protected:
    double rectWidth;
    double rectHeight;
public:
    Ellipse(double width, double height);
    double Area();
    void Show();

};
Ellipse::Ellipse(double width, double height):rectWidth(width), rectHeight(height) {};
void Ellipse::Show()
{
    cout<<"W: "<<rectWidth<<"; H:"<<rectHeight<<"; Area: "<<Area()<<endl;

}
double Ellipse::Area()
{
    return ((pi * rectHeight * rectWidth)/4);
}
int main()
{
    int Num;
    cin>>Num;
    Shape**Arr=new Shape*[Num];
    char Type;
    double w,h;
    for(int i=0; i<Num; i++)
    {
        cin>>Type>>w>>h;
        switch(Type)
        {
        case 'R':
        {
            Arr[i]=new Rectangle(w,h);
            break;
        }
        case 'E':
        {
            Arr[i]=new Ellipse(w,h);
            break;
        }
        }
    }
    for(int i=0; i<Num; i++)
    {
        Arr[i]->Show();
    }
    for(int i=0; i<Num; i++)
    {
        for(int j=i+1; j<Num; j++)
        {
            if(*Arr[i]==*Arr[j])
            {
                cout<<"Area of Shape["<<i<<"] is equal to Shape["<<j<<"]"<<endl;
            }
        }
    }
    int k;
    Shape* Temp;
    for(int i=0; i<Num-1; i++)
    {
        k=i;
        for(int j=i+1; j<Num; j++)
        {
            if(*Arr[j]>*Arr[k])
            {
                k=j;
            }
        }
        Temp=Arr[i];
        Arr[i]=Arr[k];
        Arr[k]=Temp;
    }
    for(int i=0; i<Num; i++)
    {
        Arr[i]->Show();
    }
    return 0;
}
