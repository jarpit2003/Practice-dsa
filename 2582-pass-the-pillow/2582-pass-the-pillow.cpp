class Solution {
public:
    int passThePillow(int n, int time) 
    {
        int fullrounds = time/(n-1);
        int remainder = time %(n-1);
        if(fullrounds%2==0)
        {
           return remainder+1;
        }
        else
        {
            return n-remainder;
        }
    }
};