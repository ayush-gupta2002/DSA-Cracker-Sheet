//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	
	int solve(int N,int X,int Y,vector<int>& dp){
	    if(N==0){
	        return 0;
	    }
	    else if(N<0){
	        return 1e9;
	    }
	    
	    int opt1 = 1e9;
	    int opt2 = 1e9;
	    int opt3 = 1e9;
	    
	    if(dp[N] != -1){
	        return dp[N];
	    }
	    
	    if(N >= X){
	        opt1 = 1 + solve(N-X,X,Y,dp);
	    }
	    if(N >= Y){
	        opt2 = 1 + solve(N-Y,X,Y,dp);
	    }
	    if(N >= 1){
	        opt3 = 1 + solve(N-1,X,Y,dp);
	    }
	    
	    if(opt1%2 != 0 && opt1<1e9){
	        return dp[N] = opt1;
	    }
	    else if(opt2%2 != 0 && opt2<1e9){
	        return dp[N] = opt2;
	    }
	    else{
	        return dp[N] = opt3;
	    }
	}
	
	int findWinner(int N, int X, int Y)
	{
	    vector<int> dp(N+1,-1);
		int res = solve(N,X,Y,dp);
		if(res % 2 != 0){
		    return 1;
		}
		return 0;
	}

};
	

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
       	int n, x, y;
       	cin >> n >> x >> y;

       

        Solution ob;
        cout << ob.findWinner(n, x, y);
	    cout << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends
