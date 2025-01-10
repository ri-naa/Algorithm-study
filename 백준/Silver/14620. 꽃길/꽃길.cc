#include <iostream>
#include <vector>

using namespace std;

const int MAX = 200 * 15;

int getScore(int r, int c, vector<vector<int>> gr) {
	return gr[r - 1][c] + gr[r][c - 1] + gr[r + 1][c] + gr[r][c + 1] + gr[r][c];
}

int solution(int n, vector<vector<int>> gr) {
	int answer = MAX;
	int r1, c1, r2, c2, r3, c3;
    
    n -= 2; 
    
	for (int i = 0; i < n * n; i++) {  
		r1 = i / n + 1;
		c1 = i % n + 1;
		
        for (int j = 0; j < n * n; j++) {
			r2 = j / n + 1;
			c2 = j % n + 1;
			
			if (abs(r1 - r2) + abs(c1 - c2) <= 2) { 
				continue; // 겹치는 경우 제외
			} 
			
			for (int t = 0; t < n * n; t++) {
				r3 = t / n + 1;
				c3 = t % n + 1;
				
				if (abs(r1 - r3) + abs(c1 - c3) <= 2 || abs(r2 - r3) + abs(c2 - c3) <= 2) {
					continue; // 겹치는 경우 제외 
				} 
				
				answer = min(answer, getScore(r1, c1, gr) + getScore(r2, c2, gr) + getScore(r3, c3, gr)); //합산
			}
		}
	}
	return answer;
}

int main()
{
	int n;
	vector<vector<int>> gr;
	
	cin >> n;
	gr.assign(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> gr[i][j];
		}
	}
	
	cout << solution(n, gr);
	return 0;
}