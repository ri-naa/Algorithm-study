#include <stdio.h>
#include <stdlib.h>

int** mat; //종이
int zero = 0; // 0
int one = 0; // 1


int check(int row_s, int col_s, int size) {
	int num = mat[row_s][col_s];

	for (int i = row_s; i < row_s + size; i++) {
		for (int j = col_s; j < col_s + size; j++) {
			if (mat[i][j] != num)
				return 0;
		}
	}

	return 1;
}

void divide(int row_s, int col_s, int size)
{
	if (check(row_s, col_s, size)) {
		if (mat[row_s][col_s] == 0) zero++;
		else  one++;

		return;
	}

	int newsize = size / 2;

	divide(row_s, col_s, newsize);
	divide(row_s, col_s + newsize, newsize);

	divide(row_s + newsize, col_s, newsize);
	divide(row_s + newsize, col_s + newsize, newsize);

}

int main() {
	int n;
	scanf("%d", &n);

	mat = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++) {
		mat[i] = (int*)malloc(sizeof(int) * n);
	}

	int item;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &item);
			mat[i][j] = item;
		}
	}

	divide(0, 0, n);

	printf("%d\n%d", zero, one);
}