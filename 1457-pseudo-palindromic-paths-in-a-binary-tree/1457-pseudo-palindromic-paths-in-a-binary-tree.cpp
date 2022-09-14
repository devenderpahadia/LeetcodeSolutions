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
    void solve(TreeNode* p,vector<int>&dp,int &res){
        if(p){
            dp[p->val]++;
            if(!p->left && !p->right){
                int odd=0;
                for(auto i:dp){
                    if(i%2) odd++;
                }
                if(odd<=1) res++;
            }
            solve(p->left,dp,res);
            solve(p->right,dp,res);
            dp[p->val]--;
        }
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int>dp(10);
        int res=0;
        solve(root,dp,res);
        return res;
    }
};