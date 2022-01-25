class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int flag=0;
        int i;
        for(i=1;i<arr.size();i++)
        {
            if(arr[i-1]<arr[i])
            {
                continue;
            }
            else if(arr[i-1]==arr[i])
            {
                return false;
            }
            else
            {
                flag=1;
                break;
            }
        }
        if(flag==0) return false;
        flag=0;
        for(int j=1;j<arr.size();j++)
        {
            if(arr[j-1]>arr[j])
            {
                continue;
            }
            else
            {
                flag=1;
                break;
            }
        }
        if(flag==0) return false;
        for(;i<arr.size();i++)
        {
            if(arr[i-1]>arr[i])
            {
                continue;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};