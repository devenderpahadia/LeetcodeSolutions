class CustomStack {
public:
    int mx ;
    vector<int>arr;
    CustomStack(int maxSize) {
        mx = maxSize;
    }
    
    void push(int x) {
        if(arr.size()<mx)
        {
            arr.push_back(x);
        }
    }
    
    int pop() {
        if(arr.size()==0)
            return -1;
        int x = arr[arr.size()-1];
        arr.pop_back();
        return x ;
    }
    
    void increment(int k, int val) {
        for(int i=0;i<k && i<arr.size();i++)
        {
            arr[i]+=val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */