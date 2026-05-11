//Time Complexity: O(n)
// Space Complexity: O(1)
// Using Sliding Window of fixed size

// Final function implementation
class Solution {
  public:
    int minSwap(vector<int>& arr, int k) {
        // code here
        // this is a sliding window of fixed size problem
        int n = arr.size();
        int count = 0;
        int curr_win = 0;
        
        for(int i=0 ; i<arr.size() ; i++) {
            if(arr[i] <= k) {
                count ++;
            }
        }
        
        for(int i=0 ; i<count ; i++) {
            if(arr[i] <= k) {
                curr_win ++;
            } 
        }
        
        int ans = count - curr_win;
        
        // now traverse again with window size of count
        for(int i=count ; i<n ; i++) {
            if(arr[i] <= k) {
                curr_win ++;
            }
            if(arr[i-count] <= k) {
                curr_win --;
            }
            
            ans = min(ans , count - curr_win);
        }
        
        return ans;
        
    }
};
