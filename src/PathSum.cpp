#include <stack>
#include <utility>
#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x)
        : val(x),
          left(0),
          right(0) {}
};

// Use depth first traversal, and keep track of the 'current' sum.
bool hasPathSum(TreeNode *root, int sum) {
    if (!root) return false;  // Do not forget this!!

    std::stack<std::pair<TreeNode *, int> > unvisited;

    unvisited.push(std::make_pair(root, root->val));

    while (!unvisited.empty()) {
        auto current = unvisited.top();
        if (!current.first->right && !current.first->left && current.second == sum) 
            return true;

        unvisited.pop();
        if (current.first->right) 
            unvisited.push(std::make_pair(current.first->right, current.second+current.first->right->val));
        if (current.first->left)
            unvisited.push(std::make_pair(current.first->left, current.second+current.first->left->val));
    }

    return false;
}
