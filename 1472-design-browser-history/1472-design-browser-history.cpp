class BrowserHistory {
public:
    vector<string>his;
    int i;
    BrowserHistory(string homepage) {
        his.push_back(homepage);
        i=0;
        cout<<i<<endl;
    }
    
    void visit(string url) {
        int j=i+1;
        
        while(his.size()>j)
        {
            his.pop_back();
        }
        his.push_back(url);
        i = his.size()-1;
        cout<<i<<endl;
        
    }
    
    string back(int steps) {
        if(i-steps >=0)
        {
            i=i-steps;
        }
        else
        {
            i=0;
        }
        cout<<i<<endl;
        return his[i];
    }
    
    string forward(int steps) {
        if(i+steps<=his.size()-1)
        {
            i+=steps;
        }
        else
        {
            i=his.size()-1;
        }
        cout<<i<<endl;
        return his[i];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */