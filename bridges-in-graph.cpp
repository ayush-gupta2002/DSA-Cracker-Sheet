#include <bits/stdc++.h>

void dfs(int timer,vector<int>& disc,vector<int>& low,int parent,vector<int>&visited,int i,vector<vector<int> >&res,unordered_map<int,list<int> >&adjList){
    visited[i] = true;
    
    disc[i] = timer;
    low[i] = timer;
    timer++;
    
    for(int k:adjList[i]){
        if(k == parent){
            continue;
        }
        if(!visited[k]){
            dfs(timer,disc,low,i,visited,k,res,adjList);
            low[i] = min(low[i],low[k]);
            if(low[k] > disc[i]){
                vector<int> ans;
                ans.push_back(i);
                ans.push_back(k);
                res.push_back(ans);
            }
        }
        else{
            low[i] = min(low[i],disc[k]);
        }
    }
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    
    unordered_map<int,list<int>> adjList;
    for(vector<int> edge:edges){
        int u = edge[0];
        int v = edge[1];
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    
    int timer = 0;
    vector<int> disc(v);
    vector<int> low(v);
    vector<int> visited(v);
    int parent = -1;
    for(int i=0;i<v;i++){
        disc[i] = -1;
        low[i] = -1;
        visited[i] = 0;
    }
    vector<vector<int> > res;
    for(int i=0;i<v;i++){
        if(visited[i] == 0){
       dfs(timer,disc,low,parent,visited,i,res,adjList);
        }
    }
    
    return res;
}
