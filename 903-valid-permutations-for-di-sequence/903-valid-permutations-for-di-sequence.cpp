class Solution {
public:
    int numPermsDISequence(string S) {
        int n = S.length(), mod = 1e9 + 7, sum;
        vector<int> curr(n + 1, 1), next;
        for (int k = 0; k < n; k++)
        {
            next.assign(n + 1 - k, 0);
            sum = 0;
            if (S[k] == 'D')
                for (int i = n-k; i; i--)
                    next[i-1] = (next[i-1] + (sum = (sum + curr[i]) % mod)) % mod;
            else
                for (int i = 0; i < n-k; i++)
                    next[i] = (next[i] + (sum = (sum + curr[i]) % mod)) % mod;
            swap(curr, next);
            curr.pop_back();
        }
        return curr[0];
    }
};