class LRUCache {
public:
    
    class node{
        public : 
            int key,val;
            node* prev;
            node* next;
            node(int k,int v){
                key = k;
                val = v;
            }
    };
    
    node* head = new node(-1,-1);
    node* tail = new node(-1,-1);
    int cap;
    unordered_map<int,node*>mp;
    
    LRUCache(int capacity) {
        head->next = tail;
        tail->prev = head;
        cap = capacity;
    }
    
    void addnode(node* n){
        node* temp = head->next;
        head->next = n;
        n->next = temp;
        temp->prev = n;
        n->prev = head;
    }
    
    void deletenode(node *n){
        n->prev->next = n->next;
        n->next->prev = n->prev;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            node* t = mp[key];
            mp.erase(key);
            int res = t->val;
            deletenode(t);
            addnode(t);
            mp[key] = head->next;
            return res;
        }
        
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            node* t = mp[key];
            mp.erase(key);
            deletenode(t);
        }
        if(mp.size()==cap){
            mp.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        addnode(new node(key,value));
        mp[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */