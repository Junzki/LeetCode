/**
 * Problem #115
 * https://leetcode.com/problems/binary-tree-postorder-traversal/
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

        traverse(r, node->left);
        traverse(r, node->right);

        r.push_back(node->val);
    }

    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> result;

        traverse(result, root);

        return result;
    }
};
