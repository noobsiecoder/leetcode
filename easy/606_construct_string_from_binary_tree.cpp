#include <iostream>
#include <sstream>
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
    void pre_order_traversal(TreeNode *root, std::ostringstream *oss)
    {
        if (root)
        {
            *oss << root->val;
            if (root->left || root->right)
            {
                *oss << '(';
                pre_order_traversal(root->left, oss);
                *oss << ')';
                if (root->right)
                {
                    *oss << '(';
                    pre_order_traversal(root->right, oss);
                    *oss << ')';
                }
            }
        }
        else
        {
            oss->seekp(-1, std::ios_base::end);
            *oss << "()";
            oss->seekp(-1, std::ios_base::end);
        }
    }

public:
    std::string tree2str(TreeNode *root)
    {
        std::ostringstream oss;
        pre_order_traversal(root, &oss);
        return oss.str();
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
    // creating tree structure: 1(2(4))(3(5))
    TreeNode *rootNode = new TreeNode(1);

    // left child with value 2 and a subtree rooted at [NULL, 4]
    rootNode->left = new TreeNode(2);
    rootNode->left->left = NULL;
    rootNode->left->right = new TreeNode(4);

    // right child with value 3 and a subtree rooted at [3, 5]
    rootNode->right = new TreeNode(3);
    rootNode->right->right = new TreeNode(5);

    Solution solution;
    assert(solution.tree2str(rootNode) == "1(2()(4))(3()(5))");

    solution.delete_node(rootNode);

    return 0;
}