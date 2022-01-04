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
    
    pair<int,TreeNode*> solve(TreeNode* root,int d)
    {
        if(!root)
            return {-1,NULL};
        
        if(!root->left && !root->right)
            return {d,root};
        
        pair<int,TreeNode*> l = solve(root->left,d+1);
        pair<int,TreeNode*> r = solve(root->right,d+1);
        
        if(l.first == r.first)
            return {l.first,root};
        
        return max(l,r);
    }
    
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return solve(root,0).second;
    }
};