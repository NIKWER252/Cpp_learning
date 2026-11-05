#include <iostream>
#include <iomanip>
#include <windows.h>

struct Time
{
    int hours;
    int minutes;
    int seconds;
};

bool is_valid(const Time& t)
{
    return t.hours >= 0
        && t.minutes >= 0 && t.minutes <= 59
        && t.seconds >= 0 && t.seconds <= 59;
}

Time read_time(const char* prompt)
{
    Time t{};
    char colon;

    while (true)
    {
        std::cout << prompt;
        std::cin >> t.hours >> colon >> t.minutes >> colon >> t.seconds;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Ошибка! Некорректный формат.\n";
            std::cout << "Введите время в формате чч:мм:сс.\n\n";
            continue;
        }

        if (!is_valid(t))
        {
            std::cout << "Ошибка! Некорректное время.\n";
            std::cout << "Часы >= 0, минуты и секунды от 0 до 59.\n\n";
            continue;
        }

        return t;
    }
}

void swap(Time& a, Time& b)
{
    Time temp = a;
    a = b;
    b = temp;
}

void print_time(const char* label, const Time& t)
{
    std::cout << label
              << std::setfill('0') << std::setw(2) << t.hours << ":"
              << std::setfill('0') << std::setw(2) << t.minutes << ":"
              << std::setfill('0') << std::setw(2) << t.seconds << "\n";
}

int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    Time t1 = read_time("Введите первое время (чч:мм:сс): ");
    Time t2 = read_time("Введите второе время (чч:мм:сс): ");

    swap(t1, t2);

    print_time("t1 = ", t1);
    print_time("t2 = ", t2);

    return 0;
}