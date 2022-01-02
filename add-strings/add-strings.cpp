class Solution {
public:
    string addStrings(string num1, string num2) 
    {
        int n1 = num1.size();
        int n2 = num2.size();
        
        int i = n1-1;
        int j = n2-1;
        int c = 0;
        string res="";
        
        while(i>-1 || j>-1 || c)
        {
            int curr = c;
            
            if(i>=0)
            {
                curr+=num1[i]-'0';
            }
            if(j>=0)
            {
                curr+=num2[j]-'0';
            }
            
            c= curr/10;
            curr = curr%10;
            res = (char)(curr+'0')+res;
            i--;
            j--;
        }
        
        return res;
        
    }
};