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
    int res = 0;
    class Nodeval{
        public:
        int mn;
        int mx;
        int sum;
        bool check;
        
        Nodeval(int mnn,int mxx,int summ,bool c){
            mn = mnn;
            mx = mxx;
            sum = summ;
            check = c;
        }
    };
    
    Nodeval solve(TreeNode* root){
        if(root==NULL){
            return Nodeval(INT_MAX,INT_MIN,0,true);
        }
        
        Nodeval l = solve(root->left);
        Nodeval r = solve(root->right);
        
        if( l.check && r.check && root->val > l.mx && root->val < r.mn ){
            res = max(res,l.sum + r.sum + root->val);
            return Nodeval(min(root->val,l.mn),max(root->val,r.mx),l.sum + r.sum + root->val,true);
        }
        
        return Nodeval(INT_MIN,INT_MAX,max(l.sum,r.sum),false);
        
    }
    
    int maxSumBST(TreeNode* root) {
        auto it = solve(root);
        return res;
    }
};