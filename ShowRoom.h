#pragma once
#include "car.h"
#include <vector>
#include <list>
#include <memory>
#include <iostream>
#include "Filters.h"
#include "Customer.h"

class ShowRoom
{
public:
	ShowRoom();
	//~ShowRoom();
	void Help();
	void PrintCarsCatalog();
	void UseSomeFilter();
	void BuySomeCarByID();
private:
	std::vector < std ::shared_ptr<Car> > CarsCatalog;
	std::unique_ptr < IFilter> Filter = nullptr;
	Customer customer;
};



