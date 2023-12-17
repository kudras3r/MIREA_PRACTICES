
#include <stdio.h>

void getArrSize(int *n) {
	int temp;
	printf("Enter the arr size > ");
	scanf("%d", &temp);
	if (temp >= 5 && temp <= 20) {
		*n = temp;
	}
	else {
		printf("Error size\n");
		getArrSize(n);
	}
}

void getArrValues(int *arr, const int size) {
	int temp;
	printf("Enter values > ");
	for (int i = 0; i < size; i++) {
        scanf("%d", &temp);
		if (temp >= - 50 && temp <= 50) {
            arr[i] = temp;
		}
	    else {
			printf("Error value!\n");
			i--;
			continue;
		}
	}
}

int taskSolve(const int *arr, const int size) {
	int count = 0;
	for (int i = 0; i < size - 1; i++) {
		if (arr[i] == arr[i + 1]) count++;
	}
    return count;
}

int main() {
    int n, result;
	const int* pn = &n;
	getArrSize(pn);
    int arr[n];
	getArrValues(arr, n);
	result = taskSolve(arr, n);
	printf("Result = %d", result);
    return 0;
}