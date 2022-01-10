class Solution {
public:
    string addBinary(string a, string b) 
    {
        if(a.size()<b.size())
        {
            while(a.size()!=b.size())
            {
                a = '0'+a;
            }
        }
        else
        {
            while(a.size()!=b.size())
            {
                b = '0'+b;
            }
        }
        
        // cout<<a<<" "<<b<<endl;
        
        int n=a.size();
        string c = "";
        char carry = '0';
        for(int i=n-1;i>=0;i--)
        {
            if(a[i]=='1' && b[i]=='1')
            {
                if(carry=='1')
                {
                    carry='1';
                    c='1'+ c;
                }
                else
                {
                    carry = '1';
                    c = '0'+c; 
                }
                
            }
            else 
            {
                
                if(carry=='1')
                {
                    if(a[i]=='1' || b[i]=='1')
                    {
                        carry='1';
                        c='0'+c;
                    }
                    else
                    {
                        c='1'+c;
                        carry='0';
                    }
                }
                else
                {
                    if(a[i]=='1' || b[i]=='1')
                    {
                        carry='0';
                        c='1'+c;
                    }
                    else
                    {
                        c='0'+c;
                        carry='0';
                    }
                }
            }
        }
        if(carry=='1')
        {
            c='1'+c;
        }
        return c;
    }
};