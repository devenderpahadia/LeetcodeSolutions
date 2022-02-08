class Solution {
public:
    long long smallestNumber(long long num) {
        bool sign = false;
        string str = to_string(num);
        
        if(str[0]=='-')
        {
            sign = true;
        }
        long long res = 0;
        if(!sign)
        {
            sort(str.begin(),str.end());
            for(int i=0;i<str.size();i++)
            {
                if(str[i]>'0')
                {
                    swap(str[0],str[i]);
                    break;
                }
            }
            
            for(int i=0;i<str.size();i++)
            {
                res*=10;
                res+=(str[i]-'0');
            }
        }
        else
        {
            str.erase(str.begin()+0);
            sort(str.begin(),str.end());
            reverse(str.begin(),str.end());
            
            for(int i=0;i<str.size();i++)
            {
                res*=10;
                res+=(str[i]-'0');
            }
            
            res*=(-1);
        }
        
        return res;
    }
};