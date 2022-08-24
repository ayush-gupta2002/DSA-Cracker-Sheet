class Solution {
public:
    
    bool binarySearch(int lo,int hi,vector<int>& nums,int key){
        int mid = lo + (hi-lo)/2;
        while(lo<=hi){
            if(nums[mid]==key){
                return true;
            }
            else if(nums[mid]>key){
                hi = mid-1;
            }
            else{
                lo = mid+1;
            }
            mid = lo + (hi-lo)/2;
        }
        return false;
    }
    
    int getPivot(vector<int>& nums,int lo,int hi){
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
    
    bool search(vector<int>& nums, int target) {
        //Just adding a condition to reduce time complexity
        if(target == nums[0] || target == nums.back()){
            return true;
        }
        
        //No removing all the redundant element from the beginning of the array
        int lo = 0;
        while((lo+1)<nums.size() && nums[lo]==nums[lo+1]){
            lo++;
        }
        
        //Considering the case where all the elements are equal
        if(lo == nums.size()-1){
            if(nums[lo]==target){
                return true;
            }
            return false;
        }
        
        //Removing all the redundant elements from the back of the array
        int hi = nums.size()-1;
        while(nums[hi]==nums[0] && hi>=0){
            hi--;
        }
        
        //Getting the pivot
        int pivot = getPivot(nums,lo,hi);
        
        //Applying binary search in the second half
        if(target>=nums[pivot] && target<=nums[hi]){
            return binarySearch(pivot,hi,nums,target);
        }
        
        //Applying binary search in the first half
        return binarySearch(lo,pivot-1,nums,target);
    }
};
