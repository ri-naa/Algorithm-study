#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1048576
int sorted[MAX_SIZE];
int cnt = 0;

void merge(int list[], int left, int mid, int right)
{
	int i=left; //i는 정렬된 왼쪽 리스트 인덱스
	int j=mid+1; //j는 정렬된 오른쪽 리스트 인덱스
	int k=left; //k는 정렬된 리스트 인덱스

	//분할 정렬된 list 합병하기
	while (i <= mid && j <= right) {
		if (list[i] <= list[j]) 
			sorted[k++] = list[i++];
		else 
			sorted[k++] = list[j++];
	}

	//남아있는 애들 일괄 복사
	if (i > mid)
		for (int l = j; l <= right; l++)
			sorted[k++] = list[l];
	else
		for (int l = i; l <= mid; l++)
			sorted[k++] = list[l];

	//sorted된 애들 list에 다시 집어 넣기
	for (int l = left; l <= right; l++)
		list[l] = sorted[l];
}

void merge_sort(int list[], int left, int right) {
	int mid;
	if (left < right) {
		mid = (left + right) / 2; //리스트 균등 분할
		merge_sort(list, left, mid); //부분 리스트 정렬
		merge_sort(list, mid + 1, right); //부분 리스트 정렬
		merge(list, left, mid, right); //합병
	}
}

int main() {
	int n;
	scanf("%d", &n);

	int* list;
	list = (int*)malloc(sizeof(int) * n);

	int a;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		list[i] = a;
	}
	int person;
	scanf("%d", &person);
	int size = n / person;

	for (int i = 0; i < person; i++) {
		merge_sort(list, i * size, (i + 1) * size - 1);
	}

	for (int i = 0; i < n; i++) {
		printf("%d ", list[i]);
	}
	free(list);
}