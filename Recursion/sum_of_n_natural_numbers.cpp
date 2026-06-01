class Solution {
    private:
    int findSum(int n , int sum) {
        //base case
        if(n == 0) {
            return 0;
        }
        
        return n + findSum(n-1 , sum);
    }
  public:
    int sumOfNaturals(int n) {
        
        int sum = 0;
        return findSum(n , sum);
    }
};
