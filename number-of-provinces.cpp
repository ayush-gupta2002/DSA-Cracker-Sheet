class Solution {
public:

    void dfs(int i,unordered_map<int,bool>& visited,unordered_map<int,list<int> >&adjList){
        visited[i] = true;

        for(int k:adjList[i]){
            if(!visited[k]){
                dfs(k,visited,adjList);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_map<int,list<int>> adjList;
        for(int i=0;i<isConnected.size();i++){
            for(int j=0;j<isConnected[i].size();j++){
                if(isConnected[i][j] == 1 && i!=j){
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }
        unordered_map<int,bool> visited;
        int res = 0;

        for(int i=0;i<isConnected.size();i++){
            if(!visited[i]){
                res++;
                dfs(i,visited,adjList);
            }
        }
        return res;

    }
};
