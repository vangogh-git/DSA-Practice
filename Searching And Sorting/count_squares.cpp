// time complexity: O( sqrt(n) )
// space complexity : O(n) // due to recursion

class Solution {
    private:
    int solve(int i , int n) {
        //base case
        if(i*i >= n) {
            return 0;
        }
        
       return 1 + solve(i+1,n);
        
    }
  public:
    int countSquares(int n) {
        int i=1;
        return solve(i , n);
    }
};
