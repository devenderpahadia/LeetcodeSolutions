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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        TreeNode* root = new TreeNode(nums[n/2]);
        vector<int>left1,right1;
        for(int i=0;i<=n/2-1;i++){
            left1.push_back(nums[i]);
        }
        for(int i=n/2+1;i<n;i++){
            right1.push_back(nums[i]);
        }
        if(left1.size())
        root->left = sortedArrayToBST(left1);
        if(right1.size())
        root->right = sortedArrayToBST(right1);
        
        return root;
    }
};