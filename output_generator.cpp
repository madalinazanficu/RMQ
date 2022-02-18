#include <iostream>
#include <fstream>
#define NMAX 100005

#define input "/home/madalina/Desktop/temaAA/in/test44.in"
#define output "/home/madalina/Desktop/temaAA/out/test44.out"

int main() {
    // reading from pathin
    std::ifstream in;
    in.open(input);

    // write out
    std::ofstream out;
    out.open(output);

    int n, m;
    int x, y;
    in >> n >> m;
    int *v = (int *)calloc(n + 2, sizeof(int));
    for (int i = 1; i <= n; i++) {
        in >> v[i];
    }

    // brute-force to test
    for (int i = 1; i <= m; i++) {
        in >> x >> y;
        int minn = INT32_MAX;
        for (int cnt = x; cnt <= y; cnt++) {
            if (v[cnt] < minn) {
                minn = v[cnt];
            }
        }
        out << minn << "\n"; 
    }
    free(v);
    in.close();
    out.close();

    return 0;
}
