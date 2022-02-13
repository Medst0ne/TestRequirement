#pragma once
#include <memory>
#include <string>
#include "car.h"
#include <iostream>

class Customer
{
public:
	Customer();
	~Customer();
	void ShowCurrentCar();
	void SetCurrentCar(const std::shared_ptr<Car>& NewCar);

private:
	std::string FirstName;
	std::string SecondName;
	std::shared_ptr<Car> CurrentCar;
};

