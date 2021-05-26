#include <iostream>

/*
Создать класс Card, описывающий карту в игре БлэкДжек. У этого класса должно быть три поля: масть, значение карты 
и положение карты (вверх лицом или рубашкой). Сделать поля масть и значение карты типом перечисления (enum). 
Положение карты - тип bool. Также в этом классе должно быть два метода:
метод Flip(), который переворачивает карту, т.е. если она была рубашкой вверх, то он ее поворачивает лицом вверх, и наоборот.
метод GetValue(), который возвращает значение карты, пока можно считать, что туз = 1.

Рубашка (shirt) — узор на обратной стороне карты.
Масть (suit) —  пики, трефы, черви и буби (spade, club, heart и diamond)
Значение карты (cardValue) — валет, дамы, короля, туз, джокер и от 1 до 9 (Jack, Queen, King, Ace, Joker).
*/

class Card
{
private:
	bool shirt = true;
	int suit  = 0;
	int cardValue = 0;
public:
	enum Suit
	{
		SPADE,
		CLUB,
		HEART,
		DIAMOND,
	};

	enum CardValue
	{
		ONE,
		ACE,
		TWO,
		THREE,
		FOUR,
		FIVE,
		SIX,
		SEVEN,
		EIGHT,
		NINE,
		JACK,
		QUEEN,
		KING,
		JOKER
	};

	void Flip()
	{
		if (shirt == true)
		{
			shirt = false;
		}
	}

	int getValue() { return ACE; }

	void printValue()
	{
		std::cout << ACE << std::endl;
	}
};

int main()
{
	Card card;
	card.getValue();
	card.printValue();
	


	return 0;
}