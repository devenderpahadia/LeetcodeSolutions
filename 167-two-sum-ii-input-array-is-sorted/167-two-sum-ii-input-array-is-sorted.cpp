class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        int n = numbers.size();
        int l=0;
        int h=n-1;
        
        while(l<h)
        {
            if(numbers[l]+numbers[h] == target)
            {
                return {l+1,h+1};
            }
            else if(numbers[l]+numbers[h] < target)
            {
                l++;
            }
            else
            {
                h--;
            }
        }
        return {};
    }
};