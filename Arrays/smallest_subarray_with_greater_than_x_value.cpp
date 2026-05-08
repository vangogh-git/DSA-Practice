// Time Complexity : O(n)
// Space Complexity: O(1)


class Solution {
  public:
    int smallestSubWithSum(int x, vector<int>& arr) {
        // Your code goes here
        
        // we use the sliding window approach here
        // of variable size
        // if sum goes greater than x we shrink
        // otherwise keep expanding
        
        
        int n = arr.size();
        int i=0 ;
        int sum = 0;
        int ans = INT_MAX;
        
        for(int j=0 ; j<n ; j++) {
            sum += arr[j];
            
            while(sum > x) {
                ans = min(ans , j-i+1);
                sum -= arr[i];
                i++;
            }
        }
        
        if(ans > n) return 0;
        else 
        return ans;
    }
};
