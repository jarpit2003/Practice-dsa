class Solution {
public:
    int fib(int n) {
      int sum = 0;
       if(n>=2)
       {
        sum = sum+fib(n-1)+fib(n-2);
       }
       if(n==1)
       {
        sum = 1; 
       }
       if(n==0)
       {
        sum= 0;
       }
       return sum;
    }
};