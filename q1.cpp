/*
 * Problem #1
 * https://leetcode.com/problems/two-sum/
 */
 
#include <map>
#include <vector>
 
using namespace std;
 
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> values;
        auto index = 0;
        
        for (index = 0; index < nums.size(); ++index) {
            auto v = nums[index];
            values[v] = index;
        }
        
        vector<int> result;
        
        for (index = 0; index < nums.size(); ++index) {
            auto v = nums[index];
            auto expect = target - v;
            
            auto matched_index = -1;
            
            try {
                matched_index = values.at(expect);
            } catch (const std::out_of_range& e) {
                continue;
            }
            
            if (matched_index <= index) {
                continue;
            }
            
            result.push_back(index);
            result.push_back(matched_index);
            break;
        }
        
        return result;
    }
};
