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
    void solve1(TreeNode* root,vector<int>res,int &k)
    {
        if(root==NULL)
            return;
        solve1(root->left,res,k);
        root->val = res[k++];
        solve1(root->right,res,k);
    }
    void solve(TreeNode* root,vector<int>&res)
    {
        if(root==NULL)
            return;
        solve(root->left,res);
        res.push_back(root->val);
        solve(root->right,res);
    }
    void recoverTree(TreeNode* root) {
        vector<int>res;
        solve(root,res);
        sort(res.begin(),res.end());
        int k = 0;
        solve1(root,res,k);
        
    }
};