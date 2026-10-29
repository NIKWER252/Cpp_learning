#include <iostream>
#include <windows.h>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    double vklad;
    int years;
    double percent;
    cout << "Введите начальный вклад: ";
    cin >> vklad;
    cout << "Введите число лет: ";
    cin >> years;
    cout << "Введите процентную ставку: ";
    cin >> percent;
    double stavka = percent / 100.0;
    double sum = vklad;
    for (int i = 1; i <= years; i++)
    {
        sum = sum + sum * stavka;
        cout << "В конце " << i << "-го года вы получите " << fixed << setprecision(2) << sum << "\n";
    }
    cout << "Через " << years << " лет вы получите " << fixed << setprecision(2) << sum << " долларов\n";

    return 0;
}