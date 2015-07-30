#include <vector>

using std::vector;

/************************************************************
// This solution works, but it's too slow because of the recursion.

int n(int r, int c) {
    if (c == 0 || c == r)
        return 1;

    return n(r-1, c-1) + n(r-1, c);
}

// Constraints:
//   Use O(k) extra space.
vector<int> getRow(int rowIndex) {
    vector<int> ret;

    for (int c = 0; c <= rowIndex; c++)
        ret.push_back(n(rowIndex, c));

    return ret;
}
**************************************************************/

// Space complexity: O(2k)
vector<int> getRow(int rowIndex) {
    vector<int> lastRow(rowIndex);
    vector<int> thisRow(rowIndex);

    for (int r = 0; r <= rowIndex; r++) {
        thisRow.clear();
        for (int c = 0; c <= r; c++) {
            if (c == 0 || c == r)
                thisRow.push_back(1);
            else
                thisRow.push_back(lastRow[c-1]+lastRow[c]);
        }
        lastRow = thisRow;
    }
    return thisRow;
}