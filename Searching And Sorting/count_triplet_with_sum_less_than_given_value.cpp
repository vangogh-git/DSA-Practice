// time complexity: O(n^2)
// space complexity: O(1)
// sorting + 1 loop + two pointer

class Solution {
  public:
    int countTriplets(int sum, vector<int>& arr) {
        
        int n = arr.size();
        int cnt = 0;
        sort(arr.begin(), arr.end());
        for(int i=0 ; i<n ; i++) {
            int left = i+1;
            int right = n-1;
            while(left < right) {
                if(arr[i]+arr[left]+arr[right] < sum ){
                    cnt += (right-left); // this part is interesting look closely!!!!
                    left++;
                }
                else {
                    right--;
                }
            }
        }
        return cnt;
    }
};
