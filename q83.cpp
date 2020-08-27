/**
 * Problem #83
 * https://leetcode.com/problems/remove-duplicates-from-sorted-list/
 */

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (nullptr == head) {
            return head;
        }
        
        auto ptr = head;
        auto last = ptr;
        
        ptr = ptr->next;
        while (nullptr != ptr) {
            auto next = ptr->next;
            if (last->val == ptr->val) {
                last->next = next;
            } else {
                last = ptr;
            }
            ptr = next;
        }
        
        return head;
    }
};
