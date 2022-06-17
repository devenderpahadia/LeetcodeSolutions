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
    
    int solve(TreeNode* root,int&cam){
        if(root==NULL) return 1;
        int l = solve(root->left,cam);
        int r = solve(root->right,cam);
        
        if(l==-1 || r==-1) {
            cam++;
            return 0;
        }
        
        if(l==0 || r==0) return 1;
        
        return -1;
        
    }
    
    int minCameraCover(TreeNode* root) {
        int cam = 0;
        
        if(solve(root,cam)==-1) cam++;
        return cam;
        
    }
};