#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

unsigned long ch = 0; //счетчик инверсий

void merge(long *, int , int , int);

void mergeSort(long arr[], int l, int r)
{
	if (l < r) {
		int m = l + (r - l) / 2;
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);
		merge(arr, l, m, r);
	}
}

void merge(long arr[], int l, int m, int r) {
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;
	vector <long> L(n1), R(n2);
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];
	i = 0; // Начальный индекс первого подмассива
	j = 0; // Начальный индекс второго подмассива
	k = l; // Начальный индекс отсортированного подмассива
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			ch += n1 - i; //добавляем пары, которые тоже будут инверсионными в следствие возрастания подмассива
			j++;
		}
		k++;
	}
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}
	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}

void printArray(long A[], int size) {
	int i;
	for (i = 0; i < size; i++)
		cout << A[i] << " ";
	cout << endl;
}


int main()
{
	int n;
	cin >> n;
		 long *arr =new long [n];
		 for (int i = 0; i < n; i++) cin >> arr[i];
		cout << "befor" << endl;
		printArray(arr, n);
		mergeSort(arr, 0, n - 1);
		cout << "after" << endl;
		printArray(arr, n);
		cout << endl;
		cout <<"number of inversion:"<< ch<< endl;
    return 0;
}

