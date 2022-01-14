class Solution {
public:
    bool areNumbersAscending(string s) {
        vector<string>res;
        stringstream check(s);
        string temp;
        
        while(getline(check,temp,' '))
        {
            res.push_back(temp);
        }
        int prev = -1;
        
        for(auto it : res)
        {
            if(it[0]>='0' && it[0]<='9')
            {
                int t = stoi(it);
                if(prev<t)
                {
                    prev = t;
                    continue;
                }
                else
                {
                    return false;
                }
            }
        }
        
        return true;
    }
};