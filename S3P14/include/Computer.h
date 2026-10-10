#ifndef COMPUTER_H
#define COMPUTER_H

class Computer {
public:
    Computer();

    double getPrice();

    virtual void show();

    void setName(const char* n);

    void setPrice(double p);

protected:
    char name[30]; double price; };

#endif
