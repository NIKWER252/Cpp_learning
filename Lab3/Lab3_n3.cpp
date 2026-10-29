#include <iostream>
#include <windows.h>
#include <cstdlib>

struct fraction
{
    int numerator;
    int denominator;
};

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
    fraction f1{};
    fraction f2{};
    fraction sum{};
    
    std::cout << "Введите первую дробь\n";
    std::cin >> f1.numerator >> slash >> f1.denominator;
    
    std::cout << "Введите вторую дробь\n";
    std::cin >> f2.numerator >> slash >> f2.denominator;
    
    if (f1.denominator == 0 || f2.denominator == 0)
    {
        std::cout << "На ноль делить нельзя!" << "\n";
    }
    else
    {
        sum.numerator = f1.numerator * f2.denominator + f2.numerator * f1.denominator;
        sum.denominator = f1.denominator * f2.denominator;
        
        int g = gcd(sum.numerator, sum.denominator);
        sum.numerator /= g;
        sum.denominator /= g;
        
        if (sum.numerator > sum.denominator)
        {
            std::cout << "Сумма равна: " << sum.numerator / sum.denominator << " " 
                      << sum.numerator % sum.denominator << "/" << sum.denominator << "\n";
        }
        else
        {
            std::cout << "Сумма равна: " << sum.numerator << "/" << sum.denominator << "\n";
        }
    }
    return 0;
}