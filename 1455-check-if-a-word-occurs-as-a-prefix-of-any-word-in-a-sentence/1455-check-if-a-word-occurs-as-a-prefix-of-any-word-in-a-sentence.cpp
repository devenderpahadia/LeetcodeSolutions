class Solution {
public:
    int isPrefixOfWord(string sentence, string pref) {
        vector<string>res;
        stringstream checks(sentence);
        string temp;
        while(getline(checks,temp,' '))
        {
            res.push_back(temp);
        }
        int k=0;
        for(auto it : res)
        {
            k++;
            if(it.size()<pref.size())
                continue;
            
            if(it.substr(0,pref.size())==pref)
                return k;
        }
        return -1;
    }
};