#include <iostream>
using namespace std;

int heap[20010] = {0x7fffffff};
int size=1;

void swap(int &a, int &b){
    int tmp = a;
    a = b;
    b = tmp;
}

void insert(int x) {
    heap[size++] = x;
    for (int i = size - 1; i > 1 && heap[i>>1] > heap[i]; i >>= 1) {
        swap(heap[i], heap[i>>1]);
    }
}

void find(int x) {
    int rst = 0;
    for (int i=1; i < size; ++i) {
        if (heap[i] > x && heap[i] < heap[rst]) rst = i;
    }
    cout<<rst<<endl;
}

void decrease(int i, int v) {
    heap[i] -= v;
    if (v >= 0) 
        for (int j=i; j>1 && heap[j>>1] > heap[j]; j>>=1) swap(heap[j], heap[j>>1]);
    else
        for (int j=i, k=i<<1; j<size; j=k, k=j<<1) {
            if (k+1 < size && heap[k+1] < heap[k]) k++;
            if (heap[j] > heap[k]) swap(heap[j], heap[k]);
            else break;
        }
}

int main() {
    int n;
    cin>>n;
    for (int j=0; j<n; ++j) {
        char command[10];
        cin>>command;
        if (command[0] == 'i') {
            int x;
            cin>>x;
            insert(x);
        }
        else if (command[0] == 'f') {
            int x;
            cin>>x;
            find(x);
        }
        else {
            int i, v;
            cin>>i>>v;
            decrease(i, v);
        }
    }
    return 0;
}