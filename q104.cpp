/**
 * Problem #104
 * https://leetcode.com/problems/maximum-depth-of-binary-tree
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
    int traverse(TreeNode* n, int currentDepth) {
        if (nullptr == n) {
            return currentDepth - 1;
        }
        
        auto next = currentDepth;
        auto result = currentDepth;
        
        next = traverse(n->left, currentDepth+1);
        if (next > result)
            result = next;
        
        next = traverse(n->right, currentDepth+1);
        if (next > result)
            result = next;
        
        return result;
    }
    
    int maxDepth(TreeNode* root) {
        return traverse(root, 1);
    }
};
