#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> parti(5, vector<int> (5));


//가로 지워졌는지 체크
int check1() {
    int result = 0;
    for(int i=0; i<5; i++) {
        if(!parti[i][0] && !parti[i][1] && !parti[i][2] && !parti[i][3] && !parti[i][4]) {
            result ++;
        }
    }
    return result;
}

//세로 지워졌는지 체크
int check2() {
    int result = 0;
    for(int i=0; i<5; i++) {
        if(!parti[0][i] && !parti[1][i] && !parti[2][i] && !parti[3][i] && !parti[4][i]) {
            result ++;
        }
    }
    return result;
}

//대각선 지워졌는지 체크
int check3() {
    int result = 0;
    if(!parti[0][0] && !parti[1][1] && !parti[2][2] && !parti[3][3] && !parti[4][4]) result ++;

    if(!parti[0][4] && !parti[1][3] && !parti[2][2] && !parti[3][1] && !parti[4][0]) result ++;

    return result;
}


int main() {
    
    for(int i=0; i<5; i++) {
        for(int j=0; j<5; j++) {
            cin >> parti[i][j];
        }
    }

    int a;
    for(int n=0; n<25; n++) {
        cin >> a;

        for(int i=0; i<5; i++) {
            for(int j=0; j<5; j++) {
                if(parti[i][j] == a) {
                    parti[i][j] = 0;
                }
            }
        }

        if(check1() + check2() + check3() >= 3) {
            cout << n+1;
            break;
        }
    }

    return 0;
}