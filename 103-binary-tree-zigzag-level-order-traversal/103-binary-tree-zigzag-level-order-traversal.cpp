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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        if(root==NULL)
            return {};
        vector<vector<int>>res;
        
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int sz = q.size();
            vector<int>temp;
            while(sz--)
            {
                TreeNode* n = q.front();
                q.pop();
                temp.push_back(n->val);
                
                if(n->left)
                    q.push(n->left);
                if(n->right)
                    q.push(n->right);
            }
            res.push_back(temp);
        }
        
        for(int i=1;i<res.size();i+=2)
        {
            reverse(res[i].begin(),res[i].end());
        }
        
        return res;
    }
};