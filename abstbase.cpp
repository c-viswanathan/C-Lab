#include<iostream>
using namespace std;
class Shape{
    public:
        virtual double area() const = 0;
        virtual void name() const = 0;
        virtual ~Shape(){}
};
class Circle : public Shape{
    double r;
    public:
        Circle(double r) : r(r){}
        double area() const override { return 3.14 * r * r; }
        void name() const override { cout << "Circle"; }
};
class Square : public Shape{
    double s;
    public:
        Square(double s) : s(s){}
        double area() const override { return s * s; }
        void name() const override { cout << "Square"; }
};
int main(){
    Shape* shapes[] = { new Circle(2), new Square(3) };
    for(Shape* s : shapes){
        s->name();
        cout << " area = " << s->area() << endl;
    }
    for(Shape* s : shapes) delete s;
}