#include <iostream>
#include <cmath>
#include "test.h"

int min2(int x, int y) {
    if (x < y)
        return x;
    return y;
}

int max2(int x, int y) {
    if (x > y)
        return y;
    return x;
}
int mySqrt(int n) {
    int rad = 0;
    while (rad * rad <= n) {
        rad++;
    }
    rad--;
    return rad;
}

void SquareRoot(int *input, int n, int *squareBlocks) {

    // starting index in the squareBlocks
    int block_index = 1;

    // compute the size of a block
    int block_size = mySqrt(n);

    for (int i = 1; i * block_size <= n; i++) {
       int minn = INT32_MAX; 

       // search the minimum for every block
       for (int j = (i - 1) * block_size + 1; j <= block_size * i; j++) {
           if (input[j] < minn) {
               minn = input[j];
           }
       }
       squareBlocks[block_index++] = minn;
    }
}
// execute queries
int RMQ_SquareRoot(int* input, int n, int x, int y, int *squareBlocks) {

    int minn = INT32_MAX;
    int block_size = mySqrt(n);

    int left_block = x / block_size + 2;
    int left = min2(block_size * (left_block - 1), y);

    int right_block = left_block;
    while (right_block * block_size <= y) {
        minn = min2(minn, squareBlocks[right_block]);
        right_block++;
    }

    int right = max2(block_size *(right_block), x);

    for (int i = x; i <= left; i++) {
        minn = min2(minn, input[i]);
    }
    for (int i = right; i <= y; i++) {
        minn = min2(minn, input[i]);
    }
    return minn;
}
