#include <iostream>
#include <windows.h>
#include <iomanip>

int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    std::cout << "Введите температуру\n";
    int temp_C{};
    std::cin >> temp_C;
    std::string degree = u8"°"; 
    float temp_F = temp_C * 9 / 5.00f + 32.00f;
    std::cout << std::fixed << std::setprecision(1) << temp_F << " " << degree << "F" << "\n";
    return 0;
}