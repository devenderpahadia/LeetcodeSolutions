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
    bool isPalindrome(ListNode* head) {
        ListNode* head2 = new ListNode(head->val);
        ListNode* p = head->next;
        ListNode* q = head2;
        
        while(p){
            ListNode* t = new ListNode(p->val);
            q->next = t;
            q = t;
            p=p->next;
        }
        
        ListNode* r = NULL;
        p=head2;
        q=NULL;
        
        while(p){
            r=q;
            q=p;
            p=p->next;
            q->next=r;
        }
        
        p=head;
        while(p){
            if(p->val!=q->val){
                return false;
            }
            p=p->next;
            q=q->next;
        }
        return true;
    }
};