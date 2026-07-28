// time complexity : O(n logn)
// space complexity : O(1)
// pattern : binary search + min/max concept

class Solution {
    private:
    bool canWeCut(vector<int> &arr , int height , int m) {
        long long int sum = 0;
        
        for(int i=0 ; i<arr.size() ; i++) {
            if(arr[i] > height) {
                sum += arr[i] - height;
            }
        }
        if(sum >= m) return true;
        else return false;
    }
  public:
    int maxHeight(vector<int> &arr, int m) {
        
        int n = arr.size();
        int low = 0;
        int high = *max_element(arr.begin(),arr.end());
        
        while(low <= high) {
            int mid = low + (high-low)/2;
            
            if(canWeCut(arr , mid , m)) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return high;
    }
};
