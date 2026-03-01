// Time Complexity: O(log n)
// Space Complexity: O(1)


class Solution {
  public:
    int binarysearch(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        
        int s = 0;
        int e = n-1;
        int ans = -1;
        
        while(s <= e ) {
            int mid = s + (e-s) /2;
            
            if(arr[mid] == k) {
                ans = mid;
                e = mid - 1;
            }
            
            else if(arr[mid] < k) {
                s = mid + 1;
            }
            
            else {
                e = mid - 1;
            }
        }
        
        return ans;
    }
};
