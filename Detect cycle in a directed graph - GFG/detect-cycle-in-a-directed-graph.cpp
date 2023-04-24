//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
    bool dfs(int node,int pathvis[], int visited[] , vector<int> adj[])
    {
        visited[node] = 1;
        pathvis[node] = 1;
        for(auto x: adj[node])
        {
            if(pathvis[x])return true;
            else if(!visited[x])
            {
                if(dfs(x,pathvis, visited, adj))return true;
            }
        }
        pathvis[node] = 0;
        return false;
    }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        int visited[V] = {0};
        int pathvis[V] = {0};
        for(int i = 0 ; i< V ; i++)
        {
            if(!visited[i])if(dfs(i,pathvis, visited, adj))return true;
        }
        return false;
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
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends