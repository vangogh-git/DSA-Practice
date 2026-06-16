// time complexity : O(n^3)
// space complexty : O(1)
// Brute Forcce Approach


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
