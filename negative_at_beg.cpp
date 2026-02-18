// Using Two Pointer Approach
// time complexity: O(n)
// space complexity: O(1)


#include <bits/stdc++.h> 
vector<int> separateNegativeAndPositive(vector<int> &nums){
    
    
   int n = nums.size();
    int i = 0;
    int j = n-1;
    
    while(i < j){
        if(nums[i] > 0 && nums[j] < 0){
            swap(nums[i] , nums[j]);
            i++;
            j--;
        }

        else if(nums[i] < 0 && nums[j] < 0){
            i++;
        }
        else if(nums[i] < 0 && nums[j] > 0){
            i++;
            j--;
        }
        else{
            j--;
        }
    }

    return nums;

}
