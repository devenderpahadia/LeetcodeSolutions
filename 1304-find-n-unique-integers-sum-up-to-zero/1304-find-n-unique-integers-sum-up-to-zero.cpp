class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int>arr;
        if(n%2==1)
        {
            arr.push_back(0);
            n--;
        }
        int k=1;
        while(n)
        {
            arr.push_back(k);
            arr.push_back(-k);
            n-=2;
            k++;
        }
        return arr;
    }
};