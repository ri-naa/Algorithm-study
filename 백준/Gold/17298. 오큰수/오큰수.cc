#include<iostream>
#include<vector>
#include<stack>

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    stack<int> s;
    int n;

    cin >> n;
    vector<int> arr(n);
    vector<int> result(n);

    for(int i=0; i<n; i++)
        cin >> arr[i];

    s.push(1e9+7);
    for(int i=n-1; i>=0; i--) {
        while(s.top() <= arr[i]){
            s.pop();
        }
        if (s.top() >= 1e9) result[i] = -1;
        else result[i] = s.top();
        s.push(arr[i]);
    }

    for(int i=0; i<n; i++) {
        cout << result[i] << " ";
    }

}