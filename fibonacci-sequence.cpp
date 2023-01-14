class Solution {
public:
    int fib(int n) {
        int prev = 1;
        int prevToPrev = 0;
        if(n == 1){
            return 1;
        }
        int current = 0;

        for(int i=2;i<=n;++i){
            current = prev + prevToPrev;
            prevToPrev = prev;
            prev = current;
        }
        return current;
    }
};
