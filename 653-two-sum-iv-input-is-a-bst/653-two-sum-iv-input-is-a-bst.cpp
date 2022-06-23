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
    
    stack<TreeNode*>stleft;
    stack<TreeNode*>stright;
    
    TreeNode* next(){
        if(stleft.size()){
            TreeNode* x = stleft.top();
            TreeNode* res = x;
            stleft.pop();
            if(x->right){
                x=x->right;
                while(x!=NULL){
                    stleft.push(x);
                    x=x->left;
                }
            }
            return res;
        }
        else return NULL;
    }
    
    TreeNode* before(){
        if(stright.size()){
            TreeNode* x = stright.top();
            TreeNode* res = x;
            stright.pop();
            if(x->left){
                x=x->left;
                while(x!=NULL){
                    stright.push(x);
                    x=x->right;
                }
            }
            return res;
        }
        else return NULL;
    }
    
    bool findTarget(TreeNode* root, int k) {
        
        TreeNode* l = root;
        while(l!=NULL){
            stleft.push(l);
            l=l->left;
        }
        TreeNode*r = root;
        while(r!=NULL){
            stright.push(r);
            r=r->right;
        }
        
        l = next();
        r = before();
        while(l!=r){
            if(l->val + r->val ==k) return true;
            else if(l->val + r->val < k){
                l = next();
            }
            else{
                r = before();
            }
        }
        return false;
    }
};