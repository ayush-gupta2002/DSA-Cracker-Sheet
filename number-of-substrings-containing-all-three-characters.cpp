class Solution {
public:
    int numberOfSubstrings(string s) {
        int a = 0;
        int b = 0;
        int c = 0;

        int i = 0;
        int j = 0;
        
        int n = s.size();

        int cnt = 0;

        if(s[0] == 'a'){
            a = 1;
        }else if(s[0] == 'b'){
            b=1;
        }else{
            c=1;
        }


        while(i<n && j<n){
            if(a>0 && b>0 && c>0){
                cnt += (n-j);
                if(s[i] == 'a'){
                    a--;
                }else if(s[i] == 'b'){
                    b--;
                }else{
                    c--;
                }
                i++;
            }
            else{
                j++;
                            if(s[j] == 'a'){
                a++;
            }else if(s[j] == 'b'){
                b++;
            }else{
                c++;
            }
            }
        }
        return cnt;
    }
};
