#include <iostream>
using namespace std;
 
int h[1000000];
 
int stack[1000000];
int esp = 0;
void push(int x) {stack[esp++] = x;}
int pop() {return stack[--esp];}
int top() {return stack[esp-1];} 
 
int main() {
	int n;
	cin>>n;
 
	h[0] = -2;
	for (int i=1; i<=n; i++) cin>>h[i];
 
	long long area = 0;
	for (int i=0; i<=n; ++i) {
		if (esp == 0) push(i);
		else {
			if (h[top()] < h[i]) push(i);
			else if (h[top()] == h[i]) continue;
			else {
				while (esp > 0 && h[top()] > h[i]) {
					int t = pop();
					long long tmp = h[t] * (i - top() - 1);
					area = tmp > area ? tmp : area;
				}
				push(i);
			}
		}
	}

	// while (top() > 0) {
	// 	int t = pop();
	// 	area = max(area, (long long) h[t] * (n - top()));
	// }

	cout<<area<<endl;
	return 0;
}