/**
 * Problem #67
 * https://leetcode.com/problems/add-binary/
 */

#include <iostream>
#include <string>

using std::string;

class Solution {
public:
    string addBinary(string a, string b) {
        auto size = 0;
        char* result = nullptr;
        if (a.length() >= b.length()){
            result = (char *)a.c_str();
            size = a.length();
        } else {
            result = (char *)b.c_str();
            size = b.length();
        }
        
        auto step = 0;
        auto carry = 0;
        auto index = size - 1;
        
        for (index; index >= 0; --index) {
            auto ia = a.length() - 1 - step;
            auto ib = b.length() - 1 - step;

            auto x = step >= a.length() ? 0 : a[ia] - '0';
            auto y = step >= b.length() ? 0 : b[ib] - '0';
            ++step;
            
            auto z = x + y + carry;
            switch(z) {
                case 0:
                    carry = 0;
                    result[index] = '0';
                    break;
                case 1:
                    carry = 0;
                    result[index] = '1';
                    break;
                case 2:
                    carry = 1;
                    result[index] = '0';
                    break;
                case 3:
                    carry = 1;
                    result[index] = '1';
                    break;
            }
        }
        
        auto rendered = string(result);
        if (1 == carry) {
            rendered = '1' + rendered;
        }
        
        return rendered;
    }
};


int main(void) {
    auto a = "11";
    auto b = "101";

    auto c = Solution().addBinary(a, b);
    std::cout << c << std::endl;
    return 0;
}
