class Solution {
public:
    vector<string> cellsInRange(string s) {
        char a = s[0];
        char b = s[3];
        char c = s[1];
        char d = s[4];
        // cout<<c<<" "<<d<<endl;
        vector<string>res;
        for(char i = a;i<=b;i++){
            for(char j=c;j<=d;j++){
                string str = "";
                str.push_back(i);
                str.push_back(j);
                res.push_back(str);
            }
        }
        return res;
        
    }
};