#include <iostream>


class Factory
{
	virtual void print() = 0;
};

class Car : public Factory
{
private:
	std::string _company = "";
	std::string _model = "";
public:
	Car()
	{
		std::cout << "Constructor Car" << std::endl;
	}

	Car(const std::string& company, const std::string& model)
		:_company(company), _model(model){}

	void setCompany (const std::string& company) { _company = company; }
	void setModel(const std::string& model) { _model = model; }
	std::string getCompany() const { return _company; }
	std::string getModel() const { return _model; }
	
	void print() override
	{
		std::cout << "Constructor Car: " << getCompany() << " " << getModel() << std::endl;
	}

	~Car()
	{
		std::cout << "Deconstructor Car" << std::endl;
	}
};

class PassengerCar : public Car
{
private:
	std::string _company = "";
	std::string _model = "";
public:
	PassengerCar() 
	{
		std::cout << "Constructor PassengerCar" << std::endl;
	}

	PassengerCar(const std::string& company, const std::string& model)
		:_company(company), _model(model) {}

	void print() override
	{
		std::cout << "Constructor PassengerCar: " << getCompany() << " " << getModel() << std::endl;
	}

	~PassengerCar()
	{
		std::cout << "Deconstructor PassengerCar" << std::endl;
	}
};

class Bus : public Car
{
private:
	std::string _company = "";
	std::string _model = "";
public:
	Bus() 
	{
		std::cout << "Constructor Bus" << std::endl;
	}

	Bus(const std::string& company, const std::string& model)
		:_company(company), _model(model) {}

	void print() override
	{
		std::cout << "Constructor Bus: " << getCompany() << " " << getModel() << std::endl;
	}

	~Bus()
	{
		std::cout << "Deconstructor Bus" << std::endl;
	}
};

class Minivan : public PassengerCar, public Bus
{
private:
	std::string _company = "";
	std::string _model = "";
public:
	Minivan() 
	{
		std::cout << "Constructor Minivan" << std::endl;
	}

	Minivan(const std::string& company, const std::string& model)
		:_company(company), _model(model) {}

	void print() override
	{
		std::cout << "Constructor Minivan: " << PassengerCar::getCompany() << " " << PassengerCar::getModel() << std::endl;
	}

	/*
	Здесь вызвалось четыре дополнительных деструктора: 
	Deconstructor Bus
	Deconstructor Car
	Deconstructor PassengerCar
	Deconstructor Car

	При множественном наследовании мне понадобилось определить 
	из какого родительского класса вызывается функции getCompany() и getModel().
	Что может быть огромной проблемой в большом проекте, для программистов работающими с разными частями кода.
	*/
	~Minivan()
	{
		std::cout << "Deconstructor Minivan" << std::endl;
	}
};

int main()
{
	PassengerCar passCar;
	Bus bus;
	Minivan mVan;

	Car* car1 = &passCar;
	car1->setCompany("Toyota");
	car1->setModel("Corolla");
	car1->print();

	Car* car2 = &bus;
	car2->setCompany("Ikarus");
	car2->setModel("280.33");
	car2->print();

	PassengerCar* car3 = &mVan;
	car3->setCompany("Volkswagen");
	car3->setModel("Routan");
	car3->print();

	return 0;
}