//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
        vector<int> minimumTime(int n,vector<vector<int>> &edges,int m)
        {
            unordered_map<int,list<int>> adjList;
            vector<int> indegree(n, 0);
            for(vector<int> edge:edges){
                int u = edge[0]-1;
                int v = edge[1]-1;
                
                adjList[u].push_back(v);
                indegree[v]++;
            }
            queue<pair<int,int>> q;
            
            for(int i=0;i<n;i++){
                if(indegree[i] == 0){
                    q.push({i,1});
                }
            }
            vector<int> res(n,0);
            
            while(!q.empty()){
                pair<int,int> frontPair = q.front();
                int currentNode = frontPair.first;
                int cTime = frontPair.second;
                q.pop();
                res[currentNode] = cTime;
                
                
                for(int k:adjList[currentNode]){
                    indegree[k]--;
                    if(indegree[k] == 0){
                        q.push({k,cTime+1});
                    }
                }
            }
            return res;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int m;
        cin>>m;
        vector<vector<int>> edges(m,vector<int>(2));
        for(int i=0;i<m;i++)
            cin>>edges[i][0]>>edges[i][1];
        Solution s;
        vector<int> ans=s.minimumTime(n,edges,m);
        for(auto j:ans)
            cout<<j<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
