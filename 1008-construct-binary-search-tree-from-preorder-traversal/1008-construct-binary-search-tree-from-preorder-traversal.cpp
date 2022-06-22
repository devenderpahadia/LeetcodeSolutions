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
    
    void solve(TreeNode* root,int x){
        if(root->val > x){
            if(root->left){
                solve(root->left,x);
            }
            else{
                TreeNode* temp = new TreeNode(x);
                root->left = temp;
                return;
            }
        }
        else{
            if(root->right){
                solve(root->right,x);
            }
            else{
                TreeNode* temp = new TreeNode(x);
                root->right = temp;
                return;
            }
        }
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = new TreeNode(preorder[0]);
        TreeNode* res = root;
        for(int i=1;i<preorder.size();i++){
            root = res;
            solve(root,preorder[i]);
        }
        return res;
    }
};
