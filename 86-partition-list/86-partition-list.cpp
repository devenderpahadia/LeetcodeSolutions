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
    ListNode* partition(ListNode* head, int x) {
        ListNode* p = new ListNode();
        ListNode* q = p;
        ListNode* x1 = new ListNode();
        ListNode* y = x1;
        
        ListNode* ptr = head;
        while(ptr){
            if(ptr->val < x){
                q->next = new ListNode(ptr->val);
                q=q->next;
            }
            else{
                y->next = new ListNode(ptr->val);
                y=y->next;
            }
            ptr = ptr->next;
        }
        q->next = x1->next;
        return p->next;
    }
};