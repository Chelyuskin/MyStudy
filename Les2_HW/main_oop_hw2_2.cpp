#include <iostream>

class Fruit
{
private:
	std::string _name;
	std::string _color;
public:
    Fruit(std::string name = "", std::string color = "")
        : _name(name), _color(color) {}

    std::string getName() const { return _name; }
    std::string getColor() const { return _color; }
};

class Apple : public Fruit
{
public:
    Apple(std::string name, std::string color)
        : Fruit(name, color) {}
};

class Banana : public Fruit
{
public:
    Banana(std::string name = "banana", std::string color = "yellow")
        : Fruit(name, color) {}
};

class GrannySmith : public Apple
{
public:
    GrannySmith(std::string name = "Granny Smith apple", std::string color = "green")
        : Apple(name, color) {}
};


int main()
{
    Apple a("apple", "red");
    Banana b;
    GrannySmith c;

    std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
    std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
    std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

    return 0;
}