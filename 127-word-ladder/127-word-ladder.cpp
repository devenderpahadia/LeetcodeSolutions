class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st;
        for(auto it : wordList)
            st.insert(it);
        
        if(st.find(endWord)==st.end())
            return 0;
        
        queue<string>q;
        q.push(beginWord);
        
        int res = 0;
        
        while(!q.empty())
        {
            res++;
            int sz = q.size();
            while(sz--)
            {
                string curr = q.front();
                q.pop();
                for(int i=0;i<curr.size();i++)
                {
                    string temp = curr;
                    for(char c = 'a';c<='z';c++)
                    {
                        temp[i]=c;
                        if(temp == curr)
                        {
                            continue;
                        }
                        if(temp == endWord)
                        {
                            return res+1;
                        }
                        
                        if(st.find(temp)!=st.end())
                        {
                            q.push(temp);
                            st.erase(temp);
                        }
                    }
                }
            }
        }
        return 0;
    }
};