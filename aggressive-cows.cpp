bool isPossible(vector<int> &stalls,int mid,int k){
    int cowCount = 1;
    int lastPosition = stalls[0];
    
    for(int i=1;i<stalls.size();i++){
        if((stalls[i]-lastPosition)>=mid){
            cowCount++;
            if(cowCount==k){
                return true;
            }
            lastPosition = stalls[i];
        }
    }
    return false;
}


int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(),stalls.end());
    int maxi = stalls[stalls.size()-1];
    int lo = 0;
    int hi = maxi;
    int mid = lo + (hi-lo)/2;
    int ans = -1;
    
    while(lo<=hi){
        if(isPossible(stalls,mid,k)){
            lo = mid+1;
            ans = mid;
        }
        else{
            hi = mid-1;
        }
        mid = lo + (hi-lo)/2;
    }
    return ans;
}
