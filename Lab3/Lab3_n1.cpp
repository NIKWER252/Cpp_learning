#include <iostream>
#include <windows.h>

using namespace std;

struct employee
{
    int number;
    float salary;
};

int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    
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
    return 0;
}