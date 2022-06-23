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
    void solve(TreeNode* root,int k,int&res,int&cnt)
    {
        if(root==NULL)
            return ;
        
        solve(root->left,k,res,cnt);
        cnt++;
        if(cnt==k){
            res = root->val;
            return;
        }
        solve(root->right,k,res,cnt);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0;
        int res = -1;
        solve(root,k,res,cnt);
        return res;
    }
};