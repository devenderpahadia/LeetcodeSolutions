class Solution {
public:
    string sortSentence(string s) {
        vector<string>res;
        string temp;
        stringstream check(s);
        while(getline(check,temp,' '))
        {
            res.push_back(temp);
        }
        map<int,string>mp;
        
        for(int i=0;i<res.size();i++)
        {
            mp[res[i][res[i].size()-1]-'0'] = res[i].substr(0,res[i].size()-1);
        }
        
        string ans = "";
        
        for(auto it : mp)
        {
            ans+=(it.second)+' ';
        }
        ans.pop_back();
        
        return ans;
    }
};