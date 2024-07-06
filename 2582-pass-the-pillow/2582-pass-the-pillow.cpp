class Solution {
public:
    int passThePillow(int n, int time) 
    {
        int direction = 1;
        int position = 1;
        for(int i =0;i<time;i++)
        {
            if(position==1)
            {
                direction = 1;
            }
            else if(position == n)
            {
                direction = -1;
            }
            position+=direction;
        }
        return position;
    }
};