class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        
        for(int i=0;i<boxTypes.size();i++)
            reverse(boxTypes[i].begin(),boxTypes[i].end());
        
        sort(boxTypes.begin(),boxTypes.end());
        
        for(int i=0;i<boxTypes.size();i++)
            reverse(boxTypes[i].begin(),boxTypes[i].end());
        
        reverse(boxTypes.begin(),boxTypes.end());
        
        for(auto it : boxTypes)
        {
            cout<<it[0]<<" "<<it[1]<<endl;
        }
        
        
        int x = 0;
        int sum = 0;
        for(int i=0;i<boxTypes.size();i++)
        {
            if(boxTypes[i][0]+x <= truckSize)
            {
                x+=boxTypes[i][0];
                sum+=(boxTypes[i][0]*boxTypes[i][1]);
                cout<<x<<endl;
            }
            else
            {
                sum+=((truckSize-x)*boxTypes[i][1]);
                break;
            }
        }
        return sum;
    }
};