class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int votes_1 = 0;
        int votes_2 = 0;
        int candidate_1 = -1;
        int candidate_2 = -1;
        vector<int> res;
        int n = nums.size();
        
        for(auto i:nums){
            if(i == candidate_1){
                votes_1 ++;
            }
            else if(i == candidate_2){
                votes_2 ++;
            }
            else if(votes_1 == 0){
                candidate_1 = i;
                votes_1 =1;
            }
            else if(votes_2 ==0){
                candidate_2 = i;
                votes_2 = 1;
            }
            else{
                votes_1 --;
                votes_2 --;
            }
        }
        int count_1 = 0;
        int count_2 = 0;
        
        for(auto i:nums){
            if(i==candidate_1){
                count_1++;
            }
            else if(i == candidate_2){
                count_2++;
            }
        }
        if(count_1>floor(n/3)){
            res.push_back(candidate_1);
        }
        if(count_2>floor(n/3)){
            res.push_back(candidate_2);
        }
        return res;
        
    }
};
