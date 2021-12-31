class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_map<string,int>mp;
        
        vector<string>trans = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        for(int i=0;i<words.size();i++)
        {
            string temp = "";
            for(int j=0;j<words[i].size();j++)
            {
                temp+=trans[words[i][j] - 'a'];
            }
            mp[temp]++;
        }
        
        return mp.size();
    }
};