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
    ListNode* solve(ListNode* head){
        ListNode* p = head;
        ListNode* q = NULL;
        ListNode* r = NULL;
        while(p){
            r=q;
            q=p;
            p=p->next;
            q->next = r;
        }
        return q;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        if(left==1){
            ListNode* q = head;
            ListNode* p;
            ListNode* r ;
            while(right--){
                r=q;
                q=q->next;
            }
            r->next = NULL;
            // cout<<r->val<<endl;
            r = solve(head);
            
            p = r;
            while(p->next) p=p->next;
            p->next = q;
            return r;
        }
        
        ListNode* p = head;
        left-=2;
        while(left-- >0){
            p=p->next;
        }
        ListNode* q = head;
        ListNode* r ;
        while(right--){
            r=q;
            q=q->next;
        }
        r->next = NULL;
        r = solve(p->next);
        // cout<<p->val<<" "<<q->val<<" "<<r->val<<endl;
        p->next = r;
        while(p->next) p=p->next;
        p->next = q;
        return head;
    }
};