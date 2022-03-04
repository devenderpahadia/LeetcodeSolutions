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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* res = new ListNode(0);
        ListNode* x = res;
        ListNode* p = head;
        while(p->next)
        {
            if( p->val == 0)
            {
                p=p->next;
                int sum = 0;
                while(p && p->val!=0)
                {
                    sum+=p->val;
                    p=p->next;
                }
                ListNode* t = new ListNode(sum);
                x->next = t;
                x=t;
            }
        }
        res=res->next;
        return res;
    }
};