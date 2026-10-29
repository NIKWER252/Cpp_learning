#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <windows.h>

using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct employee
{
    int number;
    float salary;
};

enum etype { laborer, secretary, manager, accountant, executive, researcher };

struct fraction
{
    int numerator;
    int denominator;
};

struct Time
{
    int hours;
    int minutes;
    int seconds;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void task1()
{
    const int employee_amount = 3;
    employee employees[employee_amount];
    
    for (int i = 0; i < employee_amount; i++) 
    {
            cout << "Введите данные для сотрудника " << i + 1 << ":" << endl;
            cout << "Номер сотрудника: ";
            cin >> employees[i].number;
            cout << "Зарплата (в рублях): ";
            cin >> employees[i].salary;
            cout << endl;
            if (((i > 0) and (employees[i].number == employees[i-1].number)) || ((i > 1) and (employees[i].number == employees[i-2].number)))
            {
                cout << "Номера не могут совпадать" << endl;
                i --;
            }
            if (employees[i].salary < 0)
            {
                cout << "Зарплата не может быть ниже нуля" << endl;
                i --;
            }
    }
    
    cout << "Информация о сотрудниках" << endl;
    for (int i = 0; i < employee_amount; i++) {
        cout << "Сотрудник " << i + 1 << ":" << endl;
        cout << "  Номер: " << employees[i].number << endl;
        cout << "  Зарплата: " << employees[i].salary << " руб." << endl;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void task2()
{
    etype position;
    char first_letter;
    bool correct = true;

    cout << "Введите первую букву должности" << endl;
    cout << "(laborer, secretary, manager, accountant, executive, researcher): ";
    cin >> first_letter;
    first_letter = tolower(first_letter);

    switch (first_letter)
    {
        case 'l': position = laborer;    break;
        case 's': position = secretary;  break;
        case 'm': position = manager;    break;
        case 'a': position = accountant; break;
        case 'e': position = executive;  break;
        case 'r': position = researcher; break;
        default:
            cout << "Неверная буква!" << endl;
            correct = false;
    }

    if (correct)
    {
        cout << "Полное название должности: ";
        switch (position)
        {
            case laborer:    cout << "laborer";    break;
            case secretary:  cout << "secretary";  break;
            case manager:    cout << "manager";    break;
            case accountant: cout << "accountant"; break;
            case executive:  cout << "executive";  break;
            case researcher: cout << "researcher"; break;
        }
        cout << endl;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void task3()
{
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
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void task4a()
{
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
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void task4b()
{
    Time t1{};

    std::cout << "Введите время (часы минуты секунды): ";
    std::cin >> t1.hours >> t1.minutes >> t1.seconds;

    if (t1.hours < 0 || t1.minutes < 0 || t1.minutes > 59
        || t1.seconds < 0 || t1.seconds > 59)
    {
        std::cout << "Ошибка! Некорректное время.\n";
        std::cout << "Часы >= 0, минуты и секунды от 0 до 59.\n";
        return;
    }

    long totalsecs = t1.hours * 3600L + t1.minutes * 60 + t1.seconds;

    std::cout << "\nВведенное время: "
              << std::setfill('0') << std::setw(2) << t1.hours << ":"
              << std::setfill('0') << std::setw(2) << t1.minutes << ":"
              << std::setfill('0') << std::setw(2) << t1.seconds << "\n";
    std::cout << "Количество секунд: " << totalsecs << "\n";
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void task5()
{
    Time t1{}, t2{}, sum{};
    char colon;

    std::cout << "Введите первое время (чч:мм:сс): ";
    std::cin >> t1.hours >> colon >> t1.minutes >> colon >> t1.seconds;

    if (t1.hours < 0 || t1.hours > 12 || t1.minutes < 0 || t1.minutes > 59
        || t1.seconds < 0 || t1.seconds > 59)
    {
        std::cout << "Ошибка! Некорректное время.\n";
        std::cout << "Часы >= 0, минуты и секунды от 0 до 59.\n";
        return;
    }

    std::cout << "Введите второе время (чч:мм:сс): ";
    std::cin >> t2.hours >> colon >> t2.minutes >> colon >> t2.seconds;

    if (t2.hours < 0 || t2.hours > 12 || t2.minutes < 0 || t2.minutes > 59
        || t2.seconds < 0 || t2.seconds > 59)
    {
        std::cout << "Ошибка! Некорректное время.\n";
        std::cout << "Часы >= 0, минуты и секунды от 0 до 59.\n";
        return;
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
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    int choice;

    cout << "Выберите задание (1-5): ";
    cin >> choice;
    cout << endl;

    switch (choice)
    {
        case 1: task1();  break;
        case 2: task2();  break;
        case 3: task3();  break;
        case 4: 
            int choice_4;
            cin >> choice_4;
            switch (choice_4)
            {
                case 1: task4a();  break;
                case 2: task4b();  break;
                default: cout << "Неверный номер задания!\n";
            }
        break;
        case 5: task5();  break;
        default: cout << "Неверный номер задания!\n";
    }

    return 0;
}