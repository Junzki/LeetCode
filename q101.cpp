/**
 * Problem #101
 * https://leetcode.com/problems/symmetric-tree/
 */


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    auto compare(TreeNode* left, TreeNode* right) -> bool {
        if ((nullptr == left) && (nullptr == right))
            return true;
        else if ((nullptr == left) || (nullptr == right))
            return false;
        
        if (left->val != right->val)
            return false;
        
        if (!compare(left->left, right->right))
            return false;
        
        return compare(left->right, right->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        if (nullptr == root)
            return true;
        
        return compare(root->left, root->right);
    }
};
