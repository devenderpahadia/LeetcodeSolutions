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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==NULL) return NULL;
        
        int ctr = 0;
        ListNode* p = head;
        while(p){
            p=p->next;
            ctr++;
        }
        if(ctr==1){
            TreeNode* root = new TreeNode(head->val);
            return root;
        }
        int mid = ctr/2;
        p=head;
        while(mid--){
            p=p->next;
        }
        TreeNode* root = new TreeNode(p->val);
        ListNode* l = head;
        ListNode* r = p->next;
        mid = ctr/2 -1;
        p=head;
        while(mid--){
            p=p->next;
        }
        p->next = NULL;
        
        root->left = sortedListToBST(l);
        root->right = sortedListToBST(r);
        
        return root;
    }
};