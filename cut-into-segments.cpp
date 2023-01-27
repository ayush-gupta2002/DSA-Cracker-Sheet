#include <bits/stdc++.h>
using namespace std;

int solve(int currentLength,int x,int y,int z,vector<int>& dp){
	if(currentLength == 0){
		return 0;
	}
	
	int opt1=-1e9;
	int opt2=-1e9;
	int opt3=-1e9;
	if(dp[currentLength] != -1){
		return dp[currentLength];
	}

	if(currentLength >= x){
		opt1 = solve(currentLength-x,x,y,z,dp) + 1;
	}
	if(currentLength >= y){
		opt2 = solve(currentLength-y,x,y,z,dp) + 1;
	}
	if(currentLength >= z){
		opt3 = solve(currentLength-z,x,y,z,dp) + 1;
	}
	return dp[currentLength] = max({opt1,opt2,opt3});
}

int cutSegments(int n, int x, int y, int z) {
	vector<int> dp(n+1,-1);
	int ans_x=0;
	int ans_y=0;
	int ans_z=0;
	if(n%x == 0){
		ans_x = n/x;
	}
	if(n%y == 0){
		ans_y = n/y;
	}
	if(n%z == 0){
		ans_z = n/z;
	}
	return max({ans_x,ans_y,ans_z,solve(n,x,y,z,dp)});
}
