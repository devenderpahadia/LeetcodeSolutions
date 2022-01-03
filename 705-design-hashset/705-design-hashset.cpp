class MyHashSet {
public:
    vector<int>H;
    MyHashSet() {
        vector<int>vec(1000001,0);
        H=vec;
    }
    
    void add(int key) {
        H[key]=1;
    }
    
    void remove(int key) {
        H[key]=0;
    }
    
    bool contains(int key) {
        return H[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */