class Solution {
public:
    vector<int> constructRectangle(int area) {
        vector<int>vec;
        int i=1;
        while(i<=sqrt(area))
        {
            if(area%i == 0)
            {
                vec.push_back(i);
            }
            i++;
        }
        vector<int>arr = {vec[vec.size()-1],area/vec[vec.size()-1]};
        sort(arr.begin(),arr.end());
        reverse(arr.begin(),arr.end());
        return arr;
    }
};