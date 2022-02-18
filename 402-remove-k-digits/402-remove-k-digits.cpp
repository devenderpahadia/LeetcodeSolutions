class Solution {
public:
    string removeKdigits(string num, int k) {
        
        if(num.size()<=k)
           return "0";
        
        for(int i=1;i<num.size();)
        {
            if(i>0 && num[i-1]>num[i] && k>0)
            {
                num.erase(num.begin()+i-1);
                i--;
                k--;
            }
            else
                i++;
        }
        
        while(num.size()>0 && k)
        {
            num.erase(num.begin()+num.size()-1);
            k--;
        }
        
        while(num[0]=='0')
        {
            num.erase(num.begin()+0);
        }
        
        if(num.size()==0)
            return "0";
        
        return num;
    }
};