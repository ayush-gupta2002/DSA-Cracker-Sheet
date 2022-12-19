#include <bits/stdc++.h>

void prepareAdjList(unordered_map<int,list<int>>&adj,vector<vector<int>> &edges){
    for(vector<int> edge:edges){
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void dfs(unordered_map<int,list<int>>& adj,unordered_map<int,bool>& visited,vector<int>& ans,int i){
    ans.push_back(i);
    visited[i] = true;
    
    for(auto j:adj[i]){
        if(!visited[j]){
            dfs(adj,visited,ans,j);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    unordered_map<int,list<int>> adj;
    prepareAdjList(adj,edges);
    unordered_map<int,bool> visited;
    vector<vector<int>> res;
    
    for(int i=0;i<V;i++){
        if(!visited[i]){
            vector<int> ans;
            dfs(adj,visited,ans,i);
            res.push_back(ans);
        }
    }
    
    return res;
}
