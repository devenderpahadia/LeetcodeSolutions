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
    void solve(TreeNode* root,int &x)
    {
        if(root)
        {
            solve(root->right,x);
            x+=root->val;
            root->val=x;
            solve(root->left,x);
        }
    }
    
    TreeNode* bstToGst(TreeNode* root) {
        int x =0;
        solve(root,x);
        return root;
    }
};