// time complexity : O(max-min) * O(n)
// space complexity : O(1)

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
