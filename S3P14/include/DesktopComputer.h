#ifndef DESKTOP_COMPUTER_H
#define DESKTOP_COMPUTER_H

#include "Computer.h"

class DesktopComputer : public Computer {
public:
    DesktopComputer(const char* n, double p, const char* f);

    void setFormFactor(const char* f);

    void show() override;

private:
    char formFactor[30]; };

#endif
