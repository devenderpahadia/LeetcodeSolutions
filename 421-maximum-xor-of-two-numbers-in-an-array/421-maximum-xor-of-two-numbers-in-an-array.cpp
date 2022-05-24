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
            int setb = (c>>i) & 1;
            if(!node->containsKey(setb)){
                node->put(setb,new Node());
            }
            node = node->get(setb);
        }
    }
    int findmax(int x){
        Node* node = root;
        int mx = 0;
        for(int i=31;i>=0;i--){
            int setb = (x>>i)&1;
            if(node->containsKey(!setb)){
                mx = mx | (1<<i);
                node = node->get(!setb);
            }
            else node = node->get(setb); 
        }
        return mx;
    }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie obj;
        for(auto it : nums){
            obj.insert(it);
            // cout<<it<<endl;
        }
        int res = 0;
        for(auto it : nums){
            res = max(res,obj.findmax(it));
        }
        return res;
    }
};