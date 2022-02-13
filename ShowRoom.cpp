#include "ShowRoom.h"

ShowRoom::ShowRoom() 
{
	int CatalogSize = rand() % 9 + 1 ;
	for (int i = 0; i < CatalogSize; i++)
	{ 
		this->CarsCatalog.emplace_back(std::make_shared<Car>());
	}
};

void ShowRoom::PrintCarsCatalog()
{
	std::cout << "ID\t цвет\t макс. скорость\t цена\n";
	for (const auto& iter : CarsCatalog)
	{
		iter->printCar();
	};
};

void ShowRoom::UseSomeFilter()
{
	int ChosenFilter;
	std::cout << "Выберете фильтр: \n 1 - фильтр по цвету \n 2 - фильтр по цене \n 3 - фильтр по по максимальной скорости" << std::endl;
	std::cin >> ChosenFilter;
	switch (ChosenFilter)
	{
		case 1:
			this->Filter = std::make_unique<FilterByColor>();
			break;
		case 2:
			this->Filter = std::make_unique<FilterByPrice>();
			break;
		case 3:
			this->Filter = std::make_unique<FilterByMaxSpeed>();
			break;
		default:
			std::cout << "Неизвестный выбор!";
			UseSomeFilter();
	}
	Filter->doSomeFilter(this->CarsCatalog);
};


void ShowRoom::BuySomeCarByID()
{
	int carID;
	std::cout << "Введите ID машины которую хотите купить: ";
	std::cin >> carID;
	
	auto carToBuy = std::find_if(this->CarsCatalog.begin(), this->CarsCatalog.end(), [carID](std::shared_ptr<Car> car) { return (*car).GetID() == carID; } );

	this->customer.SetCurrentCar(*carToBuy);
	auto carToDeleteOnFilterList = std::find(this->Filter->FilteredList.begin(), this->Filter->FilteredList.end(), *carToBuy);
	if ( carToDeleteOnFilterList!= this->Filter->FilteredList.end())
	{
		this->Filter->FilteredList.erase(carToDeleteOnFilterList);
	};
	this->CarsCatalog.erase(carToBuy);
	
};






void ShowRoom::Help()
{
	std::cout << "\nДоступные команды:\n 1 - отобразить список авто \n 2 - использовать фильтр \n 3 - отобразить отфильтрованный список \n 4 - отобразить каким автомобилем владеет покапатель \n 5 - купить определенный автомобиль \n 0 - выйти из программы ";
	int comandNumber;
	std::cin >> comandNumber;
	switch (comandNumber)
	{
	case(0):
		std::exit(0);	
		break;
	
	case(1):
		this->PrintCarsCatalog();
		break;

	case(2):
		this->UseSomeFilter();
		break;

	case(3):
		this->Filter->PrintFilteredList();
		break;

	case(4):
		this->customer.ShowCurrentCar();
		break;

	case(5):
		this->BuySomeCarByID();
		break;

	default:
		std::cout << "Неверный ввод!";
	}
	Help();
};