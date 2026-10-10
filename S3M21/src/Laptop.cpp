/** @file Laptop.cpp
 * @brief Реализация класса Laptop.
 */
#include "Laptop.h"
#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std;

Laptop::Laptop(const char* n, double p, int h) {
    strcpy(name, n);
    price = p;
    batteryHours = h;
}

void Laptop::setBatteryHours(int h) {
    batteryHours = h;
}

void Laptop::show() {
    cout << "Ноутбук: " << name << " Цена: " << fixed << setprecision(2)
         << price << " руб. Автономность: " << batteryHours << " ч" << endl;
}
