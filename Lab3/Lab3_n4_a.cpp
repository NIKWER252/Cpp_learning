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
    
    std::cout << "Введите время в формате часы, минуты, секунды:\n";
    std::cout << "Часы: ";
    std::cin >> t1.hours;
    std::cout << "Минуты: ";
    std::cin >> t1.minutes;
    std::cout << "Секунды: ";
    std::cin >> t1.seconds;
    
    long totalsecs = t1.hours * 3600 + t1.minutes * 60 + t1.seconds;
    
    std::cout << "\nВведенное время: "
              << std::setfill('0') << std::setw(2) << t1.hours << ":"
              << std::setfill('0') << std::setw(2) << t1.minutes << ":"
              << std::setfill('0') << std::setw(2) << t1.seconds << "\n";
    std::cout << "Количество секунд в введенном времени: " << totalsecs << "\n";
    
    return 0;
}