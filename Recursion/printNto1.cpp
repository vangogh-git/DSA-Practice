// T.C : O(n)
// S.C : O(n)
 
class Solution {
  public:
    void printNos(int n) {
        //base case
        if(n == 0) {
            return ;
        }
        cout << n << " ";
        printNos(n-1);
    }
};
