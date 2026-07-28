// time complexity : O(nlogn)
// space complexity : O(1)

class Solution {
    private:
    bool canWeAllocate(vector<int> &arr , long long mid , int k) {
        long long int sum = 0;
        int student_alloc = 1;
        for(int i=0 ; i<arr.size() ; i++) {
            if(arr[i] > mid) return false;
            if(sum + arr[i] <= mid) {
                sum += arr[i];
            }
            else {
                student_alloc++;
                sum = arr[i];
            }
        }
        return student_alloc <= k;
    }
  public:
    int findPages(vector<int> &arr, int k) {
        int n = arr.size();
        if(k > n) return -1;
        long long int low = *max_element(arr.begin(),arr.end());
        long long high = accumulate(arr.begin(), arr.end(), 0LL);
        
        //b.s
        while(low <= high) {
            long long int mid = low + (high - low)/2;
            if(canWeAllocate(arr,mid,k)) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return (int)low; // because we need minimum of maximum.
    }
};
