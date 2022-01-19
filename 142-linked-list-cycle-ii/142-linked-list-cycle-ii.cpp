/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) 
    {
        if(head== NULL)
        {
            return NULL;
        }
        if(head->next == NULL)
        {
            return NULL;
        }
        ListNode *p = head;
        ListNode *q = head;
        bool flag = false;
        p= p->next ;
        q= q->next ;
        q= q->next;
        
        while(q!=NULL && q->next !=NULL)
        {
            if(p==q)
            {
                flag=true;
                break;
            }
            p=p->next ;
            q= q->next ;
            q= q->next;
        }
        if(flag==false)
            return NULL;
        q=head;
        while(1)
        {
            if(p==q)
            {
                return p;
            }
            p=p->next;
            q=q->next;
        }
        return p;
    }
};