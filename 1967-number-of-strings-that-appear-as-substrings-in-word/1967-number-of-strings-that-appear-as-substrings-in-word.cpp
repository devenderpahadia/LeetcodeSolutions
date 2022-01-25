class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int ctr=0;
        for(auto it : patterns)
        {
            if(word.find(it)!=-1)
                ctr++;
        }
        return ctr;
    }
};