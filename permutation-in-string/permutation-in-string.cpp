class Solution {
public:
    bool checkInclusion(string s1, string s2) 
    {
        int n=s2.size();
        int k=s1.size();
        if(k>n)
            return false;
        vector<int>H(256);
        vector<int>H1(256);
        for(int i=0;i<k;i++)
        {
            H[s1[i]]++;
        }
        int i=0;
        int j=0;
        while(j<n)
        {
            H1[s2[j]]++;
            if(j-i+1 < k)
            {
                j++;
            }
            else
            {
                if(H==H1)
                {
                    return true;
                }
                H1[s2[i]]--;
                i++;
                j++;
            }
        }
        return false;
    }
};