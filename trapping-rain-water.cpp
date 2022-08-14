class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left_vec[n];
        int right_vec[n];
        int left_maxi = height[0];
        int right_maxi = height[n-1];
        int stored_water = 0;
        
        for(int i=0;i<n;i++){
            left_maxi = max(left_maxi,height[i]);
            left_vec[i]=(left_maxi);
            cout<<left_maxi<<" ";
        }cout<<endl;
        for(int j=(n-1);j>=0;j--){
            right_maxi = max(right_maxi,height[j]);
            right_vec[j]=(right_maxi);
            cout<<right_maxi<<" ";
        }cout<<endl;
        for(int i=0;i<n;i++){
            int height_to_subtract = min(left_vec[i],right_vec[i]);
            cout<<height_to_subtract<<" ";
            int height_difference = height_to_subtract - height[i];
            stored_water += height_difference;
        }
        return stored_water;
    }
    
    //Better approach would 
};
