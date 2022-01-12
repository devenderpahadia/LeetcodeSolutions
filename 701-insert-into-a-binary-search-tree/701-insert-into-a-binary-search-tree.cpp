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
    TreeNode* insertIntoBST(TreeNode* root, int val) 
    {
        if(root==NULL)
        {
            TreeNode* n = new TreeNode(val);
            return n;
        }
        if(root->left==NULL && root->val>val)
        {
            TreeNode* n = new TreeNode(val);
            root->left=n;
            return root;
        }
        if(root->right==NULL && root->val<val)
        {
            TreeNode* n = new TreeNode(val);
            root->right=n;
            return root;
        }
        
        if(root->val > val)
        {
            insertIntoBST(root->left,val);
        }
        else if(root->val < val)
        {
            insertIntoBST(root->right,val);
        }
        return root;
    }
};