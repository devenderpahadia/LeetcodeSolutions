class Solution {
public:
    string removeDigit(string number, char digit) {
        string res = "";
        for(int i=0;i<number.size();i++)
        {
            if(number[i]==digit)
            {
                string str = number;
                str.erase(str.begin()+i);
                res = max(res,str);
            }
        }
        
        return res;
    }
};