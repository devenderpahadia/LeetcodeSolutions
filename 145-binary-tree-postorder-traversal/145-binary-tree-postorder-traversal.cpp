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
    vector<int> postorderTraversal(TreeNode* root) {
        if(root==NULL) return {};
        stack<TreeNode*>st1,st2;
        TreeNode* p = root;
        vector<int>res;
        st1.push(p);
        while(st1.size()){
            st2.push(st1.top());
            st1.pop();
            if(st2.top()->left){
                st1.push(st2.top()->left);
            }
            if(st2.top()->right){
                st1.push(st2.top()->right);
            }
        }
        while(st2.size()){
            res.push_back(st2.top()->val);
            st2.pop();
        }
        return res;
    }
};