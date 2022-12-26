#include <bits/stdc++.h>
void topologicalSort(int i,unordered_map<int,bool>& visited, stack<int>& topo,unordered_map<int,list<int>>& adjList){
    visited[i] = true;
    
    for(int k:adjList[i]){
        if(!visited[k]){
            topologicalSort(k,visited,topo,adjList);
        }
    }
    topo.push(i);
}

void dfs(int frontNode,unordered_map<int,bool>& visited,unordered_map<int,list<int>>&transpose){
    visited[frontNode] = true;
    
    for(int k:transpose[frontNode]){
        if(!visited[k]){
            dfs(k,visited,transpose);
        }
    }
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
	unordered_map<int,list<int>> adjList;
    for(vector<int> edge:edges){
        int u = edge[0];
        int v = edge[1];
        adjList[u].push_back(v);
    }
    
    stack<int> topo;
    unordered_map<int,bool> visited;
    
    for(int i=0;i<v;i++){
        if(!visited[i]){
            topologicalSort(i,visited,topo,adjList);
        }
    }
    
    unordered_map<int,list<int>> transpose;
    for(auto i:adjList){
        for(int k:adjList[i.first]){
            transpose[k].push_back(i.first);
        }
    }
//     for(auto i:transpose){
//         cout << i.first << " --> ";
//         for(auto k:transpose[i.first]){
//             cout<<k<<" ";
//         }cout<<endl;
//     }
    
    int count = 0;
    for(int i=0;i<v;i++){
        visited[i] = false;
    }
    
    while(!topo.empty()){
        int frontNode = topo.top();
        topo.pop();
        if(!visited[frontNode]){
            count++;
            dfs(frontNode,visited,transpose);
        }
    }
    
    return count;
}
