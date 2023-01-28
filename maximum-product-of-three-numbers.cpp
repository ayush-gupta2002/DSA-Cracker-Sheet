class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();

        vector<int> largest(3,INT_MIN);
        vector<int> smallest(2,0);

        for(int i=0;i<n;i++){
            if(nums[i] > largest[0]){
                largest[2] = largest[1];
                largest[1] = largest[0];
                largest[0] = nums[i];
            }
            else if(nums[i] > largest[1]){
                largest[2] = largest[1];
                largest[1] = nums[i];
            }
            else if(nums[i] > largest[2]){
                largest[2] = nums[i];
            }
            if(nums[i] < smallest[0]){
                smallest[1] = smallest[0];
                smallest[0] = nums[i];
            }
            else if(nums[i] < smallest[1]){
                smallest[1] = nums[i];
            }
        }
        for(int it:smallest){
            cout<<it<<" ";
        }cout<<endl;
        for(int it:largest){
            cout<<it<<" ";
        }cout<<endl;
        int product = max(largest[0]*largest[1]*largest[2], smallest[0]*smallest[1]*largest[0]);

        return product;

    }
};
