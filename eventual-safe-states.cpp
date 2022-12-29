//DFS APPROACH
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    bool dfs(int i,vector<int> graph[],vector<int>& visited,vector<int>& dfsVisited,vector<int>& check){
        visited[i] = 1;
        dfsVisited[i] = 1;

        for(int k:graph[i]){
            if(dfsVisited[k] && visited[k]){
                return false;
            }
            if(!visited[k]){
                bool ans = dfs(k,graph,visited,dfsVisited,check);
                if(!ans){
                    return false;
                }
            }
        }
        dfsVisited[i] = 0;
        check[i] = 1;
        return true;
    }
  
    vector<int> eventualSafeNodes(int n, vector<int> graph[]) {
        vector<int> visited(n,0);
        vector<int> dfsVisited(n,0);
        vector<int> res;
        vector<int> check(n,0);

        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,graph,visited,dfsVisited,check);
            }
        }
        for(int i=0;i<n;i++){
            if(check[i]){
                res.push_back(i);
            }
        }
        return res;
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


//BFS APPROACH
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> res;
        vector<vector<int>> transpose(n);

        for(int i=0;i<n;i++){
            for(int k:graph[i]){
                transpose[k].push_back(i);
            }
        }


        queue<int> q;
        vector<int> indegree(n,0);
        for(int i=0;i<n;i++){
            for(int k:transpose[i]){
                indegree[k]++;
            }
        }

        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int frontNode = q.front();
            q.pop();
            res.push_back(frontNode);
            for(int k:transpose[frontNode]){
                indegree[k]--;
                if(indegree[k]==0){
                    q.push(k);
                }
            }
        }
        sort(res.begin(),res.end());
        return res;

    }
};
