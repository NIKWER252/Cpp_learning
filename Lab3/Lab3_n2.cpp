#include <iostream>
#include <windows.h>

using namespace std;

enum etype { laborer, secretary, manager, accountant, executive, researcher };

int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    etype position;
    char first_letter;
    bool correct = true;
    
    cout << "Введите первую букву должности" << endl;
    cout << "(laborer, secretary, manager, accountant, executive, researcher): ";
    cin >> first_letter;
    first_letter = tolower(first_letter);
    
    switch(first_letter)
    {
        case 'l': position = laborer;
            break;
        case 's': position = secretary;
            break;
        case 'm': position = manager; 
            break;
        case 'a': position = accountant; 
            break;
        case 'e': position = executive; 
            break;
        case 'r': position = researcher; 
            break;
        default:
            cout << "Неверная буква!" << endl;
            correct = false;
    }
    
    if (correct)
    {
        cout << "Полное название должности: ";
        switch(position)
        {
            case laborer:    cout << "laborer"; break;
            case secretary:  cout << "secretary"; break;
            case manager:    cout << "manager"; break;
            case accountant: cout << "accountant"; break;
            case executive:  cout << "executive"; break;
            case researcher: cout << "researcher"; break;
        }
        cout << endl;
    }
    
    return 0;
}