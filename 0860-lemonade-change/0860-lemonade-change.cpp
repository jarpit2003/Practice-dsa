class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fived = 0;
        int tend = 0;
        int twentyd = 0;
        bool flag = true;
        for(int i = 0;i<bills.size();++i)
        {
            if(bills[i]==5)
            {
                fived++;
            }
            else if(bills[i]==10)
            {
                tend++;
                if(fived>0)
                {
                    fived--;
                }
                else
                {
                    flag = false;
                   break; 
                }
            }
            else if(bills[i]==20)
            {
                twentyd++;
                if(tend>0&&fived>0)
                {
                    tend--;
                    fived--;
                }
                else if(tend==0&&fived>=3)
                {
                    fived-=3;
                }
                else
                {
                    flag = false;
                    break;
                }
            }
        }
        return flag;
    }
};