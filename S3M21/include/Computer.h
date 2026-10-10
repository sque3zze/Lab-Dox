/** @file Computer.h
 * @brief Объявление базового класса Computer.
 */
#ifndef COMPUTER_H
#define COMPUTER_H

/** @class Computer
 * @brief Компьютер: название и цена.
 * @details Базовый класс для DesktopComputer и Laptop.
 * getPrice(), setName() и setPrice() наследуются без переопределения.
 * Виртуальная функция show() переопределяется в классах-наследниках.
 */
class Computer {
public:
    /** @brief Создаёт компьютер с названием Noname и нулевой ценой. */
    Computer();

    /** @brief Возвращает цену компьютера.
     * @return Цена в рублях.
     */
    double getPrice();

    /** @brief Виртуальная функция вывода общих свойств компьютера.
     * @details При вызове через Computer* используется реализация наследника.
     */
    virtual void show();

    /** @brief Изменяет название компьютера.
     * @param n Новое название длиной не более 29 байт.
     */
    void setName(const char* n);

    /** @brief Изменяет цену компьютера.
     * @param p Новая цена в рублях.
     */
    void setPrice(double p);

protected:
    char name[30]; /**< Название компьютера. */
    double price; /**< Цена компьютера в рублях. */
};

#endif
