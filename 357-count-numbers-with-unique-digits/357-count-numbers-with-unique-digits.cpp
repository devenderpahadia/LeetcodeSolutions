class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int arr[n+1];
        arr[0] = 1;
        for(int i=1;i<=n;i++)
        {
            int count = 9;
            int ctr = i-1;
            int x = 9;
            while(ctr--)
            {
                count*=x;
                x--;
            }
            count+=arr[i-1];
            arr[i] = count ;
        }
        return arr[n];
    }
};