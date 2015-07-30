#include <algorithm>
#include <stack>
#include <utility>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x)
        : val(x),
          left(0),
          right(0) {}
};

// Slightly different from the "Path Sum" problem
int minDepth(TreeNode *root) {
    if (!root) return 0;

    std::vector<int> depths;
    std::stack<std::pair<TreeNode *, int>> unvisited;

    unvisited.push(std::make_pair(root, 1));

    while (!unvisited.empty()) {
        auto current = unvisited.top();
        unvisited.pop();
        if (!current.first->left && !current.first->right) { // Leaf node
            depths.push_back(current.second);
            continue;
        }

        if (current.first->right)
            unvisited.push(std::make_pair(current.first->right, current.second+1));
        if (current.first->left)
            unvisited.push(std::make_pair(current.first->left, current.second+1));
    }

    std::sort(depths.begin(), depths.end());
    return depths[0];
}
