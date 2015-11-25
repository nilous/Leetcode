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

int main(int ac, char **av) {
    auto solutions = solveNQueens(8);
    cout << solutions.size() << '\n';

    return 0;
}
