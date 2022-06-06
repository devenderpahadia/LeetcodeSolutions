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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.size()==0)
            return NULL;
        
        int mx = -1;
        int k ;
        for(int i = 0 ;i <nums.size();i++){
            if(mx<nums[i]) {
                mx = nums[i];
                k = i;
            }
        }
        
        TreeNode* root = new TreeNode(nums[k]);
        vector<int>l ;
        vector<int>r;
        for(int i=0;i<k;i++){
            l.push_back(nums[i]);
        }
        for(int i=k+1;i<nums.size();i++){
            r.push_back(nums[i]);
        }
        root->left = constructMaximumBinaryTree(l);
        root->right = constructMaximumBinaryTree(r);
        
        return root;
    }
};