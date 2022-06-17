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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>res;
        map<int,map<int,multiset<int>>>mp;
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
        
        while(!q.empty()){
            TreeNode* node = q.front().first;
            int x = q.front().second.first;
            int y = q.front().second.second;
            q.pop();
            mp[x][y].insert(node->val);
            if(node->left) q.push({node->left,{x-1,y+1}});
            if(node->right) q.push({node->right,{x+1,y+1}});
        }
        for(auto it : mp){
            vector<int>it1;
            for(auto x : it.second){
                it1.insert(it1.end(),x.second.begin(),x.second.end());
            }
            res.push_back(it1);
        }
        return res;
    }
};