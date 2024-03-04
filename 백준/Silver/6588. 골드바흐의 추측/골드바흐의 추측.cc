#include <iostream>
#include <cmath>
using namespace std;

bool arr[1000000];
void findPrime() {

	arr[0] = true;
	arr[1] = true;

	for (int i = 2; i < sqrt(1000000); i++) {
		if (arr[i]) continue;

		for (int j = i + i; j < 1000000; j += i) {
			arr[j] = true;
		}
	}
}

int main() {

	//입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	findPrime();

	while (1) {
		int num;
		cin >> num;
		if (num == 0) break;

		for (int i = 3; i < 1000000; i += 2) {
			if (num - i <= 0) {
				cout << "Goldbach's conjecture is wrong." << '\n';
				break;
			}
			else if (!arr[i] && !(arr[num - i])) {
				cout << num << " = " << i << " + " << (num - i) << '\n';
				break;
			}
		}
	}
}