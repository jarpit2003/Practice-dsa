class Solution {
public:
    bool search(vector<int>& piles, int h,int speed)
    {
        long long hours = 0;
        for(auto pile:piles)
        {
             hours += (pile+speed-1)/speed;
        }
        return hours <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(),piles.end());
        int ans = right;
        while(left<=right)
        {
            int mid = left + (right-left)/2;
            if(search(piles,h,mid))
            {
                ans = mid;
                right = mid -1;
            }
            else
            {
              left = mid+1;  
            }
        }
        return ans;
    }
};