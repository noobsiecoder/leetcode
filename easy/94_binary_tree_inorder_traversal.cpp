#include <iostream>
#include <vector>
#include <assert.h>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
private:
    std::vector<int> vec;

public:
    std::vector<int> inorderTraversal(TreeNode *root)
    {
        if (root)
        {
            inorderTraversal(root->left);
            vec.push_back(root->val);
            inorderTraversal(root->right);
        }

        return vec;
    }

    // Not for Leetcode scope
    void delete_node(TreeNode *root)
    {
        if (root)
        {
            delete_node(root->left);
            delete_node(root->right);
            delete root;
        }
    }
};

int main(int argc, char *argv[])
{
    Solution solution;

    TreeNode *rootNode = new TreeNode(1);
    rootNode->right = new TreeNode(2);
    rootNode->right->left = new TreeNode(3);

    std::vector<int> vec = {1, 3, 2};
    assert(solution.inorderTraversal(rootNode) == vec);

    solution.delete_node(rootNode);

    return 0;
}