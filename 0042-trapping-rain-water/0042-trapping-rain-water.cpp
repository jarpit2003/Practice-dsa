class Solution {
public:
    int trap(vector<int>& height) {
        int left  = 0;
        int right = height.size()-1;
        int leftmax = 0;
        int righhtmax = 0;
        int water = 0;
        while(left<right)
        {
            if(height[left]<height[right])
            {
                if(height[left]>leftmax)
                {
                 leftmax = height[left];
                }
                else
                {
                    water += (leftmax-height[left]);
                }
                left++;
            }
            else
            {
                if(height[right]>righhtmax)
                {
                 righhtmax = height[right];
                }
                else
                {
                    water += (righhtmax-height[right]);
                }
                right --;
            }
        }
        return water;
    }
};