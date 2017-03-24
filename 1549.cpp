#include <iostream>
#include <cstring>

using namespace std;
char s[105];
char r[105];
int st[100];
int top=0;

void push(int n) {
	st[top++] = n;
}

int pop() {
	return st[--top];
}

bool isEmpty() {
	return top == 0;
}

int main() {
	cin.getline(s, 105);
	int n = strlen(s);
	for (int i=0; i<n; i++) {
		if (s[i] == '(') {
			push(i);
		}
		else if (s[i] == ')') {
			if (isEmpty()) {
				r[i] = '?';
			} else {
				int tmp = pop();
				r[tmp] = r[i] = ' ';
			}
		}
		else r[i] = ' ';
	}
	while (!isEmpty()) {
		int tmp = pop();
		r[tmp] = '$';
	}
	cout<<s<<endl;
	cout<<r<<endl;
	return 0;
}