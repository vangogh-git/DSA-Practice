// time complexity: O((log n)^2)
// space complexity : O(1)
// pattern : binary search + min concept

class Solution {
    private : 
    int countZero(long long x , int n) {
        int cnt = 0;
        while(x > 0) {
            x /= 5;
            cnt += x;
        }
        return cnt;
    }
  public:
    int findNum(int n) {
        
        long long low = 0;
        long long high = 5LL*n;
        
        while(low <= high) {
            long long mid = low + (high-low)/2;
            
            if(countZero(mid,n) >= n) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return low;
    }
};
