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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
    {
        if(l1 == NULL && l2==NULL)
        {
            return l1;
        }
        if(l1 == NULL && l2!=NULL)
        {
            return l2;
        }
        if(l1 != NULL && l2==NULL)
        {
            return l1;
        }
        
        ListNode *imp = NULL;
        ListNode *last = NULL;
        
        if(l1->val < l2->val)
        {
            imp=last=l1;
            l1=l1->next;
            last->next=NULL;
            //cout<<last->val<<" ";
        }
        else
        {
            imp=last=l2;
            l2=l2->next;
            last->next=NULL;
            //cout<<last->val<<" ";
        }
        
        while(l1!=NULL && l2!=NULL)
        {
            if(l1->val < l2->val)
            {
                last->next = l1;
                last=l1;
                l1=l1->next;
                last->next=NULL;
                //cout<<last->val<<" ";
            }
            else
            {
                last->next = l2;
                last=l2;
                l2 = l2->next;
                last->next=NULL;
                //cout<<last->val<<" ";
            }
        }
        if(l1!=NULL)
        {
            last->next = l1;
        }
        if(l2!=NULL)
        {
            last->next = l2;
        }
        
        return imp;
        
    }
};