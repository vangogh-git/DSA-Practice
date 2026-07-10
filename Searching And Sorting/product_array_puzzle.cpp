// time complexity : O(n^2)
// space complexity : O(1)
// brute force approach

class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& arr) {
        
        vector<int> ans;
        for(int i=0 ; i<arr.size() ; i++) {
            int product = 1;
            for(int j=0 ; j<arr.size() ; j++) {
                if(j == i) {
                    continue;
                }
                else {
                    product *= arr[j];
                }
            }
            ans.push_back(product);
        }
        return ans;
    }
};
