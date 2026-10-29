#include <iostream>
using namespace std;

int main() {
    const int height = 20;
    
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < height - i - 1; j++) {
            cout << " ";
        }
        
        for (int j = 0; j < 2 * i + 1; j++) {
            cout << "X";
        }
        
        cout << endl;
    }
    
    return 0;
}