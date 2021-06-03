/**
 * Problem #98
 * https://leetcode.com/problems/validate-binary-search-tree/
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    void traverse(TreeNode *node, double lo, double hi)
    {
        if (nullptr == node)
            return;

        if (node->val <= lo || node->val >= hi)
            throw "value not in range";

        traverse(node->left, lo, node->val);
        traverse(node->right, node->val, hi);
    }

    bool isValidBST(TreeNode *root)
    {
        if (nullptr == root)
        {
            return false;
        }

        try
        {
            traverse(root->left, double(INT_MIN) - 1, root->val);
            traverse(root->right, root->val, double(INT_MAX) + 1);
        }
        catch (...)
        {
            return false;
        }

        return true;
    }
};
