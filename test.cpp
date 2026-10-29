#include <iostream>
#include <windows.h>

using namespace std;

void pass_by_value (int a)
{ 
    a++; 
    cout<<"В функции pass_by_value a = " << a << endl;
}
void pass_by_pointer (int* a)
{
    *a +=2; 
    cout << "В функции pass_by_pointer a = " << *a << endl;
}
void pass_by_reference (int& a)
{
    a +=3;
    cout << "В функции pass_by_reference a = " << a << endl;
}
int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    int a;
    cout << "Введите перевенную <a> ";
    cin >> a; cout << "Вы ввели " << a << endl; 
    pass_by_value (a); cout << "Сейчас в функции main переменная a = " << a << endl; 
    pass_by_pointer(&a);
    cout << "Сейчас в функции main переменная a = " << a << endl;
    pass_by_reference (a); cout << "Сейчас в функции main переменная a = " << a << endl;
    return 1;
}