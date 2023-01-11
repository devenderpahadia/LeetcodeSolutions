//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long int minIncrements(vector<int> arr, int N) {
        // Code here
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto i:arr){
            pq.push(i);
        }
        int n=0;
        while(pq.size()){
            int x=pq.top();
            pq.pop();
            while(pq.size() && x==pq.top()){
                int y=pq.top()+1;
                pq.pop();
                pq.push(y);
                n++;
            }
        }
        return n;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minIncrements(arr, N) << endl;
    }
}
// } Driver Code Ends