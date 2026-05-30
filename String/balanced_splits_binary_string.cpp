// Optimized Solution
// Time Complexity : O(n)
// Space Complexity: O(1)

class Solution {
  public:
    int maxSubStr(string &s) {
        
        int ans = 0;
        int cnt_zero = 0;
        int cnt_one = 0;
        
        for(int i=0 ; i<s.size() ; i++) {
            if(s[i] == '0') cnt_zero++;
            if(s[i] == '1') cnt_one++;
            
            if(cnt_zero == cnt_one) {
                ans++;
                cnt_zero = 0;
                cnt_one = 0;
            }
        }
        
        if(cnt_zero != cnt_one) return -1;
        if (ans == 0) return -1;
        return ans;
        
    }
};
