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
    TreeNode* res = new TreeNode();
    
    void solve(TreeNode* root)
    {
        if(root==NULL)
            return;
        
        solve(root->left);
        TreeNode* temp = new TreeNode(root->val);
        res->right=temp;
        res=temp;
        solve(root->right);
    }
    TreeNode* increasingBST(TreeNode* root) {
        
        TreeNode* node=res;
        solve(root);
        node=node->right;
        return node;
    }
};