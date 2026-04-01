// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int breakIndex = -1;

        for(int i=n-2 ; i>=0 ; i--) {
            if(nums[i] < nums[i+1] ) {
                breakIndex = i;
                break;
            }
        }

        if(breakIndex == -1) {
            sort(nums.begin() , nums.end() );
        }

        else{

        // now we have the breaking point of the array
        for(int i=n-1 ; i>breakIndex ; i--) {
            if(nums[i] > nums[breakIndex]) {
                swap(nums[i] , nums[breakIndex]);
                break;
            }
        }

        // remaining in sorted order
        sort(nums.begin() + breakIndex+1 , nums.end());

        }
        
        return ;
    }
};
