class Solution {
    private:
     bool checkodd(int num)
     {
         if(num%2==0)
         {
             return false;
         }
         else
         {
             return true;
         }
     }
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n = arr.size();
        bool flag = false;
        for(int i =0;i<=n-1;i++)
        {
            if(checkodd(arr[i])==true&&i+2<=n-1)
            {
                if(checkodd(arr[i+1])==true&&checkodd(arr[i+2])==true)
                {
                    flag = true;
                }
            }
        }
        return flag;
        
    }
};