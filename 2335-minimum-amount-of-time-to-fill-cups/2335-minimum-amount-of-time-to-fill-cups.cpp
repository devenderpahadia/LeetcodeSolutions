class Solution {
public:
    int fillCups(vector<int>& amount) {
        int ctr=0;
        int a = amount[0];
        int b = amount[1];
        int c = amount[2];
        priority_queue<int>minh;
        
        if(a!=0)
        minh.push(a);
        if(b!=0)
        minh.push(b);
        if(c!=0)
        minh.push(c);
        
        while(minh.size()>1){
            int x = minh.top();
            minh.pop();
            int y = minh.top();
            minh.pop();
            x--;
            y--;
            if(x!=0)
            minh.push(x);
            if(y!=0)
            minh.push(y);
            ctr++;
        }
        if(minh.size()) ctr+=minh.top();
        return ctr;
    }
};