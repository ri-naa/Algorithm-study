#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    
    int answer = 0;

    for(int i=0; i<moves.size(); i++) {
        moves[i] -= 1;
    }

    stack<int> s;
    
    for(int i=0; i<moves.size(); i++) {
        // moves[i] 지금 가야되는 위치
        for(int j=0; j<board.size(); j++) {
            // board[j][moves[i]] 0이면 넘어가기 

            if(board[j][moves[i]] != 0) { //0이 아닐경우
                
                // 빼내는 애랑 스택 top이랑 애랑 같을 경우
                if(!s.empty() && board[j][moves[i]] == s.top()) { 
                    s.pop(); // top 빼기
                    answer += 2;
                }
                // 다를 경우 그냥 push
                else {
                    s.push(board[j][moves[i]]);
                }

                board[j][moves[i]] = 0; // 초기화
                break;
            }
        }

    }

    return answer;
}