#include<iostream>
using namespace std;
void swap(int& a, int& b) {
	int t = a;
	a = b;
	b = t;
}
int main(){
	int arr[] = {4,5,1,2,8,9,6,21};
	int len = sizeof(arr) / sizeof(int);

	for (int i = 1; i < len; i++) {
		int selected = arr[i];
		for (int q = i-1 ; q >= 0; q--) {
				if(arr[q] > selected) swap(arr[q], arr[q+1]);
		}
	}

	for (int m = 0; m < len; m++) {
		cout << arr[m]<<endl;
	}
	return 0;
}
