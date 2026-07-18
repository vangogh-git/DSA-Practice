// very basic aaproach
// time complexity : O(n)
// space complexity : O(1)

class Solution {
  public:
    int findStepKeyIndex(vector<int>& arr, int k, int x) {
        
        int n = arr.size();
        for(int i=0 ; i<n ; i++) {
            if(arr[i] == x) {
                return i;
            }
        }
        return -1;
    }
};
