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
    int mx = -1;
    
    void func(TreeNode* root,int t)
    {
        if(root==NULL)
            return;
        mx = max(mx,abs(root->val-t));
        func(root->left,t);
        func(root->right,t);
    }
    
    void solve(TreeNode* root)
    {
        if(root==NULL)
            return ;
        func(root,root->val);
        solve(root->left);
        solve(root->right);
    }
    
    int maxAncestorDiff(TreeNode* root) {
        solve(root);
        return mx;
    }
};