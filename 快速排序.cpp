#include<iostream>
using namespace std;
void sort(int* arr,int len) {
	if (len <= 1) return;
	int selected = arr[0];
	int i = 0, j = len - 1;
	while (i < j) {
		while (arr[j] > selected&& j>0 && i<j) j--;
		if (arr[j] <= selected && i<j) {//НЪїУ
			arr[i++] = arr[j];
		}
		while (i<j && arr[i]<selected) i++;
		if (arr[i] >= selected && i < j) {//МоїУ
			arr[j--] = arr[i];
		}
		if (i == j) {
			arr[i] = selected;
		}
	}
	if (i == j) {
		sort(arr, i);
		sort(arr + i + 1, len - 1 - i);
	}
}
int main() {
	int arr[] = { 4,5,1,2,9,666,8,6,21 };
	int len = sizeof(arr) / sizeof(int);
	sort(arr,len);

	for (int _i : arr) cout << _i << endl;
	return 0;
}