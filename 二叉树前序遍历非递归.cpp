#include<iostream>
using namespace std;
//     12
// 32   11
//8  1   7 5
int lst[] = {12,32,11,8,1,7,5};
int stack[10];
int len = sizeof(lst) / sizeof(int) , stackLen = 0;
int main() {
	int index = 0;
	while (stackLen > 0 || index>=0 && index<len ) {
		while (index< len) {
			cout << lst[index] << endl;
			stack[stackLen++] = index;
			index = 2 * index + 1;
		}
		index = 2* stack[stackLen-1] + 2; 
		stackLen --;
	}
	return 0;
}