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
    ListNode* solve(ListNode* node)
    {
        if(node==NULL)
            return NULL;
        
        ListNode* p = node;
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
    
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        int k=1;
        ListNode* q = NULL;
        ListNode* p = head;
        vector<ListNode*>arr;
        while(p)
        {
            int ctr=k;
            arr.push_back(p);
            ListNode* q = NULL;
            while(ctr-- && p)
            {
                q=p;
                p=p->next;
            }
            q->next=NULL;
            k++;
        }
        for(int i=0;i<arr.size();i++)
        {
            ListNode* x = arr[i];
            int ctr=0;
            while(x)
            {
                x=x->next;
                ctr++;
            }
            if(ctr%2==0)
            {
                arr[i] = solve(arr[i]);
            }
        }
        
        p=arr[0];
        for(int i=1;i<arr.size();i++)
        {
            while(p->next)
            {
                p=p->next;
            }
            p->next = arr[i];
            p=arr[i];
        }
        
        return head;
    }
};