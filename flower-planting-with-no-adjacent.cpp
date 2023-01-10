class Solution {
public:

    bool isValid(int clr,vector<int>& res,int i,unordered_map<int,list<int>>& adjList){
        for(int it:adjList[i]){
            if(clr == res[it-1]){
                return false;
            }
        }
        return true;
    }

    void dfs(unordered_map<int,list<int>>& adjList, int i,vector<int>& visited,vector<int>& res){
        visited[i] = true;

        for(int clr=1;clr<=4;clr++){
            if(isValid(clr,res,i,adjList)){
                res[i-1] = clr;
                break;
            }
        }

        for(int k:adjList[i]){
            if(!visited[k]){
                dfs(adjList,k,visited,res);
            }
        }
    }

    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        unordered_map<int,list<int>> adjList;
        for(vector<int> path:paths){
            int u = path[0];
            int v = path[1];

            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        vector<int> visited(n+1,0);
        vector<int> res(n+1,0);
        unordered_map<int,bool> doneColors;

        for(int i=1;i<=n;i++){
            if(!visited[i]){
                dfs(adjList,i,visited,res);
            }
        }
        res.pop_back();
        return res;
    }
};
