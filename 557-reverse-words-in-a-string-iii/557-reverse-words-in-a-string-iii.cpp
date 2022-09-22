class Solution {
public:
    string reverseWords(string s) 
    {
        vector<string>res;
        stringstream check(s);
        string temp;
        
        while(getline(check,temp,' '))
        {
            res.push_back(temp);
        }
        
        string ans = "";
        
        for(auto it : res)
        {
            reverse(it.begin(),it.end());
            ans+=it;
            ans+=" ";
        }
        ans.pop_back();
        return ans;
    }
};