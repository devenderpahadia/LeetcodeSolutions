class Solution {
public:
    bool checkZeroOnes(string s) {
        string o = "";
        string t = "";
        int num1=0;
        int num2 = 0;
        int n = s.size();
        while(n--)
        {
            o+='1';
        }
        while(o.size()>0)
        {
            if(s.find(o)!= -1)
            {
                num1 = o.size();
                break;
            }
            else
            {
                o.pop_back();
            }
        }
        n = s.size();
        while(n--)
        {
            t+='0';
        }
        while(t.size()>0)
        {
            if(s.find(t)!= -1)
            {
                num2 = t.size();
                break;
            }
            else
            {
                t.pop_back();
            }
        }
        return num1>num2;
    }
};