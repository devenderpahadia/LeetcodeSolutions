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
    ListNode* solve(ListNode* l1,ListNode* l2)
    {
        ListNode*p = l1;
        ListNode*q = l2;
        int ctr1 = 0;
        int ctr2 = 0;
        while(p)
        {
            p=p->next;
            ctr1++;
        }
        while(q)
        {
            q=q->next;
            ctr2++;
        }
        // cout<<ctr1<<" "<<ctr2<<endl;
        p=l1;
        q=l2;
        int carry = 0;
        ListNode* t ;
        if(ctr1>=ctr2)
        {
            while(l1 && l2)
            {
                int c = l1->val;
                l1->val = (l1->val+l2->val+carry)%10;
                if(c + l2->val + carry > 9) carry = 1;
                else
                    carry=0;
                t=l1;
                l1=l1->next;
                l2=l2->next;
            }
            
            while(l1)
            {
                int c = l1->val;
                l1->val = (l1->val+carry)%10;
                if(c + carry > 9) carry = 1;
                else
                    carry=0;
                t=l1;
                l1=l1->next;
            }
            
            if(carry==1)
            {
                ListNode* d = new ListNode(1);
                t->next = d;
            }
            
            return p;
        }
        else
        {
            while(l1 && l2)
            {
                int c = l2->val;
                l2->val = (l1->val+l2->val+carry)%10;
                if(c + l1->val + carry > 9) carry = 1;
                else
                    carry=0;
                t=l2;
                l1=l1->next;
                l2=l2->next;
            }
            while(l2)
            {
                int c = l2->val;
                l2->val = (l2->val+carry)%10;
                if(c + carry > 9) carry = 1;
                else
                    carry=0;
                t=l2;
                l2=l2->next;
            }
            if(carry==1)
            {
                ListNode* d = new ListNode(1);
                t->next = d;
            }
            return q;
        }
        return p;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p = l1;
        ListNode* q = NULL;
        ListNode* r= NULL;
        
        while(p)
        {
            r=q;
            q=p;
            p=p->next;
            q->next=r;
        }
        l1 = q;
        
        p=l2;
        q=NULL;
        r=NULL;
        
        while(p)
        {
            r=q;
            q=p;
            p=p->next;
            q->next=r;
        }
        l2 = q;
        
        ListNode* res = solve(l1,l2);
        
        p=res;
        q=NULL;
        r=NULL;
        
        while(p)
        {
            r=q;
            q=p;
            p=p->next;
            q->next=r;
        }
        res = q;
        return res;
    }
};