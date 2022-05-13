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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* l1 = list1;
        ListNode* l2 = list2;
        if(l2==NULL) return l1;
        if(l1==NULL) return l2;
        if(l1->val > l2->val) swap(l1,l2);
        ListNode* res = l1;
        
        while(l1 && l2)
        {
            ListNode* temp = NULL;
            while(l1 && l1->val<=l2->val)
            {
                temp = l1;
                l1=l1->next;
            }
            temp->next = l2;
            swap(l1,l2);
        }
        return res;
    }
};