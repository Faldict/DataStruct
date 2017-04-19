#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int n1=0, n2=0;
    int t=0;
    int time1 = 0, time2 = 0;
    int car1[20000], car2[20000];
    for (int i=0; i<n; i++) {
        int tp;
        cin>>tp;
        if(tp==0) cin>>car1[n1++];
        else cin>>car2[n2++];
    }

    int c1=0, c2=0;
    int carry = 0;
    while (c1 < n1 || c2 < n2) {
        
        // load car1
        for (;carry<8 && car1[c1] <= t && c1 < n1; carry++) {
            time1 += t - car1[c1++];
        }

        // load car2
        for (;car2[c2] <= t && carry < 10 && c2 < n2; carry++) {
            time2 += t - car2[c2++];
        }

        // too many cars
        t += 10;
        carry = 0;
    }

    float ave1 = float(time1) / float(n1);
    float ave2 = float(time2) / float(n2);
    printf("%.3f %.3f", ave1, ave2);
    return 0;    
} 