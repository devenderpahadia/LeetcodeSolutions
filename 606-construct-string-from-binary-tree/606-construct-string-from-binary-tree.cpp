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
    void solve(TreeNode* root,string&res)
    {
        if(root==NULL)
            return;
        res+=to_string(root->val);
        if(root->left)
        {
            res+='(';
            solve(root->left,res);
            res+=')';
        }
        if(root->left==NULL && root->right)
        {    
            res+="()";
            res+='(';
            solve(root->right,res);
            res+=')';
        }
        else if(root->right)
        {
            res+='(';
            solve(root->right,res);
            res+=')';
        }
    }
    
    string tree2str(TreeNode* root) {
        string res="";
        solve(root,res);
        return res;
    }
};