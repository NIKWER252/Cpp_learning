#include <iostream>
#include <windows.h>

using namespace std;

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    int number;

    do {
        cout << "Введите число (0 для выхода): ";
        
        if (!(cin >> number)) {
            break;
        }
        
        if (number == 0) {
            break;
        }
        
        if (number < 0) {
            cout << "Факториал отрицательного числа не определён.\n\n";
            continue;
        }
        
        unsigned long long factorial = 1;
        for (int i = 2; i <= number; i++) {
            factorial *= i;
        }
        cout << number << "! = " << factorial << "\n\n";
        
    } while (true);

    cout << "Выход\n";
    return 0;
}