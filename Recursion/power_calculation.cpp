// Time Complexity : O(log e)
// Space Complexity: O(log e)

class Solution {
  public:
    double power(double b, int e) {
        // base case
        if(e == 0) return 1;
        if(e < 0) return 1 / power(b , -e);
        
        double half = power(b , e/2);
        
        if(e % 2 == 0) {
            return half * half;
        }
        else{
            return b * half * half;
        }
    }
};
