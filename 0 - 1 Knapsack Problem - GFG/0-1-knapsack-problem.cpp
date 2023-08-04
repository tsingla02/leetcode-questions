//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int ans(int W, int wt[], int val[] , int n, int ind,vector<vector<int>> &dp)
    {
        if(ind >= n){
            return 0;
        }
        if(dp[W][ind] != -1)return dp[W][ind];
        int take = INT_MIN ;
        if(W >= wt[ind]){
            take = val[ind] + ans(W- wt[ind] ,wt, val , n , ind+1, dp);
        }
        int not_take = ans(W,wt, val , n , ind+1,dp);
        return dp[W][ind] = max(take,not_take);
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>> dp(W+1,vector<int>(n,-1));
       return ans(W,wt,val, n, 0 , dp);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends