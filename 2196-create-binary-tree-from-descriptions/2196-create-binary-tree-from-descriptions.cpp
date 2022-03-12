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
    TreeNode* createBinaryTree(vector<vector<int>>& desc) {
        unordered_map<int,TreeNode*>mp;
        unordered_map<int,int>mp1;
        TreeNode* res = NULL;
        for(auto it : desc)
        {
            int nd = it[0];
            mp1[nd] = 1;
            if(mp.find(nd)!=mp.end())
            {
                
            }
            else
            {
                TreeNode* nod = new TreeNode(nd);
                mp[nd] = nod;
            }
            int ch = it[1];
            if(mp.find(ch)!=mp.end())
            {
                
            }
            else
            {
                TreeNode* nod = new TreeNode(ch);
                mp[ch] = nod;
            }
        }
        
        for(auto it : desc)
        {
            if(it[2]==1)
            {
                mp[it[0]]->left = mp[it[1]];
            }
            else if(it[2]==0)
            {
                mp[it[0]]->right = mp[it[1]];
            }
        }
        
        for(auto it : desc)
        {
            if(mp1.find(it[1])!=mp1.end())
            {
                mp1.erase(it[1]);
            }
        }
        
        for(auto it : mp1)
        {
            return mp[it.first];
        }
        return res;
    }
};