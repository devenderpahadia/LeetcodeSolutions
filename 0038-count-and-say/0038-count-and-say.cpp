class Solution {
public:
    string countAndSay(int n) 
    {
        if(n==1)
        {
            return "1";
        }
        if(n==2)
        {
            return "11";
        }
        string str="11";
        for(int i=3;i<=n;i++)
        {
            string res="";
            int ctr=1;
            str+='#';
            
            for(int i=0;i<str.size()-1;i++)
            {
                if(str[i]==str[i+1])
                {
                    ctr++;
                }
                else
                {
                    res+=to_string(ctr);
                    res+=str[i];
                    ctr=1;                    
                }
            }
            str=res;
        }
        return str;
    }
};