class Solution {
public:
int check(int n)
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
       int slow = n;
        int fast = n;
        do{
            slow = check(slow);
            fast = check(check(fast));
        }
        while(slow!=fast);
        return slow ==1;
    }
};