#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <cmath>
#include "test.h"

int min(int x, int y) {
    if (x < y)
        return x;
    return y;
}

void SparseTable(int *input, int n, int **sparse) {

    long int i, j;
    // complete the first column
    for (i = 1; i <= n; i++) {
        sparse[i][0] = input[i];
    }

    // Bit manipulation tehnique:
    // 1 << j  <=> 2 ^ j
    // 1 << (j - 1) <=> 2 ^ (j - 1)

    for (j = 1; (1 << j) <= n; j++) {
        for (i = 1; i <= n - (1 << j) + 1; i++) {
            sparse[i][j] = min(sparse[i][j - 1], sparse[i + (1 << (j - 1))][j - 1]);
        }
    }
}
int RMQ_SparseTable(int left, int right, int **sparse) {

    long int l = right - left + 1;
    long int k = log2(l);

    return min(sparse[left][k], sparse[left + l - (1<<k)][k]);
}