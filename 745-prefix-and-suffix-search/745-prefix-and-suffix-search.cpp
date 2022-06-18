class WordFilter {
public:
    vector<string>dict;
    class Node{
        public:
            Node* links[27];
            int idx;
            bool iscontains(char c){
                return links[c]!=NULL;
            }
            void put(char c,Node* n){
                links[c] = n;
            }
            Node* get(char c){
                return links[c];
            }
    };
    
    class Trie{
        public:
            Node* root;
            Trie(){
                root = new Node();
            }
            void insert(string str,int i){
                Node* node = root;
                for(auto it : str){
                    if(!node->iscontains(it-'a')){
                        node->put(it-'a',new Node());
                    }
                    node = node->get(it-'a');
                    node->idx = i;
                }
            }
            int startswith(string str){
                Node* node = root;
                for(auto it : str){
                    if(!node->iscontains(it-'a')){
                        return -1;
                    }
                    node = node->get(it-'a');
                }
                return node->idx;
            }
    };
    Trie* obj;
    WordFilter(vector<string>& words) {
        obj= new Trie();
        int n = words.size();
        for(int i=0;i<n;i++){
            string curr = words[i];
            for(int j=0;j<curr.size();j++){
                string str = curr.substr(j)+'{'+curr;
                obj->insert(str,i);
            }
        }
    }
    
    int f(string prefix, string suffix) {
        string curr = suffix+'{'+prefix;
        return obj->startswith(curr);
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */