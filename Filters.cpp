#include "Filters.h"


void IFilter::PrintFilteredList()
{
	if (this->FilteredList.empty() == true)
	{
		std::cout << "��������������� ������ ����! "<<std::endl;
		return;
	}
	std::cout << "���������� ������? 1 - �� 0 - ��� " << std::endl;
	int input;
	std::cin >> input;
	if (input == 1)
	{ 
		std::cout << "ID\t ����\t ����. ��������\t ����\n ";
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
	std::cout << "������� ������ ������� ����: ";
	std::cin >> LowerBoundPrice;
	std::cout << "������� ������� ������� ����: ";
	std::cin >> UpperBoundPrice;
	for (const auto& var : CarsCatalog)
	{
		if (var->GetPrice() > LowerBoundPrice && var->GetPrice() < UpperBoundPrice) //���������� ������!!
		{
			this->FilteredList.emplace_back(var);
		}
	}
	this->PrintFilteredList();
};


void FilterByColor:: doSomeFilter(const std::vector < std::shared_ptr<Car> >& CarsCatalog)
{
	std::cout << "�������� ���� ��� ���������� " << std::endl;
	int i = 0;
	int chosenColor;
	for (const auto& var : colors::availableColors)
	{
		std::cout << std::endl << i << " - " << var << std::endl;;
		i++;
	};
	std::cin >> chosenColor; // ��������� ������!
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
	std::cout << "������� ����������� ������������ �������� ��� ����������: " << std::endl;
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
