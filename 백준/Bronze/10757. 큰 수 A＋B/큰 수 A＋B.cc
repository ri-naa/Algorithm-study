#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

string add(const string& str1, const string& str2) {
    string result;
    int carry = 0; //올림
    
    int length = max(str1.size(), str2.size());

    for(int i=0; i<length; i++) {
        int a = 0, b = 0, sum = 0;

        if(i<str1.size())
            a = str1[str1.size() - i - 1] - '0';
        if(i<str2.size())
            b = str2[str2.size() - i - 1] - '0';

        sum = a + b + carry;
        carry = sum/10;
        result += (sum % 10) + '0';

    }

    if(carry == 1) {
        result += '1';
    }

    reverse(result.begin(), result.end()); // 문자열 뒤집어서 반환
    return result;

}


int main() {
    string str1, str2;
    cin >> str1 >> str2;
    
    string result = add(str1, str2);
    cout << result;

}