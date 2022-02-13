#include "car.h"
#include <iostream>
#include <ctime>
int Car::Count = 0;


Car::Car() 
{
	this->color = colors::availableColors[rand() % colors::availableColors.size()];
	this->maxSpeed = rand() % 200 + 120;
	this->price = rand() % 2500 + 1000;
	this->ID = ++Count;
}


Car::Car(std::string color, int price, int maxSpeed) 
{
	this->color = color;
	this->maxSpeed = maxSpeed;
	this->price = price;
	Count++;
	this->ID = Count;
}


std::string Car::GetColor() 
{
	return this->color;
};


int Car::GetMaxSpeed()
{
	return this->maxSpeed;
};


int Car::GetPrice()
{
	return this->price;
};

int Car::GetID()
{
	return this->ID;
};

void Car::printCar() const 
{
	std::cout <<this->ID<<"\t" << this->color << "\t" << this->maxSpeed << "\t\t" << this->price << std::endl;
};

std::vector<std::string> colors::availableColors =
{
	"white",
	"black",
	"gray",
	"green",
	"yellow",
	"red",
	"blue",
	"purpule"
};