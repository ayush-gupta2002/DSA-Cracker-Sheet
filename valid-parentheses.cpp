class Solution {
public:
    bool isValid(string s) {
        stack<char> hash;
        for(char i:s){
            if(i==']'){
                if(hash.empty() || hash.top() != '['){
                    return false;
                }
                else{
                    hash.pop();
                }
            }
            else if(i==')'){
                if(hash.empty() || hash.top() != '('){
                    return false;
                }
                else{
                    hash.pop();
                }
            }
            else if(i=='}'){
                if(hash.empty() || hash.top() != '{'){
                    return false;
                }
                else{
                    hash.pop();
                }
            }
            else{
                hash.push(i);
            }
        }
        if(hash.empty()){
            return true;
        }
        return false;
    }
};
