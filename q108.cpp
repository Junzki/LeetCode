/**
 * Problem #108
 * https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
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
    TreeNode* traverse(vector<int>& arr, int begin, int end) {
        if (begin > end) {
            return nullptr;
        }
        
        auto mid = begin + (end - begin) / 2;
        auto* r = new TreeNode(arr[mid]);
        if (begin == end) {
            return r;
        }
        
      
        auto* left = traverse(arr, begin, mid-1);
        auto* right = traverse(arr, mid+1, end);
        r->left = left;
        r-> right = right;
        
        return r;
    }
    
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        auto size = nums.size();
        if (0 == size) {
            return nullptr;
        } else if (1 == size) {
            return new TreeNode(nums[0]);
        }
        
        auto begin = 0;
        auto end = size - 1;
        
        auto* tree = traverse(nums, begin, end);
        
        return tree;
    }
};
