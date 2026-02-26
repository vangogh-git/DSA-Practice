// Using KADANE'S ALGORITHM
// Time Complexity: O(n)
// Space Complexity: O(1)


class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        // Code here
        int n = arr.size();
        int sum = 0;
        int maxi = arr[0];
        
        for(int i=0 ; i<n ; i++) {
            sum += arr[i];
            maxi = max(maxi , sum);
            if(sum < 0) {
                sum = 0;
            }
        }
        
        return maxi;
    }
};
