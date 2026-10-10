#include "Computer.h"
#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std;

Computer::Computer() : price(0) {
    strcpy(name, "Noname");
}

double Computer::getPrice() {
    return price;
}

void Computer::show() {
    cout << "Название: " << name << " Цена: " << fixed << setprecision(2)
         << price << " руб." << endl;
}

void Computer::setName(const char* n) {
    strcpy(name, n);
}

void Computer::setPrice(double p) {
    price = p;
}
