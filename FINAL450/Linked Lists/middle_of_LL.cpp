// https://leetcode.com/problems/middle-of-the-linked-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int ll_len = 0;
        ListNode* temp = head;
        while(temp != NULL)
        {
            ll_len++;
            temp = temp->next;
        }
        ListNode* odd_LL = head;
        int traverse = (ll_len/2);
        while(traverse)
        {
            odd_LL = odd_LL->next;
            traverse--;
        }
        return odd_LL;
        
    }
};
