#include <iostream>
using std::cout;
using std::endl;

class Shape
{
public:
	Shape() { cout << "Shape is created" << endl; }
	virtual void show() const = 0;
	virtual void hide() const = 0;
	virtual ~Shape() { cout << "Shape is deleted" << endl; }
};

class Point : public Shape
{
protected:
	int _x0, _y0;
public:
	Point(int x0 = 0, int y0 = 0):_x0(x0), _y0(y0) 
	{
		cout << "Point is created" << endl;
	}
	void show() const override { cout << "Point is shown" << endl; }
	void hide() const override { cout << "Point is hidden" << endl; }
	~Point() { cout << "Point is deleted" << endl; }
};

class Circle : virtual public Point
{
protected:
	int _rad;
public:
	Circle(int x0 = 0, int y0 = 0, int rad = 1) : Point(x0, y0), _rad(rad)
	{
		cout << "Circle was created" << endl;
	}
	void show() const override { cout << "Circle is shown" << endl; }
	void hide() const override { cout << "Circle is hidden" << endl; }
	void fill(const char* color) { cout << "Now the circle is " << color << endl; }
	~Circle() { cout << "Circle is deleted" << endl; }
};

class Rectangle : virtual public Point
{
protected:
	int _width, _height;
public:
	Rectangle(	int x0 = 0,
				int y0 = 0,
				int width = 1,
				int height = 1) : Point(x0, y0), _width(width), _height(height) {}
	void show() const override { cout << "Rectangle is shown" << endl; }
	void hide() const override { cout << "Rectangle is hidden" << endl; }
};

class Square : public Rectangle
{
public:
	Square(int x0 = 0, int y0 = 0, int a = 1) : Rectangle(x0, y0, a, a) {}
};

class CircleInSquare : public Circle, public Square
{
public:
	CircleInSquare(int x0 = 0, int y0 = 0, int r = 1) : Circle(x0, y0, r), Square(x0, y0, r) {}
	void show() const override { Circle::show(); Square::show(); }
	void hide() const override { Circle::hide(); Square::hide(); }
};

void ShowAll(Shape* objects[], int n)
{
	for (int i = 0; i < n; ++i)
	{
		Circle* c = dynamic_cast<Circle*>(objects[i]);
		if (c != nullptr)
			c->fill("Red");

		objects[i]->show();
	}
}

int main()
{
	CircleInSquare cir;

	Shape* shapes[4] = { new Circle(1,1,2), 
						 new Point(), 
						 new Circle(0,0,5), 
						 new Point(-2,1) };
	
	cout << "Hello world" << endl;
	cout << "-------" << endl;
	ShowAll(shapes, 4);
	cout << "-------" << endl;

	Point c;
	Shape& s = c;
	try
	{
		Circle& c_ref = dynamic_cast<Circle&>(s);
		c_ref.show();
	}
	catch (...) { cout << "Unable to cast" << endl; }

	for (int i = 0; i < 4; ++i)
		delete shapes[i];
	system("pause");
	return 0;
}