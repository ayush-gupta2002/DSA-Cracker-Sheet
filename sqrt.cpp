class Solution {
public:
    int mySqrt(int x) {
        int hi = x;
        int lo = 0;
        long long int mid = lo+(hi-lo)/2;
        long long int ans = -1;
        
        while(lo<=hi){
            long long int square = mid*mid;
            if(square<x){
                ans = mid;
                lo = mid+1;
            }
            else if(square>x){
                hi = mid-1;
            }
            else{
                return mid;
            }
            mid = lo + (hi-lo)/2;
        }
        return ans;
    }
};
