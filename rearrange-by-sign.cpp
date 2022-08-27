class Solution {
public:
    
    void rightRotate(vector<int>& nums,int start,int end){
        int temp = nums[end];
        for(int i=end;i>start;i--){
            nums[i]=nums[i-1];
        }
        nums[start] = temp;
    }
    
    vector<int> rearrangeArray(vector<int>& nums) {
        //even -> negative
        //odd -> positive
        int wrong = -1;
        for(int i=0;i<nums.size();i++){
            if(wrong != -1){
                if((nums[wrong]>0 && nums[i]<0) ||(nums[wrong]<0 && nums[i]>0)){
                    rightRotate(nums,wrong,i);
                    
                    if(i-wrong >=2){
                        wrong += 2;
                    }
                    else{
                        wrong = -1;
                    }
                }
            }
            else{
                if((nums[i]>0 && i%2!=0) || (nums[i]<0 && i%2==0)){
                    wrong = i;
                }
            }
        }
        return nums;
    }
};
