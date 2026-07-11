class Solution {
public:
    int nextnum(int n)
    {
        int sum = 0;
        while(n)
        {
        int digit = n%10;
        sum += digit*digit;
        n = n/10; 
        }   
        return sum;
         }
    bool isHappy(int n) {
        int slow = nextnum(n);
        int fast = nextnum(nextnum(n));
        while(slow!=fast)
        {
            slow = nextnum(slow);
            fast = nextnum(nextnum(fast));
        }
        return slow ==1;
    }
};