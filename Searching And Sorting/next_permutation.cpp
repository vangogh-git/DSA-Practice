// time complexity : O(n)
// space complexity : O(1)
// very very Important question

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // find the down valley point
        int pointIndex = -1;
        for(int i = nums.size()-2; i>= 0 ; i--) {
            if(nums[i] < nums[i+1] ) {
                pointIndex = i;
                break;
            }
        }

        if(pointIndex == -1) {
            reverse(nums.begin() , nums.end());
            return ;
        }
 
        // find the next greater element
        for(int i=nums.size()-1 ; i>=0 ; i--) {
            if(nums[i] > nums[pointIndex]) {
                swap(nums[i] , nums[pointIndex]);
                break;
            }
        }
        // reverse the remaining element
        reverse(nums.begin()+pointIndex+1 , nums.end());
        return ;
    }
};
