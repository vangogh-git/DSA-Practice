// Time Complexity: O(n)
// Space Complexity: O(n)


class Solution {
  public:

    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& arr) {
        // Your code here
        int n = arr.size();
        if(n == 0) return 0;
        
        int mini = INT_MAX;
        int maxi = INT_MIN;
        
        for(int i=0 ; i<n ; i++) {
            mini = min(mini , arr[i]);
            maxi = max(maxi , arr[i]);
        }
        
        
        vector<int> temp(maxi - mini + 1 , 0);
        
        for(int i=0 ; i<n ; i++) {
            int index = arr[i] - mini;
            temp[index] = -1;
        }
        
    
        int cnt = 0;
        int ans = 0;
        
        for(int i=0 ; i<temp.size() ; i++) {
            if(temp[i] == -1) {
                cnt ++;
                ans = max(ans , cnt);
            }
            else{
                cnt = 0;
            }
        }
        
        return ans;
    }
};
