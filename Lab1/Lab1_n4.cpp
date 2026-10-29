#include <iostream>
#include <iomanip>
#include <windows.h>

int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    int pounds;
    int shillings;
    int pennies;
    std::cout << "Введите количество фунтов\n";
    std::cin >> pounds;
    std::cout << "Введите количество шиллингов\n";
    std::cin >> shillings;
    std::cout << "Введите количество пенсов\n";
    std::cin >> pennies;
    double decpennies = ((pounds * 20 * 12) + (shillings * 12) + pennies) / 240.0;
    std::string letter = u8"£";
    std::cout << "Десятичных фунтов: \n" << letter << std::fixed << std::setprecision(2) << decpennies << "\n";
    return 0;
}