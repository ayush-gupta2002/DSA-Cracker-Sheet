class Solution {
public:
    int maximumSwap(int num) {
        priority_queue<pair<int,int>> pq;

        vector<int> digits;
        int curri = 0;

        while(num != 0){
            int digit = num%10;
            digits.push_back(digit);
            pq.push({digit,curri});
            curri++;
            num/=10;
        }

        curri = digits.size()-1;
        while(curri >= 0){
            pair<int,int> frontPair = pq.top();
            pq.pop();
            if(frontPair.first != digits[curri]){
                int mini = frontPair.second;
                pair<int,int> fp = pq.top();
                pq.pop();
                
                while(fp.first == frontPair.first){
                    mini = min(mini,fp.second);
                    fp = pq.top();
                    pq.pop();
                }
                swap(digits[curri],digits[mini]);
                break;
            }
            curri--;
        }
        int res = 0;
        int factor = 1;

        curri = 0;
        while(curri < digits.size()){
            res += digits[curri]*factor;
            factor *= 10;
            curri++;
        }
        return res;
    }
};
