class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int ctr=0;
        unordered_map<char,int>mp;
        for(auto it : chars)
        {
            mp[it]++;
        }
        for(auto it : words)
        {
            unordered_map<char,int>temp;
            for(int i=0;i<it.size();i++)
            {
                temp[it[i]]++;
            }
            bool flag = true;
            for(int i=0;i<it.size();i++)
            {
                if(mp.find(it[i])==mp.end() || temp[it[i]]>mp[it[i]])
                {
                    flag=false;
                    break;
                }
            }
            if(flag)
            {
                ctr+=it.size();
            }
        }
        return ctr;
    }
};