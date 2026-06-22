// time complexity : O(n)
// space complexoty : O(1)

class Solution {
public:
    int smallestEqual(vector<int>& nums) {
        int mini = INT_MAX;
        for(int i=0 ; i<nums.size() ; i++) {
            if(i%10 == nums[i] && i < mini) {
                mini = i;
            }

        }
        if(mini == INT_MAX) return -1;
        return mini;
    }
};
