// time complexity : O(max-min) * O(n)
// space complexity : O(1)
// this approach will go into TLE so not advised to apply

class Solution {
    private: 
    bool canWePlace(vector<int> &arr , int dist , int k) {
        int cntcows = 1;
        int lastcow = arr[0];
        
        for(int i=1 ; i<arr.size() ; i++) {
            if(arr[i] - lastcow >= dist) {
                lastcow = arr[i];
                cntcows++;
            }
        }
        if(cntcows >= k) return true;
        return false;
    }
  public:
    int aggressiveCows(vector<int> &arr, int k) {
        
        int n = arr.size();
        
        sort(arr.begin() , arr.end());
        for(int i=1 ; i<n ; i++) {
            if(canWePlace(arr , i , k)){
                continue;
            }
            else {
                return i-1;
            }
        }
    }
};

// time complexity : O(nlogm)
// space complexity : O(1)
// optimized approach -> pattern : binary search - max/min
class Solution {
    private: 
    bool canWePlace(vector<int> &arr , int mid , int k) {
        int cntcows = 1;
        int lastcow = arr[0];
        
        for(int i=1 ; i<arr.size() ; i++) {
            if(arr[i]-lastcow >= mid) {
                cntcows++;
                lastcow = arr[i];
            }
            if(cntcows >= k) return true;
        }
        return false;
    }
  public:
    int aggressiveCows(vector<int> &arr, int k) {
        
        int n = arr.size();
        
        sort(arr.begin() , arr.end());
        int low = 1;
        int high = arr[n-1] - arr[0];
        while(low <= high) {
            int mid = low + (high - low)/2;
            
            if(canWePlace(arr , mid , k)) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return high;
    }
};
