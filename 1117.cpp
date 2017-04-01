#include <cstdio>
 
using namespace std;

int father[100000];
int degree[100000];
 
int leaves[100000];
int num=0;
 
int stack[100000];
int sp=0;
 
void push(int x) {stack[sp++] = x;}
int pop() {return stack[--sp];}
int top() {return stack[sp-1];}
 
int main() {
	char tmp; int count = 1;
	int tmp_number, brackets=1;
	scanf(" %c%d", &tmp, &tmp_number);
	push(tmp_number);
	while(brackets) {
		scanf(" %c", &tmp);
		if (tmp == '(') {
			scanf("%d", &tmp_number);
			count++;
			father[tmp_number] = top();
			degree[tmp_number] = 1;
			degree[top()]++;
			push(tmp_number);
			brackets++;
		}
		else {
			pop();
			brackets--;
		}
	}

	for (int i=1; i<=count; ++i) {
		int node = i; int linked_node;
		while (degree[node] == 1 && node <= i) {
			degree[node]--;
			if (father[node] && degree[father[node]] > 0) {
				linked_node = father[node];
			}
			else {
				for (int j=1; j<=count; ++j) if (father[j] == node && degree[j] > 0) {
					linked_node = j;
					break;
				}
			}
			printf("%d ", linked_node);
			degree[linked_node]--;
			node = linked_node;
		}
	}
	return 0;
}