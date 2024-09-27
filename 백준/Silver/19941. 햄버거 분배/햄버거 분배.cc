#include <bits/stdc++.h>

using namespace std;

int solution(vector<char> &hamburger, int n, int k) {

    int result = 0;

    for(int i=0; i<n; i++) {
        // 사람이면
        if(hamburger[i] == 'P') {
            int begin = i-k;
            int end = i+k;
            // begin, end가 0, n-1 넘어가면 0, n-1로 설정해주기
            if(begin < 0) begin = 0;
            if(end > n-1) end = n-1;
            for(int j=begin; j<=end; j++) {
                if(hamburger[j] == 'H') {
                    hamburger[j] = 'N';
                    result ++;
                    break;
                }  
            }
        }
    }

    return result;

}

int main() {
    int n, k;

    cin >> n >> k;

    vector<char> hamburger(n);
    for(int i=0; i<n; i++) {
        cin >> hamburger[i];
    }

    cout << solution(hamburger, n, k);

    return 0;
}