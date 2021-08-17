#include <iostream>


class Figure
{
public:
	virtual void area() = 0;
};

class Parallelogram : public Figure
{
private:
	double _a = 0;
	double _h = 0;
public:
	Parallelogram(){}
	Parallelogram(double a, double h)
		: _a(a), _h(h) {}

	void setValueA(double a) { _a = a; }
	void setValueH(double h) { _h = h; }
	double getValueA() { return _a; }
	double getValueH() { return _h; }

	virtual void area() override
	{
		std::cout << "area of the parallelogram:	" << getValueA() * getValueH() << std::endl;
	}
};


class Circle : public Figure
{
private:
	double const _pi = 3.1415926535;
	double _radius = 0;
public:
	Circle(){}
	Circle(int radius)
		: _radius(radius) {}

	void setRad(double radius) { _radius = radius; }
	double getRad() { return _radius; }

	virtual void area() override
	{
		std::cout << "area of the circle:		" << getRad() * _pi << std::endl;
	}

};


class Rectangle: public Parallelogram
{
private:
	double _a = 0;
	double _b = 0;
public:
	Rectangle(){}

	Rectangle(double a, double h)
		: _a(a), _b(h){}

	virtual void area() override
	{
		std::cout << "area of the rectangle:		" << getValueA() * getValueH() << std::endl;
	}
};


class Square: public Parallelogram
{
private:
	double _a;
public:
	Square(){}
	Square(double a)
		: _a(a) {}

	virtual void area() override
	{
		std::cout << "area of the square:		" << getValueA() * getValueA() << std::endl;
	}
};


class Rhombus : public Parallelogram
{
private:
	double const _half = 0.5;
	double _d1 = 0;
	double _d2 = 0;
public:
	Rhombus(){}
	Rhombus(double d1, double d2)
		: _d1(d1), _d2(d2){}

	virtual void area() override
	{
		std::cout << "area of the rhombus:		" << (getValueA() * getValueH()) * _half << std::endl;
	}
};


int main()
{
	Parallelogram para(3, 9);
	Figure* fig1 = &para;
	fig1->area();

	Circle cir(6);
	Figure* fig2 = &cir;
	fig2->area();


	Rectangle rec;
	Parallelogram* fig3 = &rec;
	fig3->setValueA(7);
	fig3->setValueH(5);
	fig3->area();

	Square squ;
	Parallelogram* fig4 = &squ;
	fig4->setValueA(6);
	fig4->area();

	Rhombus rho;
	Parallelogram* fig5 = &rho;
	fig5->setValueA(4);
	fig5->setValueH(6);
	fig5->area();



	return 0;
}