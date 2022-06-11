// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
        void nullPoints(int n, double magnets[], double getAnswer[])
    {
        // Your code goes here   
        for(int i=0;i<n-1;i++)
        {
            double low = magnets[i];
            double high = magnets[i+1];
            while(low<=high)
            {
                double mid = low +(high-low)/2;
                double left = 0.00,right = 0.00;
                for(int j=i+1;j<n;j++)  left += (1/(magnets[j]-mid));
                    
                for(int j=i;j>=0;j--) right += (1/(mid-magnets[j]));
                    
                if((abs(right-left)<0.000001))
                {
                 getAnswer[i] = mid;
                break;
                }
                else if(left<right) low = mid;
                else  high = mid; 
            }
        }
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
        double magnets[n], getAnswer[n];
        for(int i=0;i<n;i++)
        cin>>magnets[i];
        Solution ob;
        ob.nullPoints(n, magnets, getAnswer);
        
        for(int i=0; i<n-1; i++)
            printf("%0.2lf ",getAnswer[i]);
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends