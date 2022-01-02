class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        sort(arr1.begin(),arr1.end());
        vector<int>vec = arr1;
        map<int,int>mp1;
        for(auto it : arr1)
        {
            mp1[it]++;
        }
        
        int i=0;
        for(int j=0;j<arr2.size();j++)
        {
            if(mp1.find(arr2[j])!=mp1.end())
            {
                while(mp1[arr2[j]]--)
                {
                    arr1[i++] = arr2[j];
                }
            }
            else{
                break;
            }
        }
        for(int j=0;j<vec.size();j++)
        {
            while(mp1[vec[j]]>0)
            {
                arr1[i++] = vec[j];
                mp1[vec[j]]--;
            }
        }
        return arr1;
        
    }
};