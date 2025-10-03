class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        int lflen = a.length()-1;
        int rglen = b.length()-1;
        string ans;
        while(lflen>=0 ||rglen>=0||carry)
        {
            if(lflen>=0)
            {
                carry += a[lflen]-'0';
                lflen--;
            }
            
            if(rglen>=0)
            {
                carry += b[rglen]-'0';
                rglen--;
            }
            ans += (carry%2 +'0');
            carry = carry/2;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};