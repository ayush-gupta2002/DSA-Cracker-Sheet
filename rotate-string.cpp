class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.length();
        s.append(s);
        int window_size = goal.length();
        int j= 0;
        int i=0;
        if(n!=window_size){
            return false;
        }
        string current_string = "";
        while(j<(s.length()-1)){
            current_string.push_back(s[j]);
            cout<<"current string "<<current_string<<endl;
            
            if(((j-i+1)==window_size) && current_string == goal){
                return true;
            }
            else if((j-i+1)<window_size){
                j++;
            }
            else if((j-i+1)==window_size && current_string != goal){
                current_string.erase(0,1);
                i++;
                j++;
            }
        }
        return false;
    }
    
};
