//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int ans(int arr[], int n, int ind, int prev_ind , vector<vector<int>> & dp)
	{
	    if(ind >= n){
	        return 0;
	    }
	    if(dp[ind][prev_ind+1] != -1)return dp[ind][prev_ind+1];
	    int take = INT_MIN;
	    if(prev_ind == -1 || arr[prev_ind] < arr[ind]){
	        take = arr[ind] + ans(arr,n,ind+1,ind ,dp);
	    }
	    int not_take = ans(arr,n,ind+1,prev_ind,dp);
	    return dp[ind][prev_ind+1] = max(take,not_take);
	}
	int maxSumIS(int arr[], int n)  
	{
	    vector<vector<int>> dp(n,vector<int>(n+1,-1));
	    return ans(arr,n,0,-1,dp);
	}  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends