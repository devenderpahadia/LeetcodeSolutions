class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int i=1;
        for(int j=0;j<arr.size();)
        {
            if(arr[j]==i)
            {
                j++;
            }
            else
            {
                k--;
                if(k==0)
                    return i;
            }
            i++;
        }
        
        while(k--)
            i++;
        return i-1;
    }
};