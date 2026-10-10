/** @file main.cpp
 * @brief Главное меню и обработка массива указателей на базовый класс.
 */
/** @mainpage S3P14. Наследование. Вариант 26
 * @brief Компьютер, настольный компьютер и ноутбук.
 *
 * Программа создаёт два настольных компьютера и два ноутбука и объединяет
 * их адреса в массив указателей на Computer. Циклическое меню позволяет
 * просматривать свойства, изменять их по номеру элемента и находить
 * самый дешёвый компьютер. Вызов show() через Computer* демонстрирует
 * виртуальную функцию и её переопределение в наследниках.
 *
 * Каждый класс объявлен и реализован в отдельной паре файлов .h/.cpp.
 */
#include "Computer.h"
#include "DesktopComputer.h"
#include "Laptop.h"
#include <iostream>
#include <limits>

#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

/** @brief Создаёт объекты и выполняет действия через циклическое меню.
 * @return 0 после завершения программы.
 * @details Пункт 1 выводит свойства всех объектов в цикле; пункт 2 изменяет
 * выбранное свойство объекта по номеру 1–4; пункт 3 находит и выводит один
 * самый дешёвый компьютер; пункт 0 завершает программу.
 */
int main() {
#ifdef _WIN32
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
#endif
    DesktopComputer d1("Dell OptiPlex", 62000, "Mini Tower");
    DesktopComputer d2("Lenovo ThinkCentre", 48000, "SFF");
    Laptop l1("ASUS Vivobook", 55000, 8);
    Laptop l2("Acer Aspire", 47000, 6);
    Computer* computers[4] = {&d1, &d2, &l1, &l2};
    int choice = 0;

    do {
        cout << "\n1 — просмотр компьютеров\n2 — изменение свойств по номеру\n"
                "3 — самый дешёвый компьютер\n0 — выход\nВыбор: ";
        if (!(cin >> choice)) { break; }

        switch (choice) {
        case 1:
            for (int i = 0; i < 4; i++) {
                cout << i + 1 << ". ";
                computers[i]->show();
            }
            break;
        case 2: {
            int number = 0;
            cout << "Номер компьютера (1–4): ";
            cin >> number;
            if (number < 1 || number > 4) { break; }
            int index = number - 1;
            int property = 0;
            cout << "1 — название; 2 — цена; 3 — собственное свойство\nСвойство: ";
            cin >> property;
            if (property == 1) {
                char n[30];
                cout << "Новое название: ";
                cin.ignore((numeric_limits<streamsize>::max)(), '\n');
                if (cin.getline(n, 30)) { computers[index]->setName(n); }
            } else if (property == 2) {
                double p = 0;
                cout << "Новая цена (руб.): ";
                if (cin >> p) { computers[index]->setPrice(p); }
            } else if (property == 3 && index < 2) {
                char f[30];
                cout << "Новый форм-фактор: ";
                cin.ignore((numeric_limits<streamsize>::max)(), '\n');
                if (cin.getline(f, 30)) {
                    static_cast<DesktopComputer*>(computers[index])->setFormFactor(f);
                }
            } else if (property == 3) {
                int h = 0;
                cout << "Автономность (ч): ";
                if (cin >> h) { static_cast<Laptop*>(computers[index])->setBatteryHours(h); }
            }
            break;
        }
        case 3: {
            int cheapest = 0;
            for (int i = 1; i < 4; i++) {
                if (computers[i]->getPrice() < computers[cheapest]->getPrice()) {
                    cheapest = i;
                }
            }
            cout << "Самый дешёвый компьютер:\n";
            computers[cheapest]->show();
            break;
        }
        }
    } while (choice != 0 && cin);

    return 0;
}
