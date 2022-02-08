class Bitset {
public:
    string str = "";    
    bool flips;
    int nfb,nfo;
    Bitset(int size) {
        while(size--)
        {
            str+='0';
        }
        flips = false;
        nfb=str.size();
        nfo=0;
    }
    
    void fix(int idx) {
        if(!flips && str[idx]=='0')
        {
            str[idx]='1';
            nfo++;
        }
        if(flips && str[idx]=='1')
        {
            str[idx]='0';
            nfo++;
        }
    }
    
    void unfix(int idx) {
        if(!flips && str[idx]=='1')
        {
            str[idx]='0';
            nfo--;
        }
        if(flips && str[idx]=='0')
        {
            str[idx]='1';
            nfo--;
        }
    }
    
    void flip() {
        
        flips = !flips;
        nfo = nfb-nfo;
    }
    
    bool all() {
        return nfo==nfb;
    }
    
    bool one() {
        return nfo>=1;
    }
    
    int count() {
        return nfo;
    }
    
    string toString() {
        
        if(!flips)
            return str;
        else
        {
            string ans = str;
            for(int i=0;i<nfb;i++)
            {
                ans[i] = (ans[i]=='1')?'0':'1';
            }
            return ans;
        }
        return str;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */