// t.c : O(n)
// s.c : O(1)

class Solution {
    private:
    void reverse(string& s , int start , int end) {
        if(start > end) {
            return ;
        }
        else {
            swap(s[start] , s[end]);
            reverse(s , start+1 , end-1);
        }
    }
  public:
    string reverseString(string& s) {
        // code here
        
        reverse(s , 0 , s.size()-1);
        return s;
    }
};
