#include <stdio.h>
#include <math.h>

int Z(int N, int r, int c) { //N=2
	int length = (int)pow(2, N); //4
	int next = length / 2; //2

	if (N == 0) return 0;

	if (r < next && c < next) { // 0번
		return Z(N - 1, r, c);
	}
	else if (r < next && c >= next) { //1번
		return (int)pow(next, 2) * 1 + Z(N - 1, r, c-next);
	}
	else if (r >= next && c < next) { //2번
		return (int)pow(next, 2) * 2 + Z(N - 1, r-next, c);
	}
	else if (r >= next && c >= next) { //3번
		return (int)pow(next, 2) * 3 + Z(N - 1, r-next, c-next);
	}

}

int main() {
	int N, r, c;
	scanf("%d %d %d", &N, &r, &c);
	printf("%d", Z(N, r, c));
	return 0;
}