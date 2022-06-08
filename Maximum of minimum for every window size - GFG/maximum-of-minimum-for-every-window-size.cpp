// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

#include<bits/stdc++.h>
class Solution
{
    public:
    //Function to find maximum of minimums of every window size.
    
    vector<int>solve(int arr[],int n){
        
        vector<int>nsl(n);
        vector<int>nsr(n);
        
        stack<pair<int,int>>st;
        
        for(int i=0;i<n;i++){
            while(st.size() && st.top().first>=arr[i]) st.pop();
            if(st.size()) nsl[i] = (st.top().second);
            else nsl[i] = (-1);
            
            st.push({arr[i],i});
        }
        while(st.size()) st.pop();
        
        for(int i=n-1;i>=0;i--){
            while(st.size() && st.top().first>=arr[i]) st.pop();
            if(st.size()) nsr[i] = (st.top().second);
            else nsr[i] = (n);
            
            st.push({arr[i],i});
        }
        vector<int>res(n);
        for(int i=0;i<n;i++){
            res[i] = nsr[i]-nsl[i]-1;
        }
        return res;
    }
    vector <int> maxOfMin(int arr[], int n)
    {
        // Your code here
        vector<int>res;
        res = solve(arr,n);
        // return res;
        vector<int>ans(n,0);
        // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>>minh;
        
        for(int i=0;i<res.size();i++){
            if(ans[res[i]-1]==0){
                ans[res[i]-1] = arr[i];
            }
            else{
                ans[res[i]-1] = max(ans[res[i]-1],arr[i]);
            }
        }
        
        for(int i=n-2;i>=0;i--){
            ans[i] = max(ans[i],ans[i+1]);
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution ob;
        vector <int> res = ob.maxOfMin(a, n);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends