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
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int>res;
        stack<TreeNode*>st;
        TreeNode* p = root;
        while(1){
            if(p!=NULL){
                st.push(p);
                p=p->left;
            }
            else{
                if(st.empty()) break;
                res.push_back(st.top()->val);
                p = st.top();
                st.pop();
                p=(p->right);
            }
        }
        return res;
    }
};