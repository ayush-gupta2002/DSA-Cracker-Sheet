class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int m = cardPoints.size();
        cardPoints.insert(cardPoints.end(),cardPoints.begin(),cardPoints.end());
        int n = cardPoints.size();


        int i=0;
        int j=0;

        int currentSum = 0;
        int maxSum = 0;

        while(j<k){
            currentSum += cardPoints[j];
            j++;
        }
        maxSum = max(maxSum,currentSum);

        while(j<n){
            currentSum += cardPoints[j];
            currentSum -= cardPoints[i];
            i++;
            j++;
            // cout<<currentSum<<" "<<i<<" "<<j<<endl;
            if(m >= i && m <= j){
                maxSum = max(maxSum,currentSum);
            }
        }

        return maxSum;
    }
};
