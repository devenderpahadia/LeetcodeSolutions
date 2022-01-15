class Solution {
public:
    string thousandSeparator(int n) {
        string str = to_string(n);
        if(str.size()<=3)
            return str;
        for(int i=str.size()-3;i>0;i-=3)
        {
            str.insert(str.begin()+i,'.');
        }
        return str;
            
    }
};