#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

struct t
{
	int start;
	int end;
	int len;
	t(int s,int e){
		start = s;end = e;len = e-s;
	}
	t(){
		start = 1000010;end = 1000010;
	}
};

int n;
int c=0;
t sca[1000010];

bool cmp(t a, t b){
	if (a.start == b.start)
		return a.len < b.len;
	return a.start < b.start;
}

int main()
{
	scanf("%d",&n);
	for (int i=0;i<n;i++){
		scanf("%d %d",&sca[i].start,&sca[i].end);
		sca[i].len = sca[i].end - sca[i].start;
	}
	sort(sca,sca+n+1,cmp);
	int p=0;
	int ind = 0;
	c++;
	while (p != n){
		if (sca[p].start >= sca[ind].end){
			c++;
			ind = p;
		}
		p++;
	}
	printf("%d\n",c);
	return 0;
}