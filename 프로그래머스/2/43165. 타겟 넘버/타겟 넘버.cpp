#include <string>
#include <vector>

using namespace std;

int answer = 0;

void get_sum(vector<int> numbers, int target, int index, int sum) {
    if(index == numbers.size()) {
        if(sum == target) {
            answer ++;
        }
        return;
    }
    
    get_sum(numbers, target, index+1, sum + numbers[index]);
    get_sum(numbers, target, index+1, sum - numbers[index]);
}

int solution(vector<int> numbers, int target) {
    
    get_sum(numbers, target, 0, 0);
    
    return answer;
}