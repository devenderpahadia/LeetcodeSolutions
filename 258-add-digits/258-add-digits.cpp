class Solution {
public:
    int addDigits(int num) {
        string str = to_string(num);
        while(str.size()!=1)
        {
            int n = 0;
            for(int i=0;i<str.size();i++)
            {
                n+=(str[i]-'0');
            }
            str=to_string(n);
        }
        return stoi(str);
    }
};