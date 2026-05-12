// Brute Force Approach
// Time Complexity: O(3n)
// Space Complexity: O(2n)

class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        // using prefixMax and suffixMax
        int n = arr.size();
        vector<int> prefix(n);
        vector<int> suffix(n);
        
        prefix[0] = arr[0];
        for(int i=1 ; i<n ; i++) {
            prefix[i] = max(prefix[i-1] , arr[i]);
        }
        
        suffix[n-1] = arr[n-1];
        for(int i=n-2 ; i>=0  ; i--) {
            suffix[i] = max(suffix[i+1] , arr[i]);
        }
        
        int total = 0;
        int leftMax , rightMax;
        
        for(int i=0 ; i<n ; i++) {
            leftMax = prefix[i];
            rightMax = suffix[i];
            if(arr[i] < leftMax && arr[i] < rightMax) {
                total += min(leftMax , rightMax) - arr[i];
            }
        }
        
        return total;
        
    }
};


// Optimized Approach
// Time Complexity: O(n)
// Space Complexity: O(1)

