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

    Time t1{};
    
    std::cout << "Введите время (часы минуты секунды): ";
    std::cin >> t1.hours >> t1.minutes >> t1.seconds;
    
    if (t1.hours < 0 || t1.hours > 12 || t1.minutes < 0 || t1.minutes > 59 
        || t1.seconds < 0 || t1.seconds > 59)
    {
        std::cout << "Ошибка! Некорректное время.\n";
        std::cout << "Часы >= 0, минуты и секунды от 0 до 59.\n";
        return 1;
    }
    
    long totalsecs = t1.hours * 3600L + t1.minutes * 60 + t1.seconds;
    
    std::cout << "\nВведенное время: "
              << std::setfill('0') << std::setw(2) << t1.hours << ":"
              << std::setfill('0') << std::setw(2) << t1.minutes << ":"
              << std::setfill('0') << std::setw(2) << t1.seconds << "\n";
    std::cout << "Количество секунд: " << totalsecs << "\n";
    
    return 0;
}