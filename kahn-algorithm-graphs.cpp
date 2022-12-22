#include <bits/stdc++.h> 

void bfs(vector<int>& visited,unordered_map<int,list<int>>&adjList,int i,vector<int>& indegree,int v,vector<int>& res){
    queue<int> q;
    for(int i=0;i<v;i++){
        if(indegree[i] == 0){
            q.push(i);
            visited[i] = true;
        }
    }
    while(!q.empty()){
        int frontNode = q.front();
        q.pop();
        visited[frontNode] = true;
        res.push_back(frontNode);
        for(int k:adjList[frontNode]){
            indegree[k]--;
            if(indegree[k] == 0){
                q.push(k);
            }
        }
    }
}


vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    unordered_map<int,list<int>> adjList;
    for(vector<int> edge:edges){
        int u = edge[0];
        int v = edge[1];
        adjList[u].push_back(v);
    }
    
    vector<int> visited(v);
    vector<int> res;
    
    for(int i=0;i<v;i++){
        visited[i] = 0;
    }
    vector<int> indegree(v);
    for(auto i:adjList){
        for(auto k:i.second){
            indegree[k]++;
        }
    }
    
    for(int i=0;i<v;i++){
        if(!visited[i]){
            bfs(visited,adjList,i,indegree,v,res);
        }
    }
    return res;
    
}
