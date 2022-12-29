//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    
    void dfs(int i,vector<vector<int>>& adjList,stack<int>& res,vector<int>& visited){
        visited[i] = 1;
        
        for(int k:adjList[i]){
            if(!visited[k]){
                dfs(k,adjList,res,visited);
            }
        }
        res.push(i);
        
        
    }
    
    vector<int> topologicalSort(vector<vector<int>>& adjList){
        int n = adjList.size();
        vector<int> visited(n,0);
        stack<int> res;
        
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,adjList,res,visited);
            }
        }
        vector<int> ans;
        while(!res.empty()){
            int topNode = res.top();
            ans.push_back(topNode);
            res.pop();
        }
        return ans;
    }
    
    string findOrder(string dict[], int N, int K) {
        vector<vector<int>> adjList(K);
        
        for(int i=1;i<N;i++){
            string earlierWord = dict[i-1];
            string laterWord = dict[i];
            int k=0;
            int l=0;
            while(k<earlierWord.size() && l<laterWord.size()){
                if(earlierWord[k] != laterWord[l]){
                    adjList[earlierWord[k]-'a'].push_back(laterWord[l]-'a');
                    break;
                }
                else{
                    k++;
                    l++;
                }
            }
        }
        // for(int i=0;i<N;i++){
        //     cout<<i+'a'<<" ";
        //     for(int k:adjList[i]){
        //         cout<<k+'a'<<" ";
        //     }cout<<endl;
        // }
        vector<int> res = topologicalSort(adjList);
        // for(int i:res){
        //     cout<<i<<" ";
        // }cout<<endl;
        string ans = "";
        for(int i=0;i<res.size();i++){
            char curr = res[i] + 'a';
            ans.push_back(curr);
        }
        return ans;
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends
