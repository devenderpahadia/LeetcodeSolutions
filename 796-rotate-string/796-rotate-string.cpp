class Solution {
public:
    
    
    bool rotateString(string s, string goal) {
        if(s==goal)
            return true;
        
        if(s.size()!=goal.size())
            return false;
        
        for(int i=0;i<s.size();i++)
        {
            
            if(s[i]==goal[0])
            {
                bool flag = true;
                int k = i;
                for(int j=0;j<goal.size();j++)
                {
                    if(s[k]==goal[j])
                    {
                        k=(k+1)%(s.size());
                        continue;
                    }
                    else
                    {
                        flag = false;
                        break;
                    }
                }
                if(flag)
                return true;
            }
        }
        return false;
    }
};