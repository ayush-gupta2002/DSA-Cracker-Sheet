class Solution {
public:
    
    int firstOcc(vector<int>& nums,int target){
        int hi = nums.size()-1;
        int lo = 0;
        int mid = lo +(hi-lo)/2;
        int answer = -1;
        
        while(lo<=hi){
            if(nums[mid]==target){
                hi = mid-1;
                answer = mid;
            }
            else if(nums[mid]>target){
                hi = mid-1;
            }
            else{
                lo = mid+1;
            }
            mid = lo +(hi-lo)/2;
        }
        return answer;
    }
    int lastOcc(vector<int>& nums,int target){
        int hi = nums.size()-1;
        int lo = 0;
        int mid = lo +(hi-lo)/2;
        int answer = -1;
        
        while(lo<=hi){
            if(nums[mid]==target){
                answer = mid;
                lo = mid+1;
            }
            else if(target<nums[mid]){
                hi = mid-1;
            }
            else{
                lo = mid+1;
            }
            mid = lo +(hi-lo)/2;
        }
        return answer;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res{-1,-1};
        if(nums.size()==0){
            return res;
        }
        res[0]=(firstOcc(nums,target));
        res[1]=(lastOcc(nums,target));
        return res;
    }
};
