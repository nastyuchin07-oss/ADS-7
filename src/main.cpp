// Copyright 2022 NNTU-CS

#include <iostream>

#include "train.h"

int main() {
    Train train;

    std::cout << "Добавляем вагоны в поезд:" << std::endl;
    train.AddCar(false);
    train.AddCar(true);
    train.AddCar(false);
    train.AddCar(true);
    train.AddCar(false);

    std::cout << "Реальная длина поезда: "
              << train.GetRealLength() << std::endl;

    int computed_length = train.GetLength();
    std::cout << "Вычисленная длина: " << computed_length << std::endl;
    std::cout << "Количество переходов: " << train.GetOpCount() << std::endl;

    if (computed_length == train.GetRealLength()) {
        std::cout << "\nАлгоритм работает корректно!" << std::endl;
    } else {
        std::cout << "\nОшибка: вычисленная длина не совпадает с реальной!"
                  << std::endl;
    }

    return 0;
}
