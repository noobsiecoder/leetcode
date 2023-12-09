#include <iostream>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void in_order_traversal(TreeNode *node)
{
    if (node != nullptr)
    {
        in_order_traversal(node->left);
        std::cout << node->val << " ";
        in_order_traversal(node->right);
    }
}

void pre_order_traversal(TreeNode *node)
{
    if (node != nullptr)
    {
        std::cout << node->val << " ";
        pre_order_traversal(node->left);
        pre_order_traversal(node->right);
    }
}

void post_order_traversal(TreeNode *node)
{
    if (node != nullptr)
    {
        post_order_traversal(node->left);
        post_order_traversal(node->right);
        std::cout << node->val << " ";
    }
}

void delete_node(TreeNode *root)
{
    if (root)
    {
        delete_node(root->left);
        delete_node(root->right);
        delete root;
    }
}

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

    in_order_traversal(rootNode);
    std::cout << std::endl;
    pre_order_traversal(rootNode);
    std::cout << std::endl;
    post_order_traversal(rootNode);
    std::cout << std::endl;
    
    delete_node(rootNode);

    return 0;
}