#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> m;
    int size = clothes.size();
    for (int i = 0; i < size; i++){
        m[clothes[i][1]]++;
    }

    for (auto iter = m.begin(); iter != m.end() ; iter++)
        answer *= iter->second+1;
    --answer;
    
    return answer;
}
