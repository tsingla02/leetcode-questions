//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    
    int flag = 0;
    void bfs(int i, vector<int>& visited, vector<int> adj[])
    {
        queue<pair<int,int>>q;
        q.push({i,-1});
        visited[i] = 1;
        while(!q.empty())
        {
            int node = q.front().first;
            int prev = q.front().second;
            q.pop();
            for(auto x : adj[node])
            {
                if(x != prev )
                {
                    if(visited[x])flag = 1;
                    else
                    {
                        q.push({x, node});
                        visited[x] = 1;
                    }
                }
            }
        }
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int> visited(V,0);
        
        for(int i = 0 ; i< V ; i++)
        {
            if(!visited[i])
            {
                bfs(i , visited, adj);
            }
        }
        if (flag == 1)return 1;
        return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends