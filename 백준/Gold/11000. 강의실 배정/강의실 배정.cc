#include <bits/stdc++.h>

using namespace std;

//필요한 강의실 수 구하기
int classroom(vector<pair<int, int>> lec, int N) {
    
    // 오름차순으로 정렬
    priority_queue<int, vector<int>, greater<>> pq;

    pq.push(-1); // 처음 인덱스 오류 피하기 위해

    for(int i=0; i<N; i++) {
        if(pq.top() <= lec[i].first) {
            pq.pop();
        }
        pq.push(lec[i].second);
    }
    return pq.size();

}

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> lec(n, pair<int, int>(0, 0));
    for(int i=0; i<n; i++) {
        cin >> lec[i].first >> lec[i].second;
    }

    sort(lec.begin(), lec.end());

    cout << classroom(lec, n);

    return 0;

}