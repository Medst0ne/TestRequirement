#pragma once
#include <string>
#include <vector>

class Car
{
public:
	Car() ;
	Car(std::string color, int price, int maxSpeed);

	static int Count;

	std::string GetColor();
	int GetPrice();
	int GetMaxSpeed();
	int GetID();

	void printCar() const;


private:
	std::string color;
	int price;
	int maxSpeed;
	int ID; 
};

class colors
{
public:
	static std::vector<std::string> availableColors;
private:

};

