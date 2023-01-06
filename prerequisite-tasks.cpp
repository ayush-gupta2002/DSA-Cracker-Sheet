//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:

    bool dfs(int i,unordered_map<int,list<int>>& adjList, vector<int>& dfsVisited, vector<int>& visited){
        visited[i] = 1;
        dfsVisited[i] = 1;
        
        for(int k:adjList[i]){
            if(!visited[k]){
                bool res = dfs(k,adjList,dfsVisited,visited);
                if(!res){
                    return false;
                }
            }
            if(dfsVisited[k]){
                return false;
            }
        }
        dfsVisited[i] = 0;
        return true;
    }

	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    unordered_map<int,list<int>> adjList;
	    for(pair<int,int> prereq:prerequisites){
	        int u = prereq.second;
	        int v = prereq.first;
	        
	        adjList[u].push_back(v);
	    }
	    
	    vector<int> visited(N,0);
	    vector<int> dfsVisited(N,0);
	    
	    for(int i=0;i<N;i++){
	        if(!visited[i]){
	            bool res = dfs(i,adjList,dfsVisited,visited);
	            if(!res){
	                return false;
	            }
	        }
	    }
	    return true;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends
