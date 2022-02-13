#include "Customer.h"
Customer::Customer()
{
	std::cout << "Здравствуйте уважаемый покупатель! \n Как вас зовут?";
	std::string FirstName;
	std::string SecondName;
	std::cin >> FirstName;
	std::cin >> SecondName;
	this->FirstName = FirstName;
	this->SecondName = SecondName;
	CurrentCar = nullptr;
}

Customer::~Customer()
{
}
void Customer::ShowCurrentCar()
{
	if (this->CurrentCar != nullptr)
		this->CurrentCar->printCar();
	else
		std::cout << "У вас еще не машины :-(";

};
void Customer::SetCurrentCar(const std::shared_ptr<Car>& NewCar)
{
	this->CurrentCar = NewCar;
};