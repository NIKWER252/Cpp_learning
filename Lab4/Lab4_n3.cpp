#include <iostream>
#include <iomanip>
#include <windows.h>

using namespace std;
void Swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

int main()
{
    int x;
    int y;
    
    cout << "Введите x: ";
    cin >> x;
    cout << "Введите y: ";
    cin >> y;

    Swap(x, y);

    cout << "x = " << x << ", y = " << y << endl;
    return 0;
}

