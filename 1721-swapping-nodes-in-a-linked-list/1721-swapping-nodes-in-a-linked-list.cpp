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
    ListNode* swapNodes(ListNode* head, int k) {
        int ctr=0;
        ListNode* p = head;
        ListNode* q = head;
        while(p)
        {
            p=p->next;
            ctr++;
        }
        int x = ctr-k;
        
        int i=0;
        p=head;
        while(i<k-1)
        {
            p=p->next;
            i++;
        }
        i=0;
        while(i<x)
        {
            head=head->next;
            i++;
        }
        swap(p->val,head->val);
        
        return q;
    }
};