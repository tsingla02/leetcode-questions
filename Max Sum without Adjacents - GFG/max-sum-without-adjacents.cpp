//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    // code here
	    vector<int> dp(n+1,-1);
	    return ans(arr ,n-1 , dp);
	}
	int ans(int *arr, int n , vector<int>& dp)
	{
	    if(n < 0)return 0;
	    if(dp[n] != -1)return dp[n];
	    if(n == 0)
	    {
	        return dp[n] = arr[0];
	        
	    }
	    return dp[n] = max( arr[n] + ans(arr, n-2, dp) , ans(arr , n -1 , dp));
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends