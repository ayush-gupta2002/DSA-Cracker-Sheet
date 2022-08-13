vector<int> Solution::lszero(vector<int> &A) {
    int n = A.size();
    int total = 0;
    vector<int> max_subarray;
    int max_length = 0;
    int start,end;
    unordered_map<int,int> hash_map;
    for(int i=0;i<n;i++){
        total += A[i];
        
        if(total == 0){
            max_length = i+1;
            start = 0;
            end = i;
        }
        else{
            if(hash_map.find(total) != hash_map.end()){
                int new_length = i-(hash_map[total]);
                if(new_length > max_length){
                    max_length = new_length;
                    start = hash_map[total]+1;
                    end = i;
                }
            }
            else{
                hash_map[total] = i;
            }
        }
    }
    for(int i=(start);i<(end+1);i++){
        max_subarray.push_back(A[i]);
    }
    return max_subarray;
}
