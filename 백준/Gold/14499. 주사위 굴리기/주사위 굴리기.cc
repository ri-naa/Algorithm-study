#include <bits/stdc++.h>

using namespace std;

int N, M, x, y, K;

vector<int> dice(6, 0);
vector<vector<int>> board(20, vector<int>(20));

//주사위 움직였을 때 칸 밖으로 나가는지 확인
//나가면 false, 안나가면 true
bool move(int order) {
    int curX = x;
    int curY = y;
    if(order == 1) { //동쪽
        curY++;
    }
    else if(order == 2) { //서쪽
        curY--;
    }
    else if(order == 3) { //북쪽
        curX--;
    }
    else { //남쪽
        curX++;
    }

    if(curX < 0 || curX > N-1 || curY < 0 || curY > M-1){
        return false;
    }
    else {
        x = curX; y = curY;
        return true;
    }
}

void roll(int order) {
    vector<int> temp = dice;

    if(order == 1) { //동쪽
        dice[2] = temp[0];
        dice[5] = temp[2];
        dice[3] = temp[5];
        dice[0] = temp[3];
    }
    else if(order == 2) { //서쪽
        dice[2] = temp[5];
        dice[5] = temp[3];
        dice[3] = temp[0];
        dice[0] = temp[2];
    }
    else if(order == 3) { //북쪽
        dice[1] = temp[0];
        dice[5] = temp[1];
        dice[4] = temp[5];
        dice[0] = temp[4];
    }
    else if(order == 4) { //남쪽
        dice[1] = temp[5];
        dice[5] = temp[4];
        dice[4] = temp[0];
        dice[0] = temp[1];
    }
}

int main() {
    
    cin >> N >> M >> x >> y >> K;

    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin >> board[i][j];
        }
    }

    //명령
    int order;
    for(int i=0; i<K; i++) {
        cin >> order;

        //board 안에 들어오면 움직여서 실행
        if(move(order)) {
            roll(order);
            if(board[x][y] == 0) {
                board[x][y] = dice[5];
            }
            else {
                dice[5] = board[x][y];
                board[x][y] = 0;
            }
            cout << dice[0] << '\n';
        }
    }
    return 0;
}