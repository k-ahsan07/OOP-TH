#include <iostream>
using namespace std;
class Shape
{
private:
	float width, height;
public:
	Shape(float W, float H){
		width=W;
		height=H;
	}
	float getW() 
	{
		return width;
	}
	float getH() 
	{
		return height;
	}
};	
class Rectangle: public Shape
{
public:
   	Rectangle(float width, float height):Shape(width,height)
    {
    }
    float area()
    {
        return (getW()*getH());
    }
};
class Triangle: public Shape
{
public:
    Triangle(float base,float height): Shape(base,height)
    {
    }
    float area()
    {
        return (getW()*getH())/2.0;
    }
};
int main ()
{
    float width, height,base;
    cout<<"Enter width of rectangle: ";
    cin>>width;
    cout<<"Enter height of rectangle: ";
    cin>>height;
    cout<<"Enter base of rectangle: ";
    cin>>base;
	Rectangle rectangle(width,height);
	Triangle triangle(base,height);
	cout <<"Area of rectangle: "<< rectangle.area() << endl;
	cout <<"Area of triangle: "<< triangle.area() << endl;
	return 0;
}
