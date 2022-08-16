// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
#include <vector>
#include <bits/stdc++.h>

int minOps(vector<int> nums){
    int i=0;
    int n = nums.size();
    int j = n-1;
    int ops = 0;
    
    while(i<j){
        if(nums[i]==nums[j]){
            i++;
            j--;
        }
        else if(nums[i]>nums[j]){
            nums[j-1] = nums[j-1]+nums[j];
            ops++;
            j--;
        }
        else{
            nums[i+1] = nums[i+1]+nums[i];
            ops++;
            i++;
        }
    }
    return ops;
}

int main() {
    // Write C++ code here
    vector<int> nums{11,14,15,99};
    int min_ops = minOps(nums);
    cout<<min_ops;

    return 0;
}
