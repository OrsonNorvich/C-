#include <bits/stdc++.h>

using namespace std;

class Rational
{
    int iUp;
    int iDown;
    void Reduce()
    {
        int tmp = Gcd(iUp, iDown);
        iUp /= tmp;
        iDown /= tmp;
        if (iUp>0 && iDown<0)
        {
            iUp *= -1;
            iDown *= -1;
        }
    }
    int Gcd(int l, int r)
    {
        if(l == 0) return r;
        else return Gcd(r%l, l);
    }
public:
    Rational(int iup, int idown):iUp(iup), iDown(idown)
    {
        Reduce();
    }
    const Rational operator-() const
    {
        return Rational(-iUp, iDown);
    }
    Rational& operator=(const Rational& tmp)
    {
        if(this == &tmp) return *this;
        iUp = tmp.iUp;
        iDown = tmp.iDown;
        return *this;
    }
    const Rational& operator++()
    {
        iUp+=iDown;
        return *this;
    }
    const Rational& operator--()
    {
        iUp-=iDown;
        return *this;
    }
    const Rational& operator++(int)
    {
        Rational before(iUp,iDown);
        iUp+=iDown;
        return before;
    }
    const Rational& operator--(int)
    {
        Rational before(iUp,iDown);
        iUp-=iDown;
        return before;
    }
    friend const Rational operator+(const Rational& a, const Rational& b)
    {
        return Rational(a.iUp*b.iDown+a.iDown*b.iUp, a.iDown*b.iDown);
    }
    friend const Rational operator-(const Rational& a, const Rational& b)
    {
        return Rational(a.iUp*b.iDown-a.iDown*b.iUp, a.iDown*b.iDown);
    }
    friend const Rational operator*(const Rational& a, const Rational& b)
    {
        return Rational(a.iUp*b.iUp, a.iDown*b.iDown);
    }
    friend const Rational operator/(const Rational& a, const Rational& b)
    {
        return Rational(a.iUp*b.iDown, a.iDown*b.iUp);
    }
    friend bool operator<(const Rational& a, const Rational& b)
    {
        Rational c = a-b;
        if(c.iUp<0) return true;
        return false;
    }
    friend bool operator>(const Rational& a, const Rational& b)
    {
        Rational c = a-b;
        if(c.iUp>0) return true;
        return false;
    }
    friend bool operator<=(const Rational& a, const Rational& b)
    {
        Rational c = a-b;
        if(c.iUp<=0) return true;
        return false;
    }
    friend bool operator>=(const Rational& a, const Rational& b)
    {
        Rational c = a-b;
        if(c.iUp>=0) return true;
        return false;
    }
    friend istream& operator>>(istream& is, Rational& tmp)
    {
        return is>>tmp.iUp>>tmp.iDown;
    }
    friend ostream& operator<<(ostream& os, const Rational& tmp)
    {
        if(tmp.iDown==1) os<<tmp.iUp;
        else os<<tmp.iUp<<"/"<<tmp.iDown;
        return os;
    }
};

int main()
{
    int a,b,c,d;
     cin>>a>>b>>c>>d;
     Rational a1(a,b),a2(c,d);
     cout<<"a+b: "<<a1+a2<<endl;
     cout<<"a-b: "<<a1-a2<<endl;
     cout<<"a*b: "<<a1*a2<<endl;
     cout<<"a/b: "<<a1/a2<<endl;
     cout<<"-a: "<<-a1<<endl;
     cout<<"++a: "<<++a1<<endl;
     cout<<"--a: "<<--a1<<endl;
     cout<<"a++: "<<a1++<<endl;
     cout<<"a--: "<<a1--<<endl;
     bool w,x,y,z;
     w=a1<a2;
     x=a1<=a2;
     y=a1>a2;
     z=a1>=a2;
     cout<<"a<b: ";w?cout<<"true":cout<<"false";cout<<endl;
     cout<<"a<=b: ";x?cout<<"true":cout<<"false";cout<<endl;
     cout<<"a>b: ";y?cout<<"true":cout<<"false";cout<<endl;
     cout<<"a>=b: ";z?cout<<"true":cout<<"false";cout<<endl;

    return 0;
}
