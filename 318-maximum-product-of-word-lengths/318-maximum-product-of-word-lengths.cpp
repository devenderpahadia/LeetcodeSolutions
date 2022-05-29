class Solution {
public:
    int maxProduct(vector<string>& words) {
        int mx = 0;
        
        for(int i=0;i<words.size();i++)
        {
            unordered_set<char>st;
            for(auto it : words[i])
                st.insert(it);
            
            for(int j=i+1;j<words.size();j++)
            {
                int flag = 1;
                for(int k = 0;k<words[j].size();k++)
                {
                    if(st.find(words[j][k])!=st.end())
                    {
                        flag = 0;
                        break;
                    }
                }
                if(flag)
                {
                    mx = max(mx,(int)words[i].size()*(int)words[j].size());
                }
            }
        }
        return mx;
    }
};