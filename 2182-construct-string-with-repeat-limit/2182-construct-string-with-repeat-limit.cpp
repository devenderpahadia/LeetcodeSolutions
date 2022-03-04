class Solution {
public:
    string repeatLimitedString(string s, int l) {
        vector<int>H(26,0);
        for(char c : s)
        {
            H[c-'a']++;
        }
        
        int x = s.size();
        string res = "";
        while(x)
        {
            for(int i=25;i>=0;i--)
            {
                int j = l;
                while(H[i] && j)
                {
                    res+=(i+'a');
                    H[i]--;
                    j--;
                    x--;
                }
                if(j==0 && H[i])
                {
                    for(int k=i-1;k>=0;k--)
                    {
                        if(H[k])
                        {
                            res+=(k+'a');
                            H[k]--;
                            x--;
                            break;
                        }
                    }
                    break;
                }
            }
        }
        cout<<res<<endl;
        char c = res[res.size()-1];
        int ctr=1;
        for(int i=res.size()-2;i>=0;i--)
        {
            if(res[i]==c)
                ctr++;
            else
                break;
        }
        cout<<ctr<<endl;
        ctr = ctr-l;
        if(ctr>0)
        {
            while(ctr--)
            res.pop_back();
        }
        return res;
    }
};