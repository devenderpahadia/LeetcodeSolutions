//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> asteroidCollision(int N, vector<int> &asteroids) {
        // code here
        stack<int> st;
        for(auto it: asteroids) {
            if (it > 0) {
                st.push(it);
            } else {
                bool isDestroyed = false;
                while(!st.empty() && st.top() > 0 && !isDestroyed) {
                    auto top = st.top();
                    if (top > abs(it)) {
                        isDestroyed = true;
                    } else if (top < abs(it)) {
                        st.pop();
                    } else {
                        st.pop();
                        isDestroyed = true;
                    }
                }
                
                if (!isDestroyed) st.push(it);
            }
        }
        
        vector<int> ans;
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> asteroids(N);
        for (int i = 0; i < N; i++) cin >> asteroids[i];

        Solution obj;
        vector<int> ans = obj.asteroidCollision(N, asteroids);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends