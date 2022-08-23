class Solution {
public:
    
    int binarySearch(vector<int>& nums,int key,int lo,int hi){
        int mid = lo + (hi-lo)/2;
        
        while(lo<=hi){
            if(nums[mid]<key){
                lo = mid+1;
            }
            else if(nums[mid]>key){
                hi = mid-1;
            }
            else{
                return mid;
            }
            mid = lo + (hi-lo)/2;
        }
        return -1;
    }
    
    int pivot(vector<int>& nums){
        int lo = 0;
        int hi = nums.size()-1;
        int mid = lo + (hi-lo)/2;
        
        while(lo<hi){
            if(nums[mid]>=nums[0]){
                lo = mid+1;
            }
            else{
                hi = mid;
            }
            mid = lo + (hi-lo)/2;
        }
        return lo;
    }
    
    int search(vector<int>& nums, int target) {
        int p = pivot(nums);
        int res = -1;
        if(target>= nums[p] && target<=nums[nums.size()-1]){
            res = binarySearch(nums,target,p,nums.size()-1);
        }
        else{
            res = binarySearch(nums,target,0,p-1);
        }
        return res;
        
    }
};
