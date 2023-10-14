//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    int ans = INT_MIN;
    long long maxSubarraySum(int arr[], int n){
        
        long long int a = LLONG_MIN,  b = 0;
        for(int i = 0 ; i< n ; i++)
        {
            b = b + arr[i];
            if(a < b)
            {
                a = b;
            }
            if(b < 0)
            {
                b = 0;
            }
        }
        return a;
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}

// } Driver Code Ends