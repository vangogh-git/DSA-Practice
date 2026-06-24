// t.c : O(1)
// s.c : O(1)

class Solution {
  public:
    int middle(int a, int b, int c) {
        
        if((a < b && a > c) || (a < c && a > b) ) {
            return a;
        }
        
        else if((b < a && b > c) || (b < c && b > a)) {
            return b;
        }
        
        else  {
            return c;
        }
        
    }
};
