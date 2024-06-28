class Solution {
public:
    bool isPalindrome(int x) {
        long long int revnum = 0;
        int dup = x;
        if(x<0)
        {
            return false;
        }
        while(x!=0)
        {
            int lr = x%10;
             revnum = revnum*10 + lr;
            x = x/10;
        }
        if(dup==revnum)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};