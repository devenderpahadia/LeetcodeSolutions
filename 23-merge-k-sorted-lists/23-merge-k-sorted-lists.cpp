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
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        priority_queue<int,vector<int>,greater<int>>maxh;
        for(int i=0;i<lists.size();i++)
        {
            ListNode* p = lists[i];
            while(p)
            {
                maxh.push(p->val);
                p=p->next;
            }
        }
        ListNode* res = new ListNode(0);
        ListNode* x = res;
        while(maxh.size()!=0)
        {
            ListNode* t = new ListNode(maxh.top());
            maxh.pop();
            res->next = t;
            res=t;
        }
        return x->next;
    }
};