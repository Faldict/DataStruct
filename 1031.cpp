#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <memory.h>

using namespace std;

#define MAX_H 110
#define MIN_H 0
#define N_2 10000
int n,n__2,road[N_2],min_path[N_2][MAX_H+2];

void output(int n){
    for(int i=0;i<MAX_H+1;++i)
        if(min_path[n][i]+1)
            cout<<i<<' '<<min_path[n][i]<<'\n';
}

void init(int end){
    for(int i=0;i<n__2;++i)
        for(int j=0;j<MAX_H+1;++j)
            min_path[i][j]=-1;
    min_path[end][road[end]]=road[end];
}

int *check(int point){
    static int next[4];
    next[0]=next[1]=next[2]=next[3]=0;
    if(point+n<n__2)
        next[0]=n;
    if((point+1)%n)
        next[1]=1;
    if(point>=n)
        next[2]=-n;
    if(point%n)
        next[3]=-1;
    return(next);
}

bool insert_point(int point,int path){
    int min_h,max_h,state=0;
    for(int i=0;i<MAX_H+1;++i){
        if(min_path[path][i]+1){
            min_h=min(road[point],i);
            max_h=max(road[point],min_path[path][i]);
            if(min_path[point][min_h]+1&&max_h<min_path[point][min_h]||!(min_path[point][min_h]+1)){
                min_path[point][min_h]=max_h;
                state=1;
            }
        }
    }
    return(state);
}

void change_path(){
    int *next,state=1;
    for(int k=0;k<n&&state;++k){
        state=0;
        for(int j=n__2-1;j>0;--j){
            next=check(j);
            for(int i=0;i<4;++i)
                if(next[i])
                    if(insert_point(j+next[i],j))
                        state=1;
        }
    }
}

int min_height(int begin,int end){
    int result=MAX_H-MIN_H,state=1;
    init(end);
    change_path();
    for(int i=0;i<MAX_H+1;++i)
        if(min_path[begin][i]+1)
            result=min(result,min_path[begin][i]-i);
    return(result);
}

int main(){
    cin>>n;
    n__2=n*n;
    for(int i=0;i<n__2;++i)
        cin>>road[i];
    int min_h=min_height(0,n__2-1);
    cout<<min_h;
    return 0;
}