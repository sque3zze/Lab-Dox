#ifndef LAPTOP_H
#define LAPTOP_H

#include "Computer.h"

class Laptop : public Computer {
public:
    Laptop(const char* n, double p, int h);

    void setBatteryHours(int h);

    void show() override;

private:
    int batteryHours; };

#endif
