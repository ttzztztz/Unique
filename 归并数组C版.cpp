#include<iostream>
using namespace std;
void merge(int* arr,int size1,int size2) {
	int index1 = 0, index2 = 0;
	int* temp = new int[size1+size2];
	while (index1 + index2 < size1 + size2) {
		//谁小谁先上
		if (index1 < size1 && (index2 >= size2 || arr[index1] <= arr[size1 + index2])) {
			temp[index1 + index2] = arr[index1++];
		}
		if (index2 < size2 && (index1 >= size1 || arr[index1] >= arr[size1 + index2])) {
			temp[index1 + index2] = arr[size1+index2++];
		}
	}
	//拷贝数组
	for (int i = 0; i < size1 + size2; i++) {
		arr[i] = temp[i];
	}
}
void sort(int*arr , int size) {
	if (size <= 1) return;
	int size1 = size / 2; int size2 = size - size1;
	sort(arr, size1);
	sort(arr,size2);
	merge(arr,size1,size2);
}
int main() {
	int arr[] = { 4,5,1,2,8,9,6,21 };
	int len = sizeof(arr) / sizeof(int);
	sort(arr,len);

	for (int i : arr) cout << i<<endl;

	return 0;
}