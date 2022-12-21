#include <bits/stdc++.h> 

void dfs(vector<int>& visited,unordered_map<int,list<int>>& adjList,int i,stack<int>& res){
    visited[i] = true;
    for(int k:adjList[i]){
        if(!visited[k]){
            dfs(visited,adjList,k,res);
        }
    }
    res.push(i);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    unordered_map<int,list<int>> adjList;
    for(vector<int> edge:edges){
        int u = edge[0];
        int v = edge[1];
        adjList[u].push_back(v);
    }
    
    vector<int> visited(v);
    for(int i=0;i<v;i++){
        visited[i] = 0;
    }
    stack<int> res;
    
    for(int i=0;i<v;i++){
        if(!visited[i]){
            dfs(visited,adjList,i,res);
        }
    }
    vector<int> ans;
    while(!res.empty()){
        ans.push_back(res.top());
        res.pop();
    }
    return ans;
    
}
