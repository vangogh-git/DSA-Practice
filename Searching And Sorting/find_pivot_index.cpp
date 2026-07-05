// time complexity : O(n)
// space complexity : O(1)
// brute force approach : 

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int left_sum = 0;
        int right_sum = 0;
        for(int i=1 ; i<nums.size() ; i++) {
            right_sum += nums[i];
        }
        for(int i=0 ; i<nums.size() ; i++) {
            if(left_sum == right_sum ) {
                return i;
            }
            else {
                left_sum += nums[i];
                if(i < nums.size()-1) {
                    right_sum -= nums[i+1];
                }
            }
        }
        return -1;
    }
};

// time complexity : O(n)
// space complexity : O(1)
// More Cleaner Approach - better for interviews - avoids i+1 edge case

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        for(int num : nums)  total += num;
        int left_sum = 0;
        for(int i=0 ; i<n ; i++) {
            int right_sum = total - left_sum - nums[i];
            if(left_sum == right_sum ) return i;
            left_sum += nums[i];
        }
        return -1;
    }
};
