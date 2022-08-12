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
    
    void solve(TreeNode* root,unordered_map<int,vector<pair<int,int>>>&mp1){
                // cout<<mp1[root->val][0].second<<endl;
        if( mp1.count(root->val) && mp1[root->val].size()>0 && mp1[root->val][0].second == 1){
            // cout<<mp1[root->val][0].first<<endl;
            root->left = new TreeNode(mp1[root->val][0].first);
            solve(root->left,mp1);
        }
        else if( mp1.count(root->val) && mp1[root->val].size()>0 && mp1[root->val][0].second == 0){
            // cout<<mp1[root->val][0].first<<endl;
            root->right = new TreeNode(mp1[root->val][0].first);
            solve(root->right,mp1);
        }
        
        if( mp1.count(root->val) && mp1[root->val].size()>1 && mp1[root->val][1].second == 1){
            root->left = new TreeNode(mp1[root->val][1].first);
            solve(root->left,mp1);
        }
        else if( mp1.count(root->val) && mp1[root->val].size()>1 && mp1[root->val][1].second == 0){
            root->right = new TreeNode(mp1[root->val][1].first);
            solve(root->right,mp1);
        }
        
    }
    
    TreeNode* createBinaryTree(vector<vector<int>>& desc) {
        TreeNode* root;
        unordered_map<int,int>mp;
        unordered_map<int,vector<pair<int,int>>>mp1;
        vector<int>vec;
        for(auto it : desc){
            vec.push_back(it[0]);
            vec.push_back(it[1]);
            mp[it[1]]++;
            mp1[it[0]].push_back({it[1],it[2]});
        }
        for(auto it : vec){
            if(mp.find(it)!=mp.end()){
                
            }
            else{
                root = new TreeNode(it);
            }
        }
        
        TreeNode* x = root;
        
        solve(x,mp1);
        return root;
        
    }
};