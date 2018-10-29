#include<iostream>
using namespace std;
//test input 
//9+(3-1)*3+6/2
char stack[50];
int stackLen = 0;
int getPriority(char input) {
	switch (input) {
		case '*':case'/': return 1;
		case '+':case'-': return 0;
		case '(':return -1;
		case ')':return -1;
		default: return -1;
	}
}
int isNumber(char input) {
	return (input >= '0'&& input <= '9');
}
char outputOneStack() {
	char rtn = stack[stackLen - 1];
	if (stack[stackLen - 1] != '(' && stack[stackLen - 1] != ')')
		cout << rtn << ' ';
	stack[stackLen - 1] = '\0';
	stackLen--;
	return rtn;
}
int main() {
	char c = '\0';
	while ( (c = getchar()) != '\n') {
		if (isNumber(c)) cout << c <<' ';
		else {
			if (c == '(') {
				stack[stackLen++] = c;
			}
			else if (c == ')') {
				//stack[stackLen++] = c;
				int flag = 1;
				for (int i = stackLen - 1; i >= 0 && flag; i++) {
					char rtn = outputOneStack();
					if (rtn == '(') flag = 0;
				}
			}
			else {
				//char stack_top = c;
				while (getPriority(stack[stackLen - 1]) >= getPriority(c)  && stackLen>0) {
					outputOneStack();
				}
				stack[stackLen++] = c;
			}
		}
	}
	while (stackLen > 0) {
		outputOneStack();
	}
	return 0;
}