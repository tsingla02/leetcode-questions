//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  private:
    bool dfs(int node, int visited[], int pathvis[] , int check[], vector<int> adj[])
    {
        visited[node] = 1;
        pathvis[node] = 1;
        check[node] = 0;
        for(auto x : adj[node])
        {
            if(!visited[x])
            {
                if(dfs(x, visited, pathvis, check, adj))
                {
                    check[node] = 0;
                    return true;
                }
            }
            else if(pathvis[x])
            {
                check[node] = 0;
                return true;
            }
        }
        check[node] = 1;
        pathvis[node] = 0;
        return false;
    }
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        int visited[V] = {0};
        int pathvis[V] = {0};
        vector<int> safenodes;
        int check[V] = {0};
        for(int i = 0 ; i < V ; i++)
        {
            if(!visited[i])
            {
                dfs(i, visited, pathvis, check, adj);
            }
        }
        for(int i = 0 ;i < V ; i++)
        {
            if(check[i] == 1)safenodes.push_back(i);
        }
        return safenodes;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends