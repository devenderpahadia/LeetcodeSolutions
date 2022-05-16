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
    
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL || k==0)
            return head;
        
        int ctr=1;
        ListNode* p = head;
        while(p->next)
        {
            p=p->next;
            ctr++;
        }
        p->next = head;
        k = k%ctr;
        ctr = ctr-k;
        while(ctr--)
        {
            p=p->next;
        }
        head = p->next;
        p->next = NULL;
        return head;
    }
};