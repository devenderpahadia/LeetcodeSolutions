class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1==s2)
            return true;
        
        if(s1.size()!=s2.size())
            return false;
        int i;
        char a , b;
        int ctr=0;
        for(i=0;i<s1.size();i++)
        {
            if(s1[i]!=s2[i])
            {
                a = s1[i];
                b = s2[i];
                break;
            }
        }
        for(int x=0;x<s1.size();x++)
        {
            if(s1[x]!=s2[x])
            {
                ctr++;
            }
        }
        cout<<ctr<<endl;
        if(ctr==0 || ctr==2)
        {
            
        }
        else
        {
            return false;
        }
        int j;
        for(j=i+1;j<s1.size();j++)
        {
            if(s1[j]!=s2[j])
            {
                if(s1[j]==b && s2[j]==a)
                {
                    return true;
                }
                else
                return false;
            }
        }
        
        
        return s1==s2;
    }
};