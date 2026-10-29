#include <iostream>
#include <windows.h>

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    char choice;
    char dot;

    do {
        int pounds1, shillings1, pence1;
        int pounds2, shillings2, pence2;

        std::cout << "Введите первую сумму: ";
        std::cin >> pounds1 >> dot >> shillings1 >> dot >> pence1;

        std::cout << "Введите вторую сумму: ";
        std::cin >> pounds2 >> dot >> shillings2 >> dot >> pence2;

        int totalPence     = pence1 + pence2;
        int totalShillings = shillings1 + shillings2;
        int totalPounds    = pounds1 + pounds2;

        if (totalPence >= 12) {
            totalShillings += totalPence / 12;
            totalPence     %= 12;
        }

        if (totalShillings >= 20) {
            totalPounds += totalShillings / 20;
            totalShillings %= 20;
        }

        std::cout << "Всего   £"
                  << totalPounds   << "."
                  << totalShillings << "."
                  << totalPence    << std::endl;

        std::cout << "Продолжить (y/n)? ";
        std::cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    std::cout << "Выход\n";

    return 0;
}