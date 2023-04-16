//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    
    void traversal(int node, vector<bool>& vis, vector<int> adj_g[])
    {
        vis[node]= 1;
        
        for(auto it : adj_g[node])
        {
            if(!vis[it])
            {
                traversal(it, vis, adj_g);
            }
        }
    }
    
    
    int numProvinces(vector<vector<int>> adj, int V) {
        vector<int> adj_g[V];
        for(int i = 0 ; i < V ; i++)
        {
            for(int j = 0 ; j< V ; j++)
            {
                if(adj[i][j] == 1 && i!=j)
                {
                    adj_g[i].push_back(j);
                }
            }
        }
        vector<bool> vis(V,0);
        int count=0;
        for(int i = 0 ; i< V ;i++)
        {
            if(!vis[i])
            {
                traversal(i,vis, adj_g);
                count++;
            }
        }
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends