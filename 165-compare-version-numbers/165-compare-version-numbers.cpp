class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<string>res;
        stringstream check(version1);
        string temp;
        while(getline(check,temp,'.'))
        {
            res.push_back(temp);
        }
        
        vector<string>tes;
        stringstream checks(version2);
        while(getline(checks,temp,'.'))
        {
            tes.push_back(temp);
        }
        vector<int>ver1;
        vector<int>ver2;
        for(auto it : res)
        {
            // cout<<it<<endl;
            ver1.push_back(stoi(it));
        }
        // cout<<"dev"<<endl;
        for(auto it : tes)
        {
            // cout<<it<<endl;
            ver2.push_back(stoi(it));
        }
        int sum1 = 0;
        for(auto it : ver1)
        {
            sum1+=it;
        }
        int sum2 = 0;
        for(auto it : ver2)
        {
            sum2+=it;
        }
        for(int i=0;i<min(ver1.size(),ver2.size()) ;i++)
        {
            // cout<<ver1[i]<<" "<<ver2[i]<<endl;
            if(ver1[i]<ver2[i])
            {
                return -1;
            }
            if(ver1[i]>ver2[i])
            {
                return 1;
            }
        }
        
        if(sum1<sum2)
            return -1;
        if(sum1>sum2)
            return 1;
        
        return 0;
    }
};