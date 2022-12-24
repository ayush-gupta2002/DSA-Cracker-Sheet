#include <bits/stdc++.h>

bool cmp(vector<int>&a,vector<int>&b){
    return a[2] < b[2];
}

void makeSet(vector<int>& parent,vector<int>& rank,int n){
    for(int i=0;i<n;i++){
        rank[i] = 0;
        parent[i] = i;
    }
}

int findParent(vector<int>& parent,int i){
    if(parent[i] == i){
        return i;
    }
    return parent[i] = findParent(parent,parent[i]);
}

bool isSameComponent(int u,int v,vector<int>&parent){
    if(findParent(parent,u) == findParent(parent,v)){
        return true;
    }
    return false;
}

void unionSet(vector<int>& parent,int u,int v,vector<int>&rank){
    int uParent = findParent(parent,u);
    int vParent = findParent(parent,v);
    
    int uParentRank = rank[uParent];
    int vParentRank = rank[vParent];
    
    if(uParentRank < vParentRank){
        parent[uParent] = vParent;
        rank[vParent] ++; 
    }
    else if(uParentRank > vParentRank){
        parent[vParent] = uParent;
        rank[uParent] ++;
    }
    else{
        parent[vParent] = uParent;
        rank[uParent]++;
        
    }
}

int minimumSpanningTree(vector<vector<int>>& edges, int n)
{
  vector<int> parent(n);
    vector<int> rank(n);
    makeSet(parent,rank,n);
    
    sort(edges.begin(),edges.end(),cmp);
    int res = 0;
    for(int i=0;i<edges.size();i++){
        int u = edges[i][0];
        int v = edges[i][1];
        
        if(!isSameComponent(u,v,parent)){
            res += edges[i][2];
            unionSet(parent,u,v,rank);
        }
    }
    
    return res;
}
