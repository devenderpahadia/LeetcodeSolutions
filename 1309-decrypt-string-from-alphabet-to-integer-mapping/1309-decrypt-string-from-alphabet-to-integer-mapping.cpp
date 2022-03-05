class Solution {
public:
    string freqAlphabets(string s) {
        string res = "";
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='#')
            {
                res.pop_back();
                res.pop_back();
                string temp = "";
                temp+=s[i-2];
                temp+=s[i-1];
                res+=('a'+stoi(temp)-1);
            }
            else
            {
                res+=('a'+(s[i]-'0')-1);
            }
        }
        return res;
    }
};