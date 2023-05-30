class Solution {
public:

    bool isVowel(char ch){
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
            return true;
        }
        return false;
    }

    int maxVowels(string s, int k) {
        int n = s.size();
        int i = 0;
        int j = 0;
        int cnt = 0;
        int maxCnt = 0;


        while(j<k){
            if(isVowel(s[j])){
                cnt++;
            }
            j++;
        }
        j--;

        while(j<n){
            // cout<<i<<" "<<j<<" "<<cnt<<endl;

            j++;
            maxCnt = max(maxCnt,cnt);

            if(isVowel(s[j])){
                cnt++;
            }
            if(isVowel(s[i])){
                cnt--;
                i++;
            }
            else if(!isVowel(s[i])){
                i++;
            }

        }
        return maxCnt;
    }
};
