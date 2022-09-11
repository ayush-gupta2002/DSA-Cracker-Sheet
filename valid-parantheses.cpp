class Solution {
public:
    bool isValid(string s) {
        stack<char> ds;
        int m = 0;
        while(m<s.length()){
            char i = s[m];
            if(i == '(' || i == '{' || i == '['){
                ds.push(i);
            }
            else{
                if(ds.empty()){
                    return false;
                }
                if(i == ')' && ds.top() != '('){
                    return false;
                }
                else if(i == ']' && ds.top() != '['){
                    return false;
                }
                else if(i == '}' && ds.top() != '{'){
                    return false;
                }
                else{
                    ds.pop();
                }
            }
            m++;
        }
        if(ds.empty()){
            return true;
        }
        return false;
    }
};
