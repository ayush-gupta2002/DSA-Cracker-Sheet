//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        vector<int> distance(V);
        for(int i=0;i<V;i++){
            distance[i] = 1e8;
        }
        distance[S] = 0;
        
        for(int i=1;i<=V;i++){
            for(vector<int> edge:edges){
                int u = edge[0];
                int v = edge[1];
                int w = edge[2];
                
                int currentDistance = distance[u] + w;
                if(currentDistance < distance[v] && distance[u] != 1e8){
                    distance[v] = currentDistance;
                }
            }
        }
        
        for(vector<int> edge:edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            
            int currentDistance = distance[u] + w;
            if(currentDistance < distance[v] && distance[u] != 1e8){
                vector<int> res;
                res.push_back(-1);
                return res;
            }
        }
        return distance;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, m;
        cin >> N >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src;
        cin >> src;

        Solution obj;
        vector<int> res = obj.bellman_ford(N, edges, src);

        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
