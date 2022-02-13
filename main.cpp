#include <iostream>
#include "car.h"
#include "Customer.h"
#include "Filters.h"
#include "ShowRoom.h"
#include <Windows.h>

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::srand(time(NULL));
    ShowRoom Test = ShowRoom();
    Test.Help();
}

