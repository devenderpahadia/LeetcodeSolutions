class Solution {
public:
    
    bool solve(int i,string s1,int j,string s2,int k,string s3,unordered_map<string,bool>&mp)
    {
        if(k==s3.size())
            return true;
        
        string temp = to_string(i)+"_"+to_string(j)+"_"+to_string(k);
        if(mp.find(temp)!=mp.end())
                return mp[temp];
        
        bool l = false,r=false;
        if(i<s1.size())
        {
            if(s1[i]==s3[k]){
                string temp1 = to_string(i+1)+"_"+to_string(j)+"_"+to_string(k+1);
                if(mp.find(temp1)!=mp.end())
                    l = mp[temp1];
                else
                    l = solve(i+1,s1,j,s2,k+1,s3,mp);
                    mp[temp1] = l;
            }
        }
        if(j<s2.size())
        {
            if(s2[j]==s3[k]){
                string temp2 = to_string(i)+"_"+to_string(j+1)+"_"+to_string(k+1);
                if(mp.find(temp2)!=mp.end())
                    r = mp[temp2];
                else
                    r = solve(i,s1,j+1,s2,k+1,s3,mp);
                    mp[temp2] = r;
            }
        }
        return mp[temp] = l || r;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size()!=s3.size())
            return false;
        if(s1.size()+s2.size()==0)
            return true;
        
//         int x = s1.size();
//         int y = s2.size();
//         int z = s3.size();
//         bool t[x+1][y+1][z+1];
//         t[0][0] = true;
        
//         for(int i=1;i<=x;i++){
//             if(s1[i-1]==s3[])
//             t[i][0]=false;
//         }
//         for(int i=1;i<=y;i++)
//             t[0][j]=false;
        
        unordered_map<string,bool>mp;
        return solve(0,s1,0,s2,0,s3,mp);
    }
};