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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        vector<double>res;
        while(!q.empty())
        {
            int sz = q.size();
            double sum=0;
            int ctr=0;
            while(sz--)
            {
                TreeNode* node = q.front();
                q.pop();
                sum+=node->val;
                ctr++;
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            sum = sum/ctr;
            res.push_back(sum);
        }
        return res;
    }
};