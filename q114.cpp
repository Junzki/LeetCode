/**
 * Problem #114
 * https://leetcode.com/problems/binary-tree-preorder-traversal/
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
    void traverse(vector<int> &r, TreeNode *node)
    {
        if (nullptr == node)
            return;

        r.push_back(node->val);

        traverse(r, node->left);
        traverse(r, node->right);
    }

    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> result;

        traverse(result, root);

        return result;
    }
};
