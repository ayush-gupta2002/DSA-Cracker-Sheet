class Solution {
public:
    bool isCyclic(int i,vector<vector<int> >& adjList,vector<int>& visited){
        if(visited[i] == 2){
            return true;
        }
        visited[i] = 2;

        for(int k:adjList[i]){
            if(visited[k] != 1){
                bool res = isCyclic(k,adjList,visited);
                if(res){
                    return true;
                }
            }
        }
        visited[i] = 1;
        return false;
          
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        for(vector<int> prereq:prerequisites){
            int u = prereq[0];
            int v = prereq[1];
            adjList[u].push_back(v);
        }
        vector<int> visited(numCourses,0);
        for(int i=0;i<numCourses;++i){
            if(visited[i] == 0){
                bool res = isCyclic(i,adjList,visited);
                if(res){
                    return false;
                }
            }
        }
        return true;
    }
};
