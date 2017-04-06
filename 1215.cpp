#include <iostream>
using namespace std;
int heap[20010];
int n, tmp_number, size = 1;
char command[10];

void swap(int &a, int &b){
    int tmp = a;
    a = b;
    b = tmp;
}

int main(){
    cin>>n;
    for(int i = 1; i <= n; ++i){
        cin>>command;
        if(command[0] == 'i'){
            cin>>tmp_number;
            heap[size++] = tmp_number;
            for(int i = size - 1; i > 1 && heap[i>>1] > heap[i]; i >>= 1)
                swap(heap[i], heap[i>>1]);
        }
        else if(command[0] == 'm')
            cout<<heap[1]<<endl;
        else{
            heap[1] = heap[--size];
            for(int i = 1, j = 2; j < size; i = j, j = i << 1){
                if(j + 1 < size && heap[j+1] < heap[j])
                    j++;
                if(heap[i] > heap[j])
                    swap(heap[i], heap[j]);
                else
                    break;
            }
        }
    }
    return 0;
}