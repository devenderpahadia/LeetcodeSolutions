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
    
    void solve(TreeNode* root,vector<int>&res){
        if(root==NULL) return;
        
        solve(root->left,res);
        res.push_back(root->val);
        solve(root->right,res);
            
    }
    
    TreeNode* func(int l,int h,vector<int>&res){
        if(l<=h){
            int mid = (l+h)/2;
            TreeNode* no = new TreeNode(res[mid]);
            no->left = func(l,mid-1,res);
            no->right = func(mid+1,h,res);
            return no;
        }
        return NULL;
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>res;
        solve(root,res);
        return func(0,res.size()-1,res);
    }
};