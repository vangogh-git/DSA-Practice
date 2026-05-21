// Time Complexity: O(n)
// Space Complexity: O(1)
// Two Pointer Approach

class Solution {
  public:
    bool isPalindrome(string& s) {
        // code here
        int i=0;
        int j = s.size()-1;
        
        string temp = s;
        
        while(i <= j) {
            swap(s[i++] , s[j--]);
        }
        
        if(temp == s) {
            return true;
        }
        
        else{
            return false;
        }
    }
};
