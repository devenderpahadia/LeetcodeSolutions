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
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next==NULL)
        {
            delete head;
            return NULL;
        }
        int ctr=0;
        ListNode* p = head;
        while(p)
        {
            ctr++;
            p=p->next;
        }
        int i=0;
        p=head;
        ListNode* q = NULL;
        while(i<ctr/2)
        {
            q=p;
            p=p->next;
            i++;
        }
        q->next = p->next;
        delete p;
        return head;
    }
};