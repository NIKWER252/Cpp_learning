#include <iostream>
#include <windows.h>

using namespace std;

long hms_to_secs(int hours, int minutes, int seconds)
{
    return long(hours) * 3600 + long(minutes) * 60 + seconds;
}
int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    int hours;
    int minutes;
    int seconds;
    char check;
    do
    {
        while (true)
        {
            cout << "Введите часы: ";
            cin >> hours;
            cout << "Введите минуты: ";
            cin >> minutes;
            cout << "Введите секунды: ";
            cin >> seconds;
            if (hours < 0 || minutes < 0 || seconds < 0)
            {
                cout << "Время не может быть отрицательным" << endl;
                continue;
            }
            break;
        }
        
        if (hours < 0 || minutes < 0 || seconds < 0)
        {
            cout << "Время не может быть отрицательным" << endl;
            return 1;
        }
        cout << "В секундах: " << hms_to_secs(hours, minutes, seconds) << endl;
        cout << "Продолжить? (y/n): ";
        cin >> check;
    }
    while (check == 'y');
    return 0;
}