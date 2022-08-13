long long sumOfMaxAndMin(vector<int> &nums, int n, int k) {
	deque<long long> maxValues;
    vector<long long> answerMax;
    deque<long long> minValues;
    vector<long long> answerMin;
    int i=0;
    int j=0;
    while(j<n){
        while(!maxValues.empty() && maxValues.back()<nums[j]){
            maxValues.pop_back();
        }
        maxValues.push_back(nums[j]);
        if((j-i+1)<k){
            
        }
        else if((j-i+1)==k){
            answerMax.push_back(maxValues.front());
            if(maxValues.front() == nums[i]){
                maxValues.pop_front();
            }
            i++;
        }
        j++;
    }
    j=0;
    i=0;
    while(j<n){
//         cout<<"Answer Min"<<endl;
//         for(auto i:answerMin){
//             cout<<i<<" ";
//         }cout<<endl;
        while(!minValues.empty() && minValues.back()>nums[j]){
            minValues.pop_back();
        }
        minValues.push_back(nums[j]);
        if((j-i+1)<k){
            
        }
        else if((j-i+1)==k){
            answerMin.push_back(minValues.front());
            if(minValues.front() == nums[i]){
                minValues.pop_front();
            }
            i++;
        }
        j++;
    }
//     for(auto i:answerMax){
//         cout<<i<<" ";
//     }cout<<endl;
//     for(auto i:answerMin){
//         cout<<i<<" ";
//     }cout<<endl;
//     cout<<"min sum "<<accumulate(answerMin.begin(),answerMin.end(),0)<<endl;
    return (accumulate(answerMin.begin(),answerMin.end(),0) + accumulate(answerMax.begin(),answerMax.end(),0));
}

