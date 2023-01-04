//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
    
    bool isValid(int row,int col,int N){
        if(row >=0 && col>=0 && row<N && col<N){
            return true;
        }
        return false;
    }
    
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    int sRow = KnightPos[0] - 1;
	    int sCol = KnightPos[1] - 1;
	    int tRow = TargetPos[0] - 1;
	    int tCol = TargetPos[1] - 1;
	    
	    
	    vector<vector<int>> distance(N ,vector<int>(N, INT_MAX));
	    distance[sRow][sCol] = 0;
	    set<pair<int,pair<int,int>>> s;
	    s.insert({0, {sRow,sCol}});
	    
	    while(!s.empty()){
	        auto p = *(s.begin());
	        s.erase(s.begin());
	        int oldDistance = p.first;
	        int row = p.second.first;
	        int col = p.second.second;
	        
	        int delRow[] = {2,2,-2,-2,1,1,-1,-1};
	        int delCol[] = {-1,1,-1,1,2,-2,2,-2};
	        
	        for(int i=0;i<8;i++){
	            int nRow = row + delRow[i];
	            int nCol = col + delCol[i];
	            
	            if(isValid(nRow,nCol,N)){
	                int currentDistance = oldDistance + 1;
	                if(distance[nRow][nCol] > currentDistance){
	                    distance[nRow][nCol] = currentDistance;
	                    s.insert({currentDistance, {nRow,nCol}});
	                }
	            }
	        }
	    }
	    if(distance[tRow][tCol] == INT_MAX){
	        return -1;
	    }
	    return distance[tRow][tCol];
	    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
