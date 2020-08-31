/**
 * Problem #100
 * https://leetcode.com/problems/same-tree/
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        auto all_null = (nullptr == p) && (nullptr == q);
        if (all_null) {
            return true;
        } else if (nullptr == p) {
            return false;
        } else if (nullptr == q) {
            return false;
        }
        
        if (p->val != q->val) {
            return false;
        }
        
        auto left_same = isSameTree(p->left, q->left);
        if (! left_same) {
            return false;
        }
        
        auto right_same = isSameTree(p->right, q->right);
        return right_same;
    }
};
