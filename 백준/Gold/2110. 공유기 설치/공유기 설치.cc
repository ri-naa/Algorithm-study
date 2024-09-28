#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//공유기 최대 수 찾는 코드
int calculate(int distance, vector<int> &house) {
    int cnt = 1;
    int current = house[0];

    for(int i=1; i<house.size(); i++) {
        if(current + distance <= house[i]) {
            cnt++;
            current = house[i];
        }
    }
    return cnt;
}

// upper bound 찾기
int findUpperBound(int N, int C, vector<int> &house) {
    // 총 거리
    int length = house[N-1] - house[0];

    int left = 1; int right = length;

    while(left <= right) {
        int mid = (left+right)/2;
        
        int maxCnt = calculate(mid, house);

        if(maxCnt >= C) {
            left = mid+1;
        }
        else {
            right = mid-1;
        }
    }

    return left-1;;
}

int main() {
    int N, C;
    // 집 개수, 공유기 개수
    cin >> N >> C;

    vector<int> house(N);

    for(int i=0; i<N; i++) {
        cin >> house[i];
    }

    sort(house.begin(), house.end());

    cout << findUpperBound(N, C, house);
}