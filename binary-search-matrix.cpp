class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int lo = 0;
        int hi = (rows*cols)-1;
        int mid = lo + (hi-lo)/2;
        
        while(lo<=hi){
            int element = matrix[mid/cols][mid%cols];
            if(element == target){
                return true;
            }
            if(element < target){
                lo = mid+1;
            }
            else{
                hi = mid-1;
            }
            mid = lo + (hi-lo)/2;
        }
        return false;
    }
};
