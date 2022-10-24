class Solution {
public:
    int maxLength(vector<string>& arr) 
    {
        vector<string>res = {""};
        int x = 0;
        for(string it : arr)
        {
            int len = res.size();
            for(int i=0;i<len;i++)
            {
                string str = res[i]+it;
                unordered_set<char>newset(str.begin(),str.end());
                if(str.size()!=newset.size())
                    continue;
                res.push_back(str);
                x=max(x,(int)str.size());
            }
        }
        return x;
    }
};