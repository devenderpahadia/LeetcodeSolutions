class Solution {
public:
    string removeDigit(string number, char digit) {
        set<string>st;
        
        for(int i=0;i<number.size();i++)
        {
            if(number[i]==digit)
            {
                string str = number;
                str.erase(str.begin()+i);
                st.insert(str);
            }
        }
        
        return *--st.end();
    }
};