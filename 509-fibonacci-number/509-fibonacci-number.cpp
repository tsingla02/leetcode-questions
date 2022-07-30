class Solution {
public:
    int fib(int n) {
        int t;
        if(n == 1){
            t = 1;
        }
        else if(n == 0){
            t =  0;
        }
        if(n>=2)
        {
            t = fib(n-1)+fib(n-2);
        }
        return t;
        
    }
};