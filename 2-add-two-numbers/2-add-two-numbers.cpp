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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* t = dummy;
        int sum = 0;
        int carry = 0;
        while(l1 || l2)
        {
            if(l1)
            {
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2)
            {
                sum+=l2->val;
                l2=l2->next;
            }
            sum+=carry;
            ListNode* curr = new ListNode(sum%10);
            carry = sum/10;
            t->next = curr;
            t = curr;
            sum=0;
        }
        if(carry == 1)
        {
            ListNode* curr = new ListNode(1);
            t->next = curr;
            t = curr;
        }
        t->next = NULL;
        return dummy->next;
    }
};