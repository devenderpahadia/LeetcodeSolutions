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
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        stack<int>st;
        ListNode* p = head;
        ListNode* q = new ListNode();
        ListNode* x=q;
        int ctr=0;
        while(p)
        {
            ctr++;
            p=p->next;
        }
        int i=0;
        p=head;
        while(i <= (ctr-k))
        {
            int y = k;
            while(y--)
            {
                st.push(p->val);
                p=p->next;
                i++;
            }
            while(!st.empty())
            {
                ListNode* t = new ListNode(st.top());
                q->next=t;
                q=t;
                st.pop();
            }
        }
        q->next=p;
        x=x->next;
        return x;
        
    }
};