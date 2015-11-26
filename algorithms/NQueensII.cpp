class NQueensSolver {
    int n;
    int uplimit;
    int solutions;
public:
    explicit NQueensSolver(int queens) : n(queens), uplimit((1<<n)-1), solutions(0) {}

    void Solve() { d(0, 0, 0); }
    int Solutions() const { return solutions; }
private:
    void d(int r, int ld, int rd) {
        if (r != uplimit) {
            // 当前行可用位置
            auto pos = ~(r|ld|rd)&uplimit;

            while (pos != 0) {
                // 取最低可用bit
                auto p = pos&(~pos+1);
                pos -= p;
                d(r+p, (ld+p)<<1, (rd+p)>>1);
            }
        } else {
            ++solutions;
        }
    }
};

class Solution {
public:
    int totalNQueens(int n) {
        NQueensSolver solver(n);
        solver.Solve();
        return solver.Solutions();
    }
};

#include <stdlib.h>
#include <iostream>

int main(int ac, char **av) {
    std::cout << Solution().totalNQueens(atoi(av[1]));
    return 0;
}
