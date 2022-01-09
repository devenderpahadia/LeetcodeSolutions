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
    void reorderList(ListNode* head) {
        vector<int>nums;
        ListNode* p = head;
        
        while(p)
        {
            nums.push_back(p->val);
            p=p->next;
        }
        p=head;
        int l = 0;
        int h = nums.size()-1;
        
        while(l<h && p)
        {
            p->val = nums[l++];
            p=p->next;
            p->val = nums[h--];
            p=p->next;
        }
        if(nums.size()%2 == 1)
        {
            p->val = nums[nums.size()/2];
        }
    }
};