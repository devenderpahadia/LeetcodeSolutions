struct Node{
    Node* links[2];
    bool containsKey(int c){
        return links[c]!=NULL;
    }
    void put(int c,Node* node){
        links[c] = node;
    }
    Node* get(int c){
        return links[c];
    }
};

class Trie{
    Node* root;
    public:
        Trie(){
            root = new Node();
        }
        void insert(int c){
            Node* node = root;
            for(int i=31;i>=0;i--){
                int setb = (c>>i)&1;
                if(!node->containsKey(setb)){
                    node->put(setb,new Node());
                }
                node = node->get(setb);
            }
        }
        int findMax(int x){
            Node* node = root;
            int mx = 0;
            for(int i=31;i>=0;i--){
                int setb = (x>>i)&1;
                if(node->containsKey(!setb)){
                    mx = mx | (1<<i);
                    node=node->get(!setb);
                }
                else if(node->get(setb)!=NULL) node = node->get(setb);
                else return -1;
            }
            return mx;
        }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        Trie obj;
        vector<vector<int>>q;
        vector<int>res(queries.size());
        for(int i=0;i<queries.size();i++){
            q.push_back({queries[i][1],queries[i][0],i});
        }
        int j=0;
        sort(q.begin(),q.end());
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<q.size();i++){
            int mx = -1;
            int x = q[i][1];
            int m = q[i][0];
            int idx = q[i][2];
            for(;j<nums.size();j++){
                if(nums[j]<=m){
                    obj.insert(nums[j]);
                }
                else break;
            }
            // cout<<x<<endl;
            // if(x!=8)
            mx = max(mx,obj.findMax(x));
            res[idx] = mx;
        }
        // obj.clear();
        return res;
    }
};