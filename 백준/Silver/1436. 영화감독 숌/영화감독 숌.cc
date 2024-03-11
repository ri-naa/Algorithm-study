#include <string>
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int num = 665;
    
    while(n) {
        num++;
        if(to_string(num).find("666") != string::npos) {
            n--;
        }
    }
    cout << num;
    return 0;
}