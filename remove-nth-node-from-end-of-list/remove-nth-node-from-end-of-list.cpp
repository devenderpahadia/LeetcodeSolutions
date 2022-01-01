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
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        int ctr=0;
        ListNode* p = head;
        ListNode* q = NULL;
        while(p)
        {
            ctr++;
            p=p->next;
        }
        
        if(ctr==1)
        {
            head = NULL;
            return head;
        }
        if(n==ctr)
        {
            head = head->next;
            return head;
        }
        int i=0;
        p=head;
        while(i< ctr-n)
        {
            q=p;
            p=p->next;
            i++;
        }
        if(p->next)
        q->next = p->next;
        else
            q->next= NULL;
        return head;
    }
};