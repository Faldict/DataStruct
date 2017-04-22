#include <cstdio>
#include <iostream>

using namespace std;

int n, m, heap[200000], zero_number, heap_size, num, tmp;
long long result = 0;

void update() {
    for (int i = 1, j = 2; j < heap_size; i = j, j = i << 1) {
        if (j+1 < heap_size && heap[j+1] < heap[j]) j++;
        if (heap[j] >= heap[i]) break;
        heap[i] ^= heap[j] ^= heap[i] ^= heap[j];
    }
}

void updateAll() {
    for (int j = heap_size - 1, i = j >> 1; j > 1 && heap[i] > heap[j]; j = i, i >>= 1)
        heap[i] ^= heap[j] ^= heap[i] ^= heap[j];
}

int main() {
    scanf("%d%d", &n, &m);
    zero_number = ((m - 1) - (n - 1) % (m - 1)) % (m - 1);
    for (heap_size = 1; heap_size <= zero_number; ++heap_size) heap[heap_size] = 0;
    for (int i=0; i<n; ++i) {
        scanf("%d", &heap[heap_size++]);
        updateAll();
    }
    while(heap_size > 2) {
        num = 0;
        for (int i=0; i<m; ++i) {
            num += heap[1];
            heap[1] = heap[--heap_size];
            update();
        }
        result += num;
        heap[heap_size++] = num;
        updateAll();
    }
    cout << result << endl;
    return 0;
}