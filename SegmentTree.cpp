#include <iostream>
#include <stdlib.h>
#include <cmath>
#include "test.h"

int min1(int x, int y) {
    if (x < y)
        return x;
    return y;
}

int assignTree(int *input, int left, int right, int *segmentTree, int position)
{
    if (left == right)
    {
        segmentTree[position] = input[left];
        return input[left];
    }
    int mid = (left + right) / 2;

    // recursive calls for left and right subtree
    segmentTree[position] = min1(assignTree(input, left, mid, segmentTree, position * 2 +1), assignTree(input, mid + 1, right, segmentTree, position * 2 + 2));
    return segmentTree[position];
}
int findMin(int *segmentTree, int left, int right, int x, int y, int position)
{
    // total overlap
    if (x <= left && y >= right)
        return segmentTree[position];
 
    // no overlap
    if (right < x || left > y)
        return INT32_MAX;
 
    int mid = (left + right) / 2;
    return min1(findMin(segmentTree, left, mid, x, y, 2 * position + 1), findMin(segmentTree, mid + 1, right, x, y, 2 * position + 2));
}
int RMQ_SegmentTree(int *segmentTree, int n, int x, int y)
{
    // error
    if (x < 0 || y > n-1 || x > y)
    {
        std::cout<<"Invalid Input";
        return -1;
    }
 
    return findMin(segmentTree, 0, n-1, x, y, 0);
}
int *buildTree(int *input, int n)
{
    // Allocate memory for segment tree
 
    // Height of segment tree
    int x = (int)(ceil(log2(n)));
 
    // Maximum size of segment tree
    int max_size = 2*(int)pow(2, x) - 1;
 
    int *segmentTree = (int *)calloc(max_size, sizeof(int));
 
    assignTree(input, 0, n-1, segmentTree, 0);
 
    // Return the constructed segment tree
    return segmentTree;
}
