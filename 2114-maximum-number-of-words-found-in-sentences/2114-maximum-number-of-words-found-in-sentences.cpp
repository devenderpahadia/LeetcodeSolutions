class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int mx = 0;
        for(int i=0;i<sentences.size();i++)
        {
            int ctr=0;
            for(int j=0;j<sentences[i].size();j++)
            {
                if(sentences[i][j]==' ')
                {
                    ctr++;
                }
            }
            mx = max(mx,ctr+1);
        }
        return mx;
    }
};