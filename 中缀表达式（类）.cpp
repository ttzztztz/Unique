#include<iostream>
using namespace std;
//test input 
//9+(3-1)*3+6/2 & 1+(2-3)*4+10/5
class Stack {
private:
	int getPriority(char input) {
		switch (input) {
		case '*':case'/': return 1;
		case '+':case'-': return 0;
		case '(':return -1;
		case ')':return -1;
		default: return -1;
		}
	}
	void _push(char c) {
		_stack[stackLen++] = c;
	}
	void push_check(char c) {
		while (getPriority(_stack[stackLen - 1]) >= getPriority(c) && stackLen > 0) {
			pop();
		}
	}
public:int stackLen;
	   char _stack[50] ;
	   Stack() {
		   stackLen = 0;
		   memset(_stack,'\0',50);
	   }
	   ~Stack() {
		   stackLen = 0;
		   memset(_stack, '\0', 50);
	   }
	   char pop() {
		   char rtn = _stack[stackLen - 1];
		   if (_stack[stackLen - 1] != '(' && _stack[stackLen - 1] != ')')
			   cout << rtn << ' ';
		   _stack[stackLen - 1] = '\0';
		   stackLen--;
		   return rtn;
	   }

	   void push(char c) {
		   if (c == '(') {
			   _push(c);
		   }
		   else if (c == ')') {
			   int flag = 1;
			   for (int i = stackLen - 1; i >= 0 && flag; i++) {
				   char rtn = pop();
				   if (rtn == '(') flag = 0;
			   }
		   }
		   else {
			   push_check(c);
			   _push(c);
		   }
	   }
	   void pop_all() {
		   while (stackLen > 0) {
			   pop();
		   }
	   }
};
int isNumber(char input) {
	return (input >= '0'&& input <= '9');
}
int main() {
	char c = '\0';
	Stack stack;
	while ((c = getchar()) != '\n') {
		if (isNumber(c)) cout << c << ' ';
		else stack.push(c);
	}
	stack.pop_all();
	return 0;
}