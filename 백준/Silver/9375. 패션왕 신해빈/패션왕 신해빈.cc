#include <bits/stdc++.h>

using namespace std;

int main() {
    int t, n;
    string key, value;
    cin >> t;

    for(int i=0; i<t; i++) {
        cin >> n;
        map<string, int> clothes;
        for(int j=0; j<n; j++) {
            cin >> value >> key;
            clothes[key] ++;
        }

        int type_num = clothes.size();
        int result = 1;
        
        // map의 begin부터 map의 end까지 탐색하기
        for(auto iter = clothes.begin(); iter != clothes.end(); iter++) {
            result *= (iter->second + 1);
        }
        result --;
        cout << result << '\n';
    }

    return 0;
}