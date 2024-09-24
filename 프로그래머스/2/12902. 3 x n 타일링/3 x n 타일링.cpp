#include <bits/stdc++.h>

using namespace std;

int DEVIDE = 1000000007;

int solution(int n) {
    int answer = 0;

    int num = n/2;
    int ans=3;

    for(int i=1; i<num; i++) {
        ans *= 3;
    }

    int num1 = n/4;
    int ans1=2;

    for(int i=1; i<num1; i++) {
        ans1 *= 2;
    }

    answer = (ans+ans1)%DEVIDE;
    return answer;
}
