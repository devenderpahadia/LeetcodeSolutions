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
    ListNode* solve(ListNode* head)
    {
        ListNode* p = head;
        ListNode* q = NULL;
        ListNode* r = NULL;
        while(p)
        {
            r=q;
            q=p;
            p=p->next;
            q->next = r;
        }
        return q;
    }
    bool isPalindrome(ListNode* head) {
        if(head==NULL||head->next==NULL) return true;
        ListNode* fast = head;
        ListNode* slow = head;
        
        while(fast->next && fast->next->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        fast = head;
        slow->next = solve(slow->next);
        slow = slow->next;
        while(slow)
        {
            if(fast->val!=slow->val) return false;
            fast=fast->next;
            slow=slow->next;
        }
        return true;
    }
};