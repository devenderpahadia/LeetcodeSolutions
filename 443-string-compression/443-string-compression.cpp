class Solution {
public:
    int compress(vector<char>& chars) {
        string str="";
        for(int i=0;i<chars.size();i++)
        {
            int ctr=0;
            if(i<chars.size())
            {
                char c = chars[i];
                while(i<chars.size() && c==chars[i] )
                {
                    ctr++;
                    i++;
                }
                if(ctr>1)
                {
                    str+=c;
                    str+=(to_string(ctr));
                    i--;
                }
                else
                {
                    str+=c;
                    i--;
                }   
            }
            else
                continue;
        }
        
        for(int i=0;i<str.size();i++)
        {
            chars[i] = str[i];
        }
        return str.size();
    }
};