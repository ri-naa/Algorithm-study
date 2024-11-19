#include <string>
#include <vector>

using namespace std;

vector<int> check(200);

void dfs(int n, vector<vector<int>> computers, int current) {
    check[current] = 1;
    
    for(int i=0; i<n; i++) {
        if(computers[current][i]==1 && check[i]==0) {
            dfs(n, computers, i);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for(int i=0; i<n; i++) {
        if(check[i]==0) {
            dfs(n, computers, i);
            answer ++;
        }
    }
    
    return answer;
}