#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>


/*
Первое задание реализовал через добавление в файл "Students.txt" вводимых данных с клавиатуры.
Добавил проверку на открытие файла и поиск по имени студента. 
Если студент не найден можно добавить его в список. Не хватает времени разобраться со счетчиком.
Для него нужен отдельный метод, у меня он считает только первые вводимые данные count = count + 1;
*/
	class Person
	{
	private:
		std::string _name;
		int _age;
		int _weight;
	
	public:
		Person(std::string name = "", int age = 0, int weight = 0)
			: _name(name), _age(age), _weight(weight){}
	};

	class Student : public Person
	{
	private:
		int _studyDur;
		int _count;
		int _numStud;
	
	public:

		void inputData(std::string name = "", int age = 0, int weight = 0,
			int studyDur = 0, int count = 0, int numStud = 0)
		{
			std::cout << "Enter the number of students: " << std::endl;
			std::cin >> numStud;

			for (int i = 0; i < numStud; i++)
			{
				std::cout << "Enter the student's name: " << std::endl;
				std::cin >> name;
				std::cout << "Enter the student's age: " << std::endl;
				std::cin >> age;
				std::cout << "Enter the student's weight: " << std::endl;
				std::cin >> weight;
				std::cout << "Enter the student's duration of study: " << std::endl;
				std::cin >> studyDur;

				count = count + 1;
				writeFile(name, age, weight, studyDur, count, numStud);
			}
		}

		void writeFile(std::string& name, int age, int weight, int studyDur, int count, int numStud)
		{
			std::ofstream fout("Students.txt", std::ios::app);
			fout << count << "\t" << name << "\t" << age << 
							"\t" << weight << "\t" << studyDur << std::endl;


		}

		void readFile()
		{
			std::ifstream fin("Students.txt");
			if (!fin)
			{
				std::cerr << "Error! Unable to open file" << std::endl;
				exit(1);
			}

			while (fin)
			{
				std::string strInput;
				getline(fin, strInput);
				std::cout << strInput << std::endl;
			}
			findName(fin);
		}

		void findName(std::ifstream & fin)
		{
			std::ifstream finSearch("Students.txt", std::ios::in);

			std::string searchWord = "", searchCheck = "";

			std::cout << "Enter a name to search: ";
			std::cin >> searchCheck;

			while (finSearch >> searchWord)
				if (searchWord == searchCheck)
				{
					std::cout << "The name: '" << searchWord << "' was found!" << std::endl;
					system("pause");
					fin.close();
					break;
				}
				if (searchWord != searchCheck)
				{
					std::cout << "The name '" << searchCheck << "' was not found!" << std::endl;
					addNewStudent();
				}
		}

		void addNewStudent()
		{
			std::string yesOrNo = "";
			std::cout << "Add a new student? [y/n]" << std::endl;
			std::cin >> yesOrNo;

			if (yesOrNo == "y")
			{
				inputData();
			}
			else if (yesOrNo != "n" && yesOrNo != "y")
			{
				addNewStudent();
			}
		}
	};


	int main()
	{
		Student student;

		student.inputData();
		student.readFile();

		return 0;
	}