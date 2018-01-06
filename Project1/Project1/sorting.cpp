#include <iostream>
using namespace std;
void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = *a;
}

void selectSort(int *arr,int n) {
	
	for (int i = n-1; i >= 1; i--)
	{
		for (int j = i - 1; j >= 0; j--) {
			if (arr[i] < arr[j]) swap(arr[j], arr[i]);
		}
	}
}

void bubbleSort(int *arr, int n) {

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n-1-i; j++) {
			if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
		}
	}

}

void insertSort(int *arr, int n) {
	int temp;
	for (int i = 1; i < n; i++) {
		temp = arr[i];
		for (int j = i-1; j >= 0; j--)
		{
			if (temp < arr[j]) {
				arr[j + 1] = arr[j];	
				arr[j] = temp;
			}		
		}
	}
}



//p시작점, q 중간점, r 끝점 , 병합정렬 미완성
/*
void merge(int *arr, int p, int q, int r) {
	int i = p;
	int j = q + 1; 
	int k = p;

	int tmp[sizeof(arr) / sizeof(int)];
	cout << sizeof(arr) / sizeof(int);
	while (i <= q && j <= r) {
		if (arr[i] <= arr[j]) { tmp[k++] = arr[i++]; }
		else { tmp[k++] = arr[j++]; }
	}
	while (i <= q) { tmp[k++] = arr[i++]; }
	while (j <= r) { tmp[k++] = arr[j++]; }

	for (int i = p; i <= r; i++) arr[i] = tmp[i];
}

void mergeSort(int *arr, int p, int r) {
	int q;
	if (p < r) {
		q = (p + r) / 2;
		mergeSort(arr, p, q);
		mergeSort(arr, q + 1, r);
		merge(arr, p, q, r);
	}
}
*/


void partition(int *arr, int p, int r, int &pivot) {
	int i, j;
	int pivotItem;
	pivotItem = arr[p];
	j = p;
	for (i = p + 1; i < r; i++) {
		if (arr[i] < pivotItem)
		{
			j++;
			swap(arr[i], arr[j]);
		}
	}

	pivot = j;
	swap(arr[p], arr[pivot]);

} 
void quickSort(int *arr, int p, int r) {
	int pivot;
	if (p < r) {
		partition(arr, p, r, pivot);
		quickSort(arr, p, pivot - 1);
		quickSort(arr, pivot + 1, r);
	}
}


int main(){

	int arr[] = {1,3,5,4,2,6};
	int n = sizeof(arr) / sizeof(int);

	//insertSort(arr, n);
	//mergeSort(arr, 0, n);
	quickSort(arr, 0, n);
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " " << endl;
	}

	return 0;
}