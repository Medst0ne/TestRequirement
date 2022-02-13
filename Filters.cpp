#include "Filters.h"


void IFilter::PrintFilteredList()
{
	if (this->FilteredList.empty() == true)
	{
		std::cout << "Отфильтрованный список пуст! "<<std::endl;
		return;
	}
	std::cout << "Отобразить скисок? 1 - да 0 - нет " << std::endl;
	int input;
	std::cin >> input;
	if (input == 1)
	{ 
		std::cout << "ID\t цвет\t макс. скорость\t цнеа\n ";
		for (const auto& var : FilteredList)
		{
			var->printCar();
		};
	}
};

void FilterByPrice::doSomeFilter(const std::vector < std::shared_ptr<Car> >& CarsCatalog)
{
	int LowerBoundPrice;
	int UpperBoundPrice;
	std::cout << "Введите нижнюю границу цены: ";
	std::cin >> LowerBoundPrice;
	std::cout << "Введите верхнюю гранциу цены: ";
	std::cin >> UpperBoundPrice;
	for (const auto& var : CarsCatalog)
	{
		if (var->GetPrice() > LowerBoundPrice && var->GetPrice() < UpperBoundPrice) //обработать ошибки!!
		{
			this->FilteredList.emplace_back(var);
		}
	}
	this->PrintFilteredList();
};


void FilterByColor:: doSomeFilter(const std::vector < std::shared_ptr<Car> >& CarsCatalog)
{
	std::cout << "Выберете цвет для фильтрации " << std::endl;
	int i = 0;
	int chosenColor;
	for (const auto& var : colors::availableColors)
	{
		std::cout << std::endl << i << " - " << var << std::endl;;
		i++;
	};
	std::cin >> chosenColor; // обрабоать ошибку!
	for (const auto& var : CarsCatalog)
	{
		if (colors::availableColors[chosenColor] == var->GetColor())
		{
			this->FilteredList.emplace_back(var);			
		}
	}
	this->PrintFilteredList();
};



void FilterByMaxSpeed:: doSomeFilter(const std::vector < std::shared_ptr<Car> >& CarsCatalog)
{
	int minimalMaxSpeed;
	std::cout << "Введите минимальную максимальную скорость для автомобиля: " << std::endl;
	std::cin >> minimalMaxSpeed;
	for (const auto& var : CarsCatalog)
	{
		if (var->GetMaxSpeed() > minimalMaxSpeed)
		{
				this->FilteredList.emplace_back(var);
		}
	};
	this->PrintFilteredList();
};
