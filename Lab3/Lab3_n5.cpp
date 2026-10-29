#include <iostream>
#include <iomanip>
#include <windows.h>

struct Time
{
    int hours;
    int minutes;
    int seconds;
};

int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    
    Time t1{}, t2{}, sum{};
    char colon;
    
    std::cout << "Введите первое время (чч:мм:сс): ";
    std::cin >> t1.hours >> colon >> t1.minutes >> colon >> t1.seconds;
    
    if (t1.hours < 0 || t1.hours > 12 || t1.minutes < 0 || t1.minutes > 59 
    || t1.seconds < 0 || t1.seconds > 59)
    {
        std::cout << "Ошибка! Некорректное время.\n";
        std::cout << "Часы >= 0, минуты и секунды от 0 до 59.\n";
        return 1;
    }
    
    std::cout << "Введите второе время (чч:мм:сс): ";
    std::cin >> t2.hours >> colon >> t2.minutes >> colon >> t2.seconds;

    if (t2.hours < 0 || t2.hours > 12 || t2.minutes < 0 || t2.minutes > 59 
        || t2.seconds < 0 || t2.seconds > 59)
    {
        std::cout << "Ошибка! Некорректное время.\n";
        std::cout << "Часы >= 0, минуты и секунды от 0 до 59.\n";
        return 1;
    }

    long totalSecs = (t1.hours * 3600L + t1.minutes * 60L + t1.seconds)
                   + (t2.hours * 3600L + t2.minutes * 60L + t2.seconds);
    
    sum.hours   = static_cast<int>(totalSecs / 3600);
    sum.minutes = static_cast<int>((totalSecs % 3600) / 60);
    sum.seconds = static_cast<int>(totalSecs % 60);
    
    std::cout << "Сумма: "
              << std::setfill('0') << std::setw(2) << sum.hours << ":"
              << std::setfill('0') << std::setw(2) << sum.minutes << ":"
              << std::setfill('0') << std::setw(2) << sum.seconds << "\n";
    
    return 0;
}