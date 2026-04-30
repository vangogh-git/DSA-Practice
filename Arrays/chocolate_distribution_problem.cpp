// time complexity: O(nlogn)
// space complexity: O(1)

// pattern of this problem
// this is a sliding window problem

class Solution {
  public:
    int findMinDiff(vector<int>& a, int m) {
        // code here
           // this is a sliding window problem
           
           // first let us sort the array
           sort(a.begin() , a.end());
           int ans = INT_MAX;
           
           int n = a.size();
           
           // now apply sliding window
           for(int i=0 ; i<=n-m ; i++) {
               int diff = a[i+m-1] - a[i];
               ans = min(ans , diff);
           }
           
           return ans;
    }
};
