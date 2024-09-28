#include <string>
#include <vector>

using namespace std;


int backtracking(int row, int n, vector<bool>& column, vector<bool>& diagup, vector<bool>& diagdown) {  
    if(row == n) {
        return 1;
    }

    int answers = 0;
    for(int col=0; col<n; col++) {
        //퀸을 놓을 수 있으면 계속하기
        if(column[col] || diagup[row+col] || diagdown[row-col+n-1]) {
            continue;
        }

        //퀸 배치하기
        column[col] = true;
        diagup[row+col] = true;
        diagdown[row-col+n-1] = true;

        answers += backtracking(row+1, n, column, diagup, diagdown);


        //다음 탐색을 위헤 퀸 회수하기
        column[col] = false;
        diagup[row+col] = false;
        diagdown[row-col+n-1] = false;
    }

    return answers;
}
int solution(int n) {
    vector<bool> columns(n, false); // 열 체크
    vector<bool> diag_up(2 * n - 1, false); // 상향 대각선 체크
    vector<bool> diag_down(2 * n - 1, false); // 하향 대각선 체크

    return backtracking(0, n, columns, diag_up, diag_down);
}
