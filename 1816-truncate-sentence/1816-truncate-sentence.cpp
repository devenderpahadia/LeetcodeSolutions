class Solution {
public:
    string truncateSentence(string s, int k) {
        string str ="";
        string temp;
        stringstream check(s);
        while(getline(check,temp,' ') && k--)
        {
            str+=temp+' ';
        }
        str.pop_back();
        return str;
    }
};