// Time Complexity : O(n+m)
// Space Complexity: O(1)

// User function template for C++
class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        int i = 0;
        
        int n = arr.size();
        int m = arr[i].size();
        

        int j = m-1;
        
        int ans = -1;
        
        while(i < n && j >= 0) {
            if(arr[i][j] == 1) {
                ans = i;
                j--;
            }
            
            else {
                i++;
            }
        }
        return ans;
    }
};
