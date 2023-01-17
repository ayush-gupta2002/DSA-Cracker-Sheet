//MEMOIZATION SOLUTION

#include <bits/stdc++.h> 

int frogJumpUtil(int n,vector<int>& heights,int current,vector<int>& effort){
    if(current == 0){
        effort[0] = 0;
    }
    if(effort[current] == -1){
        int left = frogJumpUtil(n,heights,current-1,effort) + abs(heights[current]-heights[current-1]);
        if(current > 1){
        int right = frogJumpUtil(n,heights,current-2,effort) + abs(heights[current] - heights[current-2]);
        effort[current] = min(left,right);
    }
        else{
                    effort[current] = left;
        }
    }
    return effort[current];
}

int frogJump(int n, vector<int> &heights)
{
    vector<int> effort(n);
    for(int i=0;i<n;i++){
        effort[i] = -1;
    }
    return frogJumpUtil(n,heights,n-1,effort);
}

//TABULATION APPROACH

#include <bits/stdc++.h> 

int frogJumpUtil(int n,vector<int>& heights,int current,vector<int>& effort){
    if(current == 0){
        effort[0] = 0;
    }
    if(effort[current] == -1){
        int left = frogJumpUtil(n,heights,current-1,effort) + abs(heights[current]-heights[current-1]);
        if(current > 1){
        int right = frogJumpUtil(n,heights,current-2,effort) + abs(heights[current] - heights[current-2]);
        effort[current] = min(left,right);
    }
        else{
                    effort[current] = left;
        }
    }
    return effort[current];
}

int frogJump(int n, vector<int> &heights)
{
    vector<int> effort(n);
    effort[0] = 0;
    effort[1] = abs(heights[1]-heights[0]);
    for(int i=2;i<n;i++){
        int left = effort[i-1] + abs(heights[i] - heights[i-1]);
        int right = effort[i-2] + abs(heights[i] - heights[i-2]);
        effort[i] = min(left,right);
    }
    
    return effort[n-1];
}

//TABULATION WITH SPACE OPTIMISATION

#include <bits/stdc++.h> 

int frogJumpUtil(int n,vector<int>& heights,int current,vector<int>& effort){
    if(current == 0){
        effort[0] = 0;
    }
    if(effort[current] == -1){
        int left = frogJumpUtil(n,heights,current-1,effort) + abs(heights[current]-heights[current-1]);
        if(current > 1){
        int right = frogJumpUtil(n,heights,current-2,effort) + abs(heights[current] - heights[current-2]);
        effort[current] = min(left,right);
    }
        else{
                    effort[current] = left;
        }
    }
    return effort[current];
}

int frogJump(int n, vector<int> &heights)
{
    int prev = abs(heights[1] - heights[0]);
    int prevToPrev = 0;
    int current = 0;
    if(n==1){
        return prev;
    }
    for(int i=2;i<n;i++){
        int left = prev + abs(heights[i] - heights[i-1]);
        int right = prevToPrev + abs(heights[i] - heights[i-2]);
        current = min(left,right);
        prevToPrev = prev;
        prev = current;
    }
    
    return prev;
}

