/**
 * Problem #94
 * https://leetcode.com/problems/binary-tree-inorder-traversal
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
class Solution {
public:
    void traverse(vector<int>& r, TreeNode* node) {
        if (nullptr == node)
            return;
        
        traverse(r, node->left);
        
        r.push_back(node->val);
        
        traverse(r, node->right);
    }
    
    
    vector<int> inorderTraversal(TreeNode* root) { 
        vector<int> result;
        
        traverse(result, root);
        
        return result;
    }
};
