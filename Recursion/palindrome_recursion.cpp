// t.c : O(n)
// s.c : O(1)

class Solution {
    private: 
    bool Check(string &s , int st , int e){
        if(st > e) {
            return true;
        }
        else{
            if(s[st] != s[e] ) {
                return false;
            }
            Check(s , st+1 , e-1);
        }
    }
  public:
    bool isPalindrome(string& s) {
        
        return Check(s , 0 , s.size()-1);
        
    }
};
