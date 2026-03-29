// Time Complexity: O(n)
// Space Complexity: O(1)
// this solution works for the test cases where only one number is repeated

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int ans = 0;

        for(int i=0 ; i<nums.size() ; i++) {
            ans = ans ^ nums[i];
        }

        for(int i=1 ; i<nums.size() ; i++) {
            ans = ans ^ i;
        }

        return ans;
    }
};
