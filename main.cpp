#include <iostream>
#include <cstdint>
#include <cassert>
using namespace std;

class Power
{
private:
	float m_num1;
	float m_num2;

public:
	void set(float num1, float num2)
	{
		m_num1 = num1;
		m_num2 = num2;
	}
	
	void calculate()
	{
		std::cout << "Результат возведения первого числа в степень второго числа: " << "\n" << pow(m_num1, m_num2);
	}
};

class RGBA
{
private:
	std::uint8_t m_red = 0;
	std::uint8_t m_green = 0;
	std::uint8_t m_blue = 0;
	std::uint8_t m_alpha = 255;

public:
	RGBA(){}

	RGBA(std::uint8_t red, std::uint8_t green, std::uint8_t blue, std::uint8_t alpha)
	{
		std::uint8_t m_red = red;
		std::uint8_t m_green = green;
		std::uint8_t m_blue = blue;
		std::uint8_t m_alpha = alpha;
	}

	void print(std::uint8_t red, std::uint8_t green, std::uint8_t blue, std::uint8_t alpha)
	{
		std::cout << "Красный: " << red << ";\n" << 
					"Зелёный: " << green << ";\n" <<
					"Синий: " << blue << ";\n" <<
					"Альфа-канал: " << alpha << ";\n";
	}
};

class Stack
{
private:
	int m_array[10];
	int m_checkLenght = 0;

public:
	void reset()
	{
		for (int i = 0; i < 10; i++)
		{
			m_array[i] = 0;
		}
	}

	bool push(int value)
	{
		if (m_checkLenght == 10)
		{
			return false;
		}

		m_array[m_checkLenght++] = value;
		return true;
	}

	int pop()
	{
		assert(m_checkLenght > 0);
		return m_array[--m_checkLenght];
	}

	void print()
	{
		std::cout << "( ";
		for (int i = 0; i < m_checkLenght; i++)
		{
			std::cout << m_array[i] << " ";
		}
		std::cout << ")\n";
	}

};


int main()
{
	setlocale(LC_ALL, "Russian");
	
	//Задание 1
	float num1 = 0;
	float num2 = 0;
	Power power;

	std::cout << "Введите первое вещественнное число: " << endl;
	std::cin >> num1;
	std::cout << "Введите второе вещественнное число: " << endl;
	std::cin >> num2;
	power.set(num1, num2);
	power.calculate();
	std::cout << endl;

	//Задание 2
	std::uint8_t red = 0;
	std::uint8_t green = 0;
	std::uint8_t blue = 0;
	std::uint8_t alpha = 0;

	std::cout << "Введите значение красного: " << endl;
	std::cin >> red;
	std::cout << "Введите значение зеленого: " << endl;
	std::cin >> green;
	std::cout << "Введите значение синего: " << endl;
	std::cin >> blue;
	std::cout << "Введите значение альфа-канала: " << endl;
	std::cin >> alpha;

	RGBA rgba;
	RGBA(red, green, blue, alpha);
	rgba.print(red, green, blue, alpha);
	std::cout << endl;

	//Задание 3
	Stack stack;
	stack.reset();
	stack.print();

	stack.push(3);
	stack.push(7);
	stack.push(5);
	stack.print();

	stack.pop();
	stack.print();

	stack.pop();
	stack.pop();
	stack.print();


	return 0;
}