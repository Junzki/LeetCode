/**
 * Problem #88
 * https://leetcode.com/problems/merge-sorted-array/
 *
 * The STL can make things much more easier. :P
 */

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (0 == n) {
            return;
        }
        
        auto pos = m;
        
        for (auto v : nums2) {
            nums1[pos] = v;
            ++pos;
        }
        
        sort(nums1.begin(), nums1.end());
    }
};
