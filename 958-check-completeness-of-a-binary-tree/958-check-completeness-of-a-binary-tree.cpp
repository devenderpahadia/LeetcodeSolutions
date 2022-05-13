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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int flag = 1;
        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                TreeNode* u = q.front();
                q.pop();
                if(flag && u->left){
                    q.push(u->left);
                }
                else if(!flag && u->left) return false;
                if(u->left==NULL)
                    flag = 0;
                if(flag && u->right){
                    q.push(u->right);
                }
                else if(!flag && u->right) return false;
                if(u->right==NULL)
                    flag = 0;
            }
        }
        return true;
    }
};