#include <iostream>
#include <windows.h>
#include <cstdlib>

int gcd(int a, int b) 
{
    a = std::abs(a);
    b = std::abs(b);
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    char slash;
    int a{};
    int b{};
    int c{};
    int d{};
    std::cout << "Введите первую дробь\n";
    std::cin >> a >> slash >> b;
    std::cout << "Введите вторую дробь\n";
    std::cin >> c >> slash >> d;
    if (b == 0 || d == 0)
    {
        std::cout << "На ноль делить нельзя!" << "\n";
    }
    else
    {
        int numer = a * d + c * b;
        int denom = b * d;
        int g = gcd(numer, denom);
        numer /= g;
        denom /= g;
        if (numer > denom)
        {
            std::cout << "Сумма равна: " << numer / denom << " " << numer % denom << "/" << denom << "\n";
        }
        else
        {
            std::cout << "Сумма равна: " << numer << "/" << denom << "\n";
        }
    }
    return 0;
}