#include <iostream>
using namespace std;

int main() {
    cout << "Contoh penggunaan break dan continue:" << endl;
    
    // Perulangan for dengan break dan continue
    for(int i = 1; i <= 10; i++) {
        // Jika i == 5, gunakan continue untuk melompati
        if(i == 5) {
            continue;  // Lompati iterasi ini
        }
        
        // Jika i == 10, gunakan break untuk menghentikan
        if(i == 10) {
            cout << i << " ";
            break;  // Hentikan perulangan
        }
        
        cout << i << " ";
    }
    
    cout << endl;
    cout << "Loop berhenti karena break" << endl;
    
    return 0;
} 