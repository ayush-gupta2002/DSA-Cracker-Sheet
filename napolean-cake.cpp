#include <iostream>
#include <vector>
using namespace std;

void reverse(vector<int>& nums){
    int l = 0;
    int r = nums.size()-1;
    while(l<r){
        int temp = nums[l];
        nums[l] = nums[r];
        nums[r] = temp;
        l++;
        r--;
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> creams(n);
        for(int i=0;i<n;i++){
            cin>>creams[i];
        }
        int temp = 0;
        vector<int> res;
        for(int i=n-1;i>=0;i--){
            temp = max(temp,creams[i]);
            if(temp <= 0){
                res.push_back(0);
            }
            else{
                res.push_back(1);
            }
            temp--;
        }
        reverse(res);
        for(int it:res){
            cout<<it<<" ";
        }
    }
    return 0;
}

//
