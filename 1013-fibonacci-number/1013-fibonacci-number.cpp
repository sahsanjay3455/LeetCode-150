class Solution {
public:
    int fib(int n) {
        //int a=0,b=1;
        if(n<=1)
        {
            return n;
        }
        int first=fib(n-1);
        int second=fib(n-2);

        return (first+second);
        
    }
};