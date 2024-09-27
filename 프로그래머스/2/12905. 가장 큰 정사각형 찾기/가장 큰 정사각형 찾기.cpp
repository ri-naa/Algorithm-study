#include<vector>
using namespace std;


int solution(vector<vector<int>> board) {
    int n = board.size();
    int m = board[0].size();
    
    vector<vector<int>> dp(board.size() + 1, vector<int>(board[0].size() + 1));
    
    int max_length = 0;
    for(int i=1; i <= n; i++) {
        for(int j=1; j <= m; j++) {
            if(board[i-1][j-1] == 1){
                dp[i][j] = min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j])) +1;
            }
            max_length = max(dp[i][j], max_length);
        }
    }
    
    return max_length * max_length;
}