// this code is only provided to understand how recursion works
// T.C : O(N)
// S.C : O(N)

class Solution {
  public:
    void printTillN(int n) {
        // print after returning 
        // base case
        if(n == 0) {
            return ;
        }
        printTillN(n-1);
        cout << n << " ";
    }
};
