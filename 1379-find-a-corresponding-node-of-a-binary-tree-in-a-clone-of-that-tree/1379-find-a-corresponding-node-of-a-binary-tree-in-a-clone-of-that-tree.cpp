/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    unordered_map<TreeNode*,TreeNode*>mp;
    
    void solve(TreeNode* root,TreeNode* root1)
    {
        if(root==NULL)
        {
            mp[root]=NULL;
            return;
        }
        mp[root] = root1;
        solve(root->left,root1->left);
        solve(root->right,root1->right);
    }
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        solve(original,cloned);
        return mp[target];
    }
};