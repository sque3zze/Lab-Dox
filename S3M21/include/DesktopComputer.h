/** @file DesktopComputer.h
 * @brief Объявление класса настольного компьютера.
 */
#ifndef DESKTOP_COMPUTER_H
#define DESKTOP_COMPUTER_H

#include "Computer.h"

/** @class DesktopComputer
 * @brief Настольный компьютер, открытый наследник Computer.
 * @details Наследует название, цену и методы getPrice(), setName(), setPrice().
 * Собственное свойство — форм-фактор корпуса. Метод show() переопределён.
 */
class DesktopComputer : public Computer {
public:
    /** @brief Создаёт настольный компьютер.
     * @param n Название длиной не более 29 байт.
     * @param p Цена в рублях.
     * @param f Форм-фактор корпуса длиной не более 29 байт.
     */
    DesktopComputer(const char* n, double p, const char* f);

    /** @brief Изменяет собственное свойство — форм-фактор корпуса.
     * @param f Новый форм-фактор длиной не более 29 байт.
     */
    void setFormFactor(const char* f);

    /** @brief Выводит название, цену и форм-фактор настольного компьютера.
     * @details Переопределяет виртуальную функцию Computer::show().
     */
    void show() override;

private:
    char formFactor[30]; /**< Собственное свойство — форм-фактор корпуса. */
};

#endif
