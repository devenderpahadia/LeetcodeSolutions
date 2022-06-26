// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
public:
    int countDistinctSubarray(int arr[], int n)
    {
        //code here.
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        int ctr=0;
        int i=0;
        unordered_map<int,int>mp1;
        for(int j = 0;j<n;j++){
            mp1[arr[j]]++;
            while(mp1.size()==mp.size()){
                ctr+=(n-j);
                mp1[arr[i]]--;
                if(mp1[arr[i]]==0){
                    mp1.erase(arr[i]);
                }
                i++;
            }
        }
        return ctr;
    }
};


// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;	
		cout<<ob.countDistinctSubarray(a,n)<<endl;
	}
	return 0;
}  // } Driver Code Ends