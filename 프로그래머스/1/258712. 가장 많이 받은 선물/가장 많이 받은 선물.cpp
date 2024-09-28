#include <bits/stdc++.h>
 
using namespace std;
 
map<string, int> nameToIdx;
int giftArr[51][51];
map<string, int> give;
map<string, int> receive;
 
 
int solution(vector<string> friends, vector<string> gifts) {
    //초기 세팅
    int n = friends.size();
    map<string, int> gift_map;
    vector<vector<int>> gift_table(n, vector<int> (n));

    vector<int> gift_score(n, 0);
    vector<int> next_gift(n, 0);

    for(int i=0; i<n; i++) {
        gift_map[friends[i]] = i;
    }
    
    //선물지수 계산
    for(int i=0; i<gifts.size(); i++) {
        string a, b;
        stringstream ss (gifts[i]);
        ss >> a >> b;

        gift_table[gift_map[a]][gift_map[b]] ++;
        //준사람 선물지수 +1
        gift_score[gift_map[a]] ++;
        //받은사람 선물지수 -1
        gift_score[gift_map[b]] --;
    }
    
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(i != j) {
                //i가 준 선물이 더 많을 때
                if(gift_table[i][j] > gift_table[j][i]) {
                    next_gift[i] ++;
                }  
                //주고 받은 선물 개수 같으면 선물지수 비교
                else if(gift_table[i][j] == gift_table[j][i]) {
                    if(gift_score[i] > gift_score[j]) {
                        next_gift[i]++;
                    }
                }
            }
        }
    }

    //next_gift에서 가장 큰 값 찾기
    int max_gift = next_gift[0];

    for(int i=1; i<n; i++) {
        if(next_gift[i] > max_gift) {
            max_gift = next_gift[i];
        }
    }

    return max_gift;
}