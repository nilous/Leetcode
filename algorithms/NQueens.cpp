/**
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.


Given an integer n, return all distinct solutions to the n-queens puzzle.
Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
*/

#include <math.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

////////////////////////////////////////////////////////////////////////////////
// 1. 递归解法

class Board {
    int nn;
    uint8_t *cells;
public:
    explicit Board(int n) : nn(n), cells(new uint8_t[n*n]) { Clear(0); }
    int Size() const { return nn; }
    void Clear(int startRow) { memset(cells+startRow*nn, 0, sizeof(uint8_t)*(nn-startRow)*nn); }
    uint8_t &Cells(int row, int col) const { return *(cells+row*nn+col); }
    bool IsCellAvailable(int row, int col) const {
        for (auto r = 0; r < nn; ++r) {
            for (auto c = 0; c < nn; ++c) {
                if (Cells(r, c) != 0) {
                    if (r == row || c == col || abs(r-row) == abs(c-col)) return false;
                }
            }
        }
        return true;
    }
    bool TryPut(int row, int col) {
        if (!IsCellAvailable(row, col)) return false;
        Cells(row, col) = 1; return true;
    }
};

vector<string> BoardAsStringVector(const Board &b) {
    vector<string> result;
    stringstream buf;
    for (auto r = 0; r < b.Size(); ++r) {
        buf.str("");
        for (auto c = 0; c < b.Size(); ++c)
            buf << (b.Cells(r, c) ? 'Q' : '.');
        result.push_back(buf.str());
    }
    return result;
}

class NQueensSolver {
    Board board;
    vector<vector<string>> solutions;
public:
    explicit NQueensSolver(int queens) : board(Board(queens)) {}
    const vector<vector<string>> &Solutions() const { return solutions; }
    void Solve() { PutQueen(0); }
private:
    void PutQueen(int index) {
        for (auto c = 0; c < board.Size(); ++c) {
            board.Clear(index);
            if (board.TryPut(index, c)) {
                if (index == board.Size()-1) { solutions.push_back(BoardAsStringVector(board)); return; }
                else PutQueen(index+1);
            }
        }
    }
};

vector<vector<string>> solveNQueens(int n) {
    NQueensSolver solver(n);
    solver.Solve();
    return solver.Solutions();
}

////////////////////////////////////////////////////////////////////////////////
// 2. 非递归

// 在Intel E3-1230 V2 @ 3.30GHz的机器上，cl /O2编译：
// 13皇后的耗时约为：
// 递归：   21094 ms 
// 非递归： 21140 ms
// 因函数调用导致的时间开销，可以忽略不计。唯一的问题是递归可能导致stack overflow。

class NQueensSolver_NonRecursion {
    Board board;
    vector<vector<string>> solutions;
public:
    explicit NQueensSolver_NonRecursion(int queens) : board(Board(queens)) {}
    const vector<vector<string>> &Solutions() const { return solutions; }

    int ColForRow(int r) const {
        for (auto c = 0; c < board.Size(); ++c) {
            if (board.Cells(r, c) != 0) return c;
        }
        return -1;
    }

    void Solve() {
        int r, c;
        r = c = 0;

        while (1) {
            c = ColForRow(r);
            board.Clear(r);

            auto cc = c+1;
            for (; cc < board.Size(); ++cc) {
                if (board.TryPut(r, cc)) {
                    if (r == board.Size()-1) { solutions.push_back(BoardAsStringVector(board)); --r; }
                    else { ++r; }
                    break;
                }
            }
            if (r < 0) return;
            if (cc == board.Size()) {
                if (r == 0) return;
                else --r;
            }
        }
    }
};

////////////////////////////////////////////////////////////////////////////////
// 3. 快的一b的位操作版本

class NQueensSolver_Bits {
    int n;
    int uplimit;
    vector<string> solution;
    vector<vector<string>> solutions;
public:
    explicit NQueensSolver_Bits(int queens) : n(queens), uplimit((1<<n)-1) {}

    void Solve() { d(0, 0, 0); }
    vector<vector<string>> Solutions() const { return solutions; }
private:
    string RowAsString(int row) {
        string r(n, '.');
        auto i = 0;
        while (1) {
            if ((1<<i) == row) {
                r[n-i-1] = 'Q';
                break;
            }
            ++i;
        }
        return r;
    }

    void d(int r, int ld, int rd) {
        if (r != uplimit) {
            // 当前行可用位置
            auto pos = ~(r|ld|rd)&uplimit;

            while (pos != 0) {
                // 取最低可用bit
                auto p = pos&(~pos+1);
                pos -= p;

                solution.push_back(RowAsString(p));

                d(r+p, (ld+p)<<1, (rd+p)>>1);

                solution.pop_back();
            }
        } else {
            solutions.push_back(solution);
        }
    }
};

#include <Windows.h>

class Timer {
    DWORD begin;
public:
    Timer() : begin(GetTickCount()) {}
    ~Timer() { cout << "Time eplased: " << GetTickCount()-begin << "ms.\n"; }
};


int main(int ac, char **av) {
#define N 8 
#define LOG_TIME Timer __lt__
    NQueensSolver solver(N);
    {
        LOG_TIME;
        solver.Solve();
    }
    cout << solver.Solutions().size() << '\n';

    NQueensSolver_NonRecursion nr_solver(N);
    {
        LOG_TIME;
        nr_solver.Solve();
    }
    cout << nr_solver.Solutions().size() << '\n';

    NQueensSolver_Bits bits_solver(N);
    {
        LOG_TIME;
        bits_solver.Solve();
    }
    cout << bits_solver.Solutions().size() << '\n';

    for (auto solution : bits_solver.Solutions()) {
        for (auto row : solution) {
            cout << row << '\n';
        }
        cout << "\n\n";
    }

    return 0;
}
