class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>st;
        int n = nums2.size();
        vector<int>result(n,-1);
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty()&&nums2[st.top()]<nums2[i])
            {
                st.pop();
            }
            if(st.empty()) result[i] = -1;
            else result[i]=st.top();
            st.push(i);
        }
int m =nums1.size();
    vector<int>arr;
    for(int x:nums1)
    {
        auto it = find(nums2.begin(),nums2.end(),x);
        int index = 0;
        if(it!=nums2.end()) 
        {  index = it-nums2.begin();
        if(result[index]==-1) arr.push_back(-1);
        else arr.push_back(nums2[result[index]]);
        } 
        else
        {
            arr.push_back(-1);
        }      
    }
    return arr;
    }
    
};