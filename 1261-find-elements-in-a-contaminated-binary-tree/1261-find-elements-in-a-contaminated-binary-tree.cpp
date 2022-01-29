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
class FindElements {
public:
    
    unordered_set<int>st;
    
    void solve(TreeNode* root,int x)
    {
        if(root==NULL)
            return;
        st.insert(x);
        solve(root->left,2*x+1);
        solve(root->right,2*x+2);
    }
    
    FindElements(TreeNode* root) {
        root->val=0;
        solve(root,0);
        
    }
    
    bool find(int target) {
        return st.find(target)!=st.end();
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */