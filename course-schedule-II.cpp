class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,list<int> > adjList;

        for(vector<int> prereq:prerequisites){
            int u = prereq[0];
            int v = prereq[1];
            adjList[v].push_back(u);
        }

        vector<int> indegree(numCourses,0);
        for(auto i:adjList){
            for(int k:i.second){
                indegree[k]++;
            }
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        vector<int> res;
        while(!q.empty()){
            int frontNode = q.front();
            q.pop();
            res.push_back(frontNode);
            for(int k:adjList[frontNode]){
                indegree[k]--;
                if(indegree[k] == 0){
                    q.push(k);
                }
            }
        }
        if(res.size() != numCourses){
            vector<int> ans;
            return ans;
        }
        return res;

    }
};
