//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	   // int fact(int n ,vector<int>& dp)
	   // {
	   //     if(n == 0|| n == 1)return 1;
	   //     if(dp[n] != -1)return dp[n];
	   //     return dp[n] = fact(n-1)* fact(n);
	   // }
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    set<string> rt;
		    vector<int> dp(S.size()+1,-1);
		    int n = S.size();
		  //  n = fact(n , dp);
		    unordered_map<int,int> mp;
		    for(int i = 0 ; i< S.size() ; i++)
		    {
		        mp[i] = 0;
		    }
		    string st;
		    ans(rt , st, mp , S);
		    vector<string> myVector;
            for (const auto& element : rt) {
                myVector.push_back(element);
            }
		    return myVector;
		}
		void ans(set<string>& rt , string& st , unordered_map<int,int>& mp , string& S)
		{
		    //Base Case
		    if(S.size() == st.size())
		    {
		        rt.insert(st);
		        return;
		    }
		    //Calculation
		    for(int i = 0 ; i< S.size() ; i++)
		    {
		        if(mp[i] == 0)
		        {
		            mp[i] = 1;
		            st.push_back(S[i]);
		            ans(rt , st, mp , S);
		            st.pop_back();
		            mp[i] = 0;
		        }
		    }
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends