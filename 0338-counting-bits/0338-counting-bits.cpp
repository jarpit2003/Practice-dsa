class Solution {
public:
int count1sbin(const int &n)
{
    int ans = 0;
    for(int i =0;i<32;i++)
    {
        if((n>>i)&1) ans++;
    }
    return ans;
}
    vector<int> countBits(int n) {
        vector<int>ans(n + 1);
        for(int i =0;i<n+1;i++)
        {
            ans[i] = count1sbin(i);
        }
        return ans;
    }
};