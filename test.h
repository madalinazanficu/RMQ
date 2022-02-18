#ifndef __TEST_H
#define __TEST_H


#define NMAX 10000005

void SparseTable(int *input, int n, int **sparse);
int RMQ_SparseTable(int low, int high, int **sparse);

int assignTree(int *input, int ss, int se, int *segmentTree, int si);

int RMQUtil(int *segmentTree, int ss, int se, int qs, int qe, int index);
int RMQ_SegmentTree(int *segmentTree, int n, int qs, int qe);
int *buildTree(int *input, int n);

void SquareRoot(int *input, int n, int *squareBlocks);
int RMQ_SquareRoot(int* input, int n, int x, int y, int *squareBlocks);

#endif