/**
 * Problem #70
 * https://leetcode.com/problems/climbing-stairs/
 * 
 * Note: This is a Dynamic Programming problem.
 * Key Point:
 * -> f(n) = f(n - 1) + f(n - 2)
 */

class Solution {
public:
    int climbStairs(int n) {
        if (1 == n)
            return 1;
        else if (2 == n)
            return 2;
        
        auto carry_1 = 1;
        auto carry_2 = 2;
        
        int current;
        auto index = 3;
        for (index = 3; index <= n; ++index) {
            current = carry_2 + carry_1;
            carry_1 = carry_2;
            carry_2 = current;
        }
        
        return current;
    }
};
