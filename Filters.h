#pragma once
#include "car.h"
#include <vector>
#include <iostream>


class IFilter
{	
public:
	void virtual doSomeFilter(const std::vector < std::shared_ptr<Car> >& CarsCatalog) = 0;
	void PrintFilteredList();
	std::vector<std::shared_ptr<Car>> FilteredList;
};

class FilterByPrice :public IFilter
{
public:
	void  doSomeFilter(const std::vector < std::shared_ptr<Car> >& CarsCatalog) override;
};

class FilterByColor : public IFilter
{
public:
	void doSomeFilter(const std::vector < std::shared_ptr<Car> >& CarsCatalog) override;

};

class FilterByMaxSpeed : public IFilter 
{
public:
	void doSomeFilter(const std::vector < std::shared_ptr<Car> >& CarsCatalog) override;
};