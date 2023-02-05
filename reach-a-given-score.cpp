//{ Driver Code Starts
// Driver Code
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

// } Driver Code Ends
// Complete this function

long long int solve(vector<int>& deno,vector<vector<int>>& dp,long long int n,int curri){
    if(curri == 0){
        if(n%deno[0] == 0){
            return 1;
        }
        return 0;
    }
    else if(n==0){
        return 1;
    }
    else if(curri < 0){
        return 0;
    }
    else if(n < 0){
        return 0;
    }
    if(dp[curri][n] != -1){
        return dp[curri][n];
    }
    
    int left = 0;
    if(n >= deno[curri]){
        left = solve(deno,dp,n-deno[curri],curri);
    }
    int right = solve(deno,dp,n,curri-1);
    return  dp[curri][n] = left + right;
}

long long int count(long long int n)
{
	
	vector<int> deno{3,5,10};
	vector<vector<int>> dp(3, vector<int>(n+1,-1));
	
	return solve(deno,dp,n,2);
}

//{ Driver Code Starts.



int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		cout<<count(n)<<endl;
	}
	return 0;
}
// } Driver Code Ends
