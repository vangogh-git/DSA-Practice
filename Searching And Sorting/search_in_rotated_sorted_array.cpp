// time complexity : O(n)
// space complexity : O(1)


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int mini = 0;
        int maxi = nums.size()-1;
        bool found = false;
        for(int i=1 ; i<nums.size() ; i++) {
            if(nums[i-1] > nums[i]) {
                maxi = i-1;
                mini = i;
                found = true;
                break;
            }
        }

        if(!found) {
            mini = 0;
            maxi = nums.size()-1;
        }

        int s1 = 0 , s2 = mini , e1 = maxi , e2 = nums.size()-1;
        while(s1 <= e1) {
            int mid = s1 + (e1-s1)/2;
            if(nums[mid] == target) {
                return mid;
            }
            else if(nums[mid] < target) {
                s1 = mid+1;
            }
            else {
                e1 = mid-1;
            }
        }
        while(s2 <= e2) {
            int mid = s2 + (e2-s2)/2;
            if(nums[mid] == target) {
                return mid;
            }
            else if(nums[mid] < target) {
                s2 = mid+1;
            }
            else {
                e2 = mid-1;
            }
        }
        return -1;
    }
};

// optimized Solution
// time complexity : O(log n)
// space complexity : O(1)

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int beg = 0;
        int end = nums.size()-1;
        while(beg <= end) {
            int mid = beg + (end-beg)/2;
            if(target == nums[mid]) {
                return mid;
            }
            if(nums[beg] <= nums[mid] ) {
                if(target >= nums[beg] && target <= nums[mid]) {
                    end = mid - 1;
                }
                else {
                    beg = mid + 1;
                }
            }
            else {
                if(target > nums[mid] && target <= nums[end]) {
                    beg = mid + 1;
                }
                else{
                    end = mid - 1;
                }
            }
        }
        return -1;
    }
};
