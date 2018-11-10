#include <iostream>
#include <string>
using namespace std;



class Shape{
public:
	virtual void draw() = 0;
	virtual int getArea() = 0;
};

class Point:public Shape
{
	int x;
	int y;
public:
	Point(int x,int y)
	{
		this->x = x;
		this->y = y;
	}
	void draw()
	{
		cout<< "This is a point"<<endl;
	}
	int getArea()
	{
		return 0;
	}
	int getX()
	{
		return this->x;
	}
	int getY()
	{
		return this->y;
	}
};

class Circle:public Shape
{
	int radius;
	Point center;
public:
	Circle (int r, Point p): radius(r),center(p){};
	int getRadius(){
		return this->radius;
	}

	void draw()
	{
		cout<< "This is a circle!"<<endl;
	}
	int getArea()
	{
		int Area = 3.14*getRadius()*getRadius();
		return Area;
	}
	float getAreaF()
	{
		float Area= 3.14*getRadius()*getRadius();
		return Area;
	}

};

class Rectangle:public Shape
{
	int length;
	int width;
	Point center;
public:
	Rectangle(int l, int w, Point p): length(l), width(w), center(p){}
	int getLength()
	{
		return this->length;
	}
	int getWidth()
	{
		return this->width;
	}
	void draw()
	{
		cout << "This is a regtangle"<< endl;
	}
	int getArea()
	{
		return  getWidth() * getLength();
	}
};
class Square:public Shape
{
	int side;
	Point center;
public:
	Square(int s,Point c): side(s), center(c){}
	int getSide()
	{
		return this->side;
	}
	virtual void draw()
	{
		cout << "This is a square"<< endl;
	}

	int getArea()
	{
		int area = side * side;
		return area;
	}
};
class Triangle:public Shape
{

};

// class ShapeList
// {
// 	Shape* arr;
// 	int size;
// 	int alloc_size;
// public:
// 	ShapeList(){
// 		this->arr = (Shape*)malloc(10* sizeof(Shape*));
// 		this->size = 0;
// 		this->alloc_size = 10;
// 	}
// 	~ShapeList(){
// 		free(arr);
// 	}
// 	int find(Shape& shape)
// 	{
// 		for (int i = 0; i<= alloc_size ;i++)
// 		{
// 			if (arr+i == &shape)
// 				return i;
// 		}
// 		return -1;
// 	}
// 	void add (Shape* shape)
// 	{
// 		if (size == alloc_size)
// 		{
// 			this->arr = (Shape*) malloc(100*sizeof(Shape*));
// 		}
// 		(arr+size) = shape;
// 		size++;
// 	}
// };


class ShapeList{
	Shape* arr;
	int count;
	int size;
public:
	ShapeList(int size=10)
	{
		this->count = 0;
		this->size = size;
		this->arr = (Shape*)malloc(size* sizeof(Shape*));
	}
	void add(Shape& shape)
	{
		if(count==getSize())
			Realloc(size*2);
		arr[size] = shape;
	}
	void Realloc(int s)
	{
		realloc(this->arr,s * sizeof(Shape*));
		this->size = s;
	}
	int getSize()
	{
		return size;
	}
	int find(Shape& shape)
	{
		for(int i=0;i<size;i++)
		if(&shape==(arr+i))return i;
	return -1;
	};
	int remove(Shape& shape){

	}
};

int main()
{

	Point p(0,0);
	Circle c(4,p);
	cout << c.getAreaF()<< endl;
	c.draw();

	Rectangle r(5,3,p);
	cout<<r.getArea()<<endl;
	r.draw();

	Square s(4,p);
	cout<< s.getArea()<<endl;
	ShapeList array;
	array.add(c);
	array.add(r);
	cout<<array.find(r)<<endl;
	return 0;
}