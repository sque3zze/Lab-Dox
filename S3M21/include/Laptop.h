/** @file Laptop.h
 * @brief Объявление класса ноутбука.
 */
#ifndef LAPTOP_H
#define LAPTOP_H

#include "Computer.h"

/** @class Laptop
 * @brief Ноутбук, открытый наследник Computer.
 * @details Наследует название, цену и методы getPrice(), setName(), setPrice().
 * Собственное свойство — время автономной работы. Метод show() переопределён.
 */
class Laptop : public Computer {
public:
    /** @brief Создаёт ноутбук.
     * @param n Название длиной не более 29 байт.
     * @param p Цена в рублях.
     * @param h Время автономной работы в часах.
     */
    Laptop(const char* n, double p, int h);

    /** @brief Изменяет собственное свойство — время автономной работы.
     * @param h Новое время автономной работы в часах.
     */
    void setBatteryHours(int h);

    /** @brief Выводит название, цену и автономность ноутбука.
     * @details Переопределяет виртуальную функцию Computer::show().
     */
    void show() override;

private:
    int batteryHours; /**< Собственное свойство — время автономной работы в часах. */
};

#endif
