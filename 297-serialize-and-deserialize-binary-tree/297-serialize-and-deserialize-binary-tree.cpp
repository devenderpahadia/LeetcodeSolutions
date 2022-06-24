/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res = "";
        if(root==NULL) return res;
        queue<TreeNode*>q;
        q.push(root);
        res+=to_string(root->val);
        res+=',';
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                TreeNode* node = q.front();
                q.pop();
                if(node->left){
                    q.push(node->left);
                    string x = to_string(node->left->val);
                    res+=x+',';
                }
                else{
                    res+="#,";
                }
                if(node->right){
                    q.push(node->right);
                    string x = to_string(node->right->val);
                    res+=x+',';
                }
                else{
                    res+="#,";
                }
                
            }
        }
        res.pop_back();
        return res;
    }

    // Decodes your encoded data to tree.
    
    TreeNode* deserialize(string data) {
        if(data=="")
        return NULL;
        
        vector<string>res;
        stringstream checks(data);
        string temp;
        while(getline(checks,temp,','))
        {
            res.push_back(temp);
        }
        TreeNode* root = new TreeNode(stoi(res[0]));
        queue<TreeNode*>q;
        q.push(root);
        int i=1;
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(res[i]=="#"){
                node->left = NULL;
                i++;
            }
            else{
                node->left = new TreeNode(stoi(res[i++]));
                q.push(node->left);
            }
            if(res[i]=="#"){
                node->right = NULL;
                i++;
            }
            else{
                node->right = new TreeNode(stoi(res[i++]));
                q.push(node->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));