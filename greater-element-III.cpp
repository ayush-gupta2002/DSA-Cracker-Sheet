class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int> digits;
        int og = n;
        while(n > 0){
            int digit = n%10;
            n /= 10;
            digits.push_back(digit);
        }
        reverse(digits.begin(),digits.end());

        int digitSize = digits.size();
        int k = digitSize - 2;
        cout<<k<<endl;

        while(k>=0 && digits[k+1]<=digits[k]){
            k--;
        }
        cout<<k<<endl;
        if(k<0){
            reverse(digits.begin(),digits.end());
        }
        else{
            int j = digitSize - 1;

            while(j>k && digits[j]<=digits[k]){
                j--;
            }
            swap(digits[j],digits[k]);
            reverse(digits.begin()+k+1,digits.end());
        }
        long long int number = 0;
        long long int factor = 1;
        for(int i = digitSize-1;i>=0;i--){
            number += digits[i]*factor;
            factor *= 10;
        }
        if(number <= og || number > INT_MAX){
            return -1;
        }
        return number;
    }
};
