// time complexity : O(n^3)
// space complexty : O(1)
// Brute Force Approach


class Solution {
  public:
    string longestPalindrome(string &s) {
        string ans = "";
        int n = s.size();
        int max_length = 0;
        for(int i=0 ; i<n ; i++) {
            char ch = s[i];
            for(int j=n-1 ; j >= i+1 ; j--) {
                if(s[j] == ch) {
                    string temp = s;
                    reverse(temp.begin()+i , temp.begin()+j+1);
                    if(s.substr(i,j-i+1) == temp.substr(i,j-i+1)){
                        string temp2 = temp.substr(i,j-i+1);
                        if(temp2.size() > max_length) {
                            ans = temp2;
                            max_length = temp2.size();
                        }
                        
                    }
                }
            }
        }
        
        if(ans.size() > 1) return ans;
        else return string(1,s[0]);
        
    }
};

// time complexity : O(n^2)
// space complexty : O(1)
// Optimized Approach

class Solution {
  public:
    string longestPalindrome(string &s) {
        
        string res = "";
        int reslen = 0;
        int left = 0;
        int right = 0;
        for(int i=0 ; i<s.size() ; i++) {
            // odd length
            left = i;
            right = i;
            while(left >= 0 && right < s.size() && s[left] == s[right]) {
                if(right - left + 1 > reslen) {
                    res = s.substr(left , right-left+1);
                    reslen = right - left + 1;
                }
                left--;
                right++;
            }
            
            // even length
            left = i;
            right = i+1;
            while(left >=0 && right < s.size() && s[left] == s[right]) {
                if(right - left + 1 > reslen) {
                    res = s.substr(left , right - left + 1);
                    reslen = right - left + 1;
                }
                left--;
                right++;
            }
        } 
        return res;  
    }
};
