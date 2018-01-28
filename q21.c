/**
 * Problem #21
 * https://leetcode.com/problems/merge-two-sorted-lists/ 
 *
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *list;
    struct ListNode *plist;
    struct ListNode *p1;
    struct ListNode *p2;
    
    int v1;
    int v2;
    
    if (NULL == l1)
        return l2;
    else if (NULL == l2)
        return l1;
    
    list = (struct ListNode *)malloc(sizeof(struct ListNode));
    if (NULL == list)
        exit(1);
    
    plist = list;
    p1 = l1;
    p2 = l2;
    
    v1 = p1->val;
    v2 = p2->val;
    
    if (v1 > v2)
    {
        struct ListNode *swp;
        swp = p1;
        p1 = p2;
        p2 = swp;
    }
    
    plist->val = p1->val;
    p1 = p1->next;
    v2 = p2->val;
    
    while(NULL != p1)
    {
        v1 = p1->val;
        
        if (NULL != p2)
            v2 = p2->val;
        
        while(v2 <= v1 && NULL != p2)
        {
            plist->next = (struct ListNode*)malloc(sizeof(struct ListNode));
                if (NULL == list)
                    exit(1);

            plist = plist->next;
            plist->val = v2;

            p2 = p2->next;
            if (NULL == p2)
                break;
            
            v2 = p2->val;
        }
        
        plist->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        if (NULL == list)
            exit(1);

        plist = plist->next;
        plist->val = v1;
        p1 = p1->next;
    }
    
    while(NULL != p2)
    {
        plist->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        if (NULL == list)
            exit(1);

        plist = plist->next;
        plist->val = p2->val;
        
        p2 = p2->next;
    }
    
    plist->next = NULL;
    
    return list;
}

/**
 * Note here:
 *  I tried a difficult way to merge two lists,
 * too much useless loops.
 *
 *  Another thing is, any pointer **must** initialize
 * before use.
 *
 */
