class Solution {
public:
    class Node{
        public:
            Node* links[26];
            int pre = 0;
            bool containskey(char c){
                return links[c-'a']!=NULL;
            }
            void put(char c,Node* n){
                links[c-'a'] = n;
            }
            Node* get(char c){
                return links[c-'a'];
            }
    };
    
    
    class Trie{
        public:
            Node* root;
            Trie(){
                root = new Node();
            }
            void insert(string str){
                Node* node = root;
                for(auto it : str){
                    if(!node->containskey(it)){
                        node->put(it,new Node());
                        node= node->get(it);
                        (node->pre)++;
                    }
                    else{
                        node= node->get(it);
                        (node->pre)++;
                    }
                    
                }
                
            }
            string search(string str,int n){
                string res="";
                Node* node = root;
                for(auto it : str){
                    if(node->containskey(it)){
                        node = node->get(it);
                        if(node->pre == n){
                            res+=it;
                        }
                        else return res;
                    }
                    else return res;
                }
                return res;
            }
    };
    
    
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        Trie *obj = new Trie();
        for(auto it : strs) obj->insert(it);
        return obj->search(strs[0],n);
    }
};