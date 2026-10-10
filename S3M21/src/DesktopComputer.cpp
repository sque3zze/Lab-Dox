/** @file DesktopComputer.cpp
 * @brief Реализация класса DesktopComputer.
 */
#include "DesktopComputer.h"
#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std;

DesktopComputer::DesktopComputer(const char* n, double p, const char* f) {
    strcpy(name, n);
    price = p;
    strcpy(formFactor, f);
}

void DesktopComputer::setFormFactor(const char* f) {
    strcpy(formFactor, f);
}

void DesktopComputer::show() {
    cout << "Настольный компьютер: " << name << " Цена: " << fixed
         << setprecision(2) << price << " руб. Форм-фактор: " << formFactor << endl;
}
