#include <fstream>
#include <stdlib.h>
#include "test.h"
#include <chrono>
#include <unistd.h>
#include <iostream>

int main() {

    long int n, m;
    int *input = (int*)malloc(NMAX * sizeof(int));
    long int i;
    long int x, y;

    // input file
    std::ifstream in;
    in.open("./test.in");


    // output file
    std::ofstream out;
    out.open("./test.out");

    in >> n >> m;
    for (i = 1; i <= n; i++) {
        in >> input[i];
    }

    // SquareRoot
    int *squareBlocks = (int *)calloc(n + 2, sizeof(int));


    auto start = std::chrono::steady_clock::now();
    SquareRoot(input, n, squareBlocks);


    for (i = 1; i <= m; i++) {
        in >> x >> y;
        out << RMQ_SquareRoot(input, n, x, y, squareBlocks) << "\n";
    }
    sleep(2);
    auto end = std::chrono::steady_clock::now();
    std::cout << "Elapsed time in milliseconds: "
        << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()
        << " µs" << std::endl;

    free(input);
    free(squareBlocks);

    in.close();
    out.close();

    return 0;
}