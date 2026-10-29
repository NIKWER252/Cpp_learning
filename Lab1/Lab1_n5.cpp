#include <iostream>
#include <cmath>
#include <windows.h>

int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    double decimalPounds;
    
    std::cout << "Введите число десятичных фунтов: ";
    std::cin >> decimalPounds;
    long totalPence = std::round(decimalPounds * 240);
    int pounds = totalPence / 240.00;
    int remainderPence = totalPence % 240;
    int shillings = remainderPence / 12;
    int pence = remainderPence % 12;
    std::cout << "Эквивалентная сумма в старой форме записи: £" << pounds << "." << shillings << "." << pence << "\n";
    
    return 0;
}