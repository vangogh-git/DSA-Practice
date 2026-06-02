// time complexity : O(n)
// space complexity : O(n)


class Solution {
    private:
    void solve(string& s , int i , int j) {
        // base case
        if(i > j) {
            return ;
        }
        else{
            swap(s[i] , s[j]);
            return solve(s, i+1 , j-1);
        }
    }
    
  public:
    bool isPalindrome(string& s) {
        
        int i = 0;
        int j = s.size()-1;
        string org = s;
        solve(s , i , j);
        if(s == org) {
           return true; 
        }
        else {
           return false; 
        }
        
    }
};
