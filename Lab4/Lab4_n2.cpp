#include <iostream>
#include <iomanip>
#include <windows.h>

struct Time
{
    int hours;
    int minutes;
    int seconds;
};

long time_to_secs(const Time& t)
{
    return static_cast<long>(t.hours) * 3600 + t.minutes * 60 + t.seconds;
}

Time secs_to_time(long totalSecs)
{
    Time t;
    t.hours   = static_cast<int>(totalSecs / 3600);
    t.minutes = static_cast<int>((totalSecs % 3600) / 60);
    t.seconds = static_cast<int>(totalSecs % 60);
    return t;
}

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

int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    Time t1 = read_time("Введите первое время (чч:мм:сс): ");
    Time t2 = read_time("Введите второе время (чч:мм:сс): ");

    long totalSecs = time_to_secs(t1) + time_to_secs(t2);
    Time sum = secs_to_time(totalSecs);

    std::cout << "Сумма: "
              << std::setfill('0') << std::setw(2) << sum.hours << ":"
              << std::setfill('0') << std::setw(2) << sum.minutes << ":"
              << std::setfill('0') << std::setw(2) << sum.seconds << "\n";

    return 0;
}