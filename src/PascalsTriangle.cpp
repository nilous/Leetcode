#include <vector>

using std::vector;

vector<vector<int> > generate(int numRows) {
    vector<vector<int>> ret;
    for (int r = 0; r < numRows; r++) {
        vector<int> row;
        for (int c = 0; c <= r; c++) {
            if (c == 0 || c == r)
                row.push_back(1);
            else
                row.push_back(ret[r-1][c-1]+ret[r-1][c]);
        }
        ret.push_back(row);
    }
    return ret; 
}