// Time Complexity : O(n)
// Space Comeplexity : O(n)
// NON-RECURSIVE SOLUTION


class Solution {
  public:
    string removeDuplicates(string& s) {
        string ans = "";
        char prev = '#';
        for(int i=0 ; i<s.size() ; i++) {
            if(s[i] != prev) {
                ans += s[i];
                prev = s[i];
            }
        }
        
        return ans;
    }
};
