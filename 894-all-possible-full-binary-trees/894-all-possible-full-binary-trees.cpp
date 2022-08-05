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
    
    vector<TreeNode*> solve(int n){
        if(n==1){
            vector<TreeNode*>res;
            res.push_back(new TreeNode(0));
            return res;
        }
        vector<TreeNode*>res;
        for(int i=1;i<n;i+=2){
            vector<TreeNode*>l = solve(i);
            vector<TreeNode*>r = solve(n-i-1);
            
            for(auto it : l){
                for(auto jt : r){
                    TreeNode* root = new TreeNode(0);
                    root->left = it;
                    root->right = jt;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
    
    vector<TreeNode*> allPossibleFBT(int n) {
        return solve(n);
    }
};