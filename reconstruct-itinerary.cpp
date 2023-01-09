class Solution {
public:

    void dfs(unordered_map<string,priority_queue<string, vector<string>, greater<string>>>& adjList, string currentDest,vector<string>& res){
        while(!adjList[currentDest].empty()){
            string str = adjList[currentDest].top();
            adjList[currentDest].pop();
            dfs(adjList,str,res);
        }
        res.push_back(currentDest);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,priority_queue<string, vector<string>, greater<string>>> adjList;
        for(vector<string> ticket:tickets){
            string u = ticket[0];
            string v = ticket[1];

            adjList[u].push(v);
        }

        vector<string> res;

        dfs(adjList, "JFK",res);
        reverse(res.begin(),res.end());
        return res;
    }
};
