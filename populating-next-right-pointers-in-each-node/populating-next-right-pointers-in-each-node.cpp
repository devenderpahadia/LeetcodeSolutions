/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL)
            return root;
        vector<vector<Node*>>vec;
        queue<Node*>q;
        q.push(root);
        while(!q.empty())
        {
            int sz = q.size();
            vector<Node*>temp;
            while(sz--)
            {
                Node* nd = q.front();
                q.pop();
                temp.push_back(nd);
                if(nd->left)
                {
                    q.push(nd->left);
                }
                if(nd->right)
                {
                    q.push(nd->right);
                }
            }
            vec.push_back(temp);
        }
        
        for(int i=0;i<vec.size();i++)
        {
            for(int j=0;j<vec[i].size()-1;j++)
            {
                vec[i][j]->next = vec[i][j+1];
            }
            vec[i][vec[i].size()-1]->next = NULL;
        }
        return root;
    }
};