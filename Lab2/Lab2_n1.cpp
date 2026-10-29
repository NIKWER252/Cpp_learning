#include <iostream>
using namespace std;

int main() {
    const int height = 20;
    const int maxWidth = 2 * height - 1;
    
    for (int i = 0; i < height; i++) {
        int symbolsCount = 2 * i + 1;
        
        for (int j = 0; j < maxWidth - symbolsCount; j++) {
            cout << " ";
        }
        
        for (int j = 0; j < symbolsCount; j++) {
            cout << "X";
        }
        
        cout << endl;
    }
    
    return 0;
}