#include<iostream>
using namespace std;
int lst[] = {12,32,11,8,1,7,5,26};
//make big top heap
void swap(int& a , int &b) {
	int t = a;
	a = b;
	b = t;
}
void makeHeap(int* arr , int len) {
	for (int i = (len - 2) / 2; i >= 0; i--) {
		int index_child1 = i * 2 + 1, index_child2 = i * 2 + 2;
		int child1 = arr[index_child1], child2 = arr[index_child2];
		if (child1 <= arr[i] && child2 <= arr[i]) continue;
		if (child1 > arr[i]&& child1>child2) swap(arr[i],arr[index_child1]);
		else swap(arr[i],arr[index_child2]);
	}
}
void remakeHeap(int* arr ,int len) {
	for (int i = 1; i < len; i = 2*i+1) {
		int parent_index = (i - 1) / 2; 
		if (i + 1 < len && arr[i] < arr[i + 1]) i++;
		if ( arr[i] > arr[parent_index]) swap(arr[i],arr[parent_index]);
		else break;
	}
}
void sortHeap(int* arr , int len) {
	for (int i = 0; i < len; i++) {
		if (i != 0) remakeHeap(arr , len -i -1);
		swap(arr[0],arr[len-i-1]);
	}
}
int main() {
	int len = sizeof(lst) / sizeof(int);
	makeHeap(lst , len);
	sortHeap(lst,len);
	for (int _i : lst) cout << _i << endl;
	return 0;
}