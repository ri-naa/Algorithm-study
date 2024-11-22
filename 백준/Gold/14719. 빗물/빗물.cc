#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int rain(vector<int> blocks, int W) {
    int result = 0;
    
    for(int i=1; i<W-1; i++) {
        //i는 현재 위치
        int right_max = 0;
        int left_max = 0;
        //i 보다 오른쪽에서 가장 큰 값
        for(int j=i+1; j<=W-1; j++) {
            right_max = max(right_max, blocks[j]);
        }
        //i 보다 왼쪽에서 가장 큰 값
        for(int j=i-1; j>=0; j--) {
            left_max = max(left_max, blocks[j]);
        }


        // min 값이 현재 벽돌 위치 보다 크면,
        // min 값에서 현재 벽돌 위치 빼서 result에 합하기
        int rain = min(right_max, left_max) - blocks[i];
        if(rain > 0) {
            result += rain;
        }

        // result += max(0, min(right_max, left_max) - blocks[i]);
    }

    return result;
}

int main() {
    int H, W;
    cin >> H >> W;

    vector<int> blocks(W);
    for(int i=0; i<W; i++) {
        cin >> blocks[i];
    }

    cout << rain(blocks, W);

    return 0;

}