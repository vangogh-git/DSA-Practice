// time complexity : O(n * log(sum(arr)))
// space complexity : O(1)
// pattern : binary search -> min/max concept

class Solution {
    private:
    bool canWePaint(vector<int>& arr, int mid , int k) {
        int sum = arr[0];
        int painter_alloc = 1;
        for(int i=1 ; i<arr.size(); i++) {
            if(sum + arr[i] <= mid) {
                sum += arr[i];
            }
            else {
                painter_alloc++;
                sum = arr[i];
            }
        }
        return painter_alloc <= k;
    }
  public:
    int minTime(vector<int>& arr, int k) {
        
        int n = arr.size();
        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin() , arr.end() , 0LL);
        
        while(low <= high) {
            int mid = low + (high - low)/2;
            
            if(canWePaint(arr, mid , k)) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return low;
    }
};
