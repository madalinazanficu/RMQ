#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#define NMAX 100005

#define input "/home/madalina/Desktop/temaAA/in/test44.in"
#define output "/home/madalina/Desktop/temaAA/out/test44.out"

int main() {
    std::ofstream out;
    out.open(input);

    srand(time(0));
    int n = (rand() % (NMAX - 5)) + 5;
    int m = rand() % NMAX;
    out << n << " " << m << "\n";


    std::vector <int> v;
    for (int i = 1; i <= n; i++) {
        v.push_back((rand() % 10000) + 1);
    }

    for (int i = 0; i < n; i++) {
        out << v[i] << " ";
    }
    out << "\n";
    int x, y;
    for (int i = 1; i <= m; i++) {
        x = (rand() % (n - 3)) + 1;
        y = x + (rand() % (n - 1 - x));
        out << x << " " << y << "\n";
    }

    out.close();

    return 0;
}
