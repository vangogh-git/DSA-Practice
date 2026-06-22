
// Time complexity : O(n)
// space complexity : O(1)

class Solution {
  public:
    vector<int> find(vector<int>& arr, int x) {
        
        vector<int> ans;
        bool found = false;
        int first = 0 , last = 0;
        int n = arr.size();
        
        // edge case
        if(x < arr[0] || x > arr[n-1]) return {-1,-1};
        
        for(int i=0 ; i<arr.size() ; i++) {
            if(!found && arr[i] == x) {
                found = true;
                ans.push_back(i);
            }
            
            if(found && arr[i] != arr[i+1]) {
                ans.push_back(i);
                break;
            }
        }
        
        if(found == false) return {-1,-1};
        return ans;
        
    }
};

// time complexity : O(log n)
// space complexity : O(1)

class Solution {
    private: 
    int find_first(vector<int>& nums, int target){
        int first_index = INT_MAX;
        int beg = 0;
        int end = nums.size()-1;
        bool found = false;
        
        while(beg <= end) {
            int mid = beg + (end-beg)/2;
            if(nums[mid] == target) {
                    first_index = mid;
                    found = true;
                    end = mid - 1;
            }
            else if(nums[mid] < target) {
                beg = mid + 1;
            }
            else if(nums[mid] > target) {
                end = mid - 1;
            }
        }
        if(!found) return -1;
        return first_index;
    }
    int find_last(vector<int>& nums, int target){
    int last_index = INT_MIN;
        int beg = 0;
        int end = nums.size()-1;
        bool found = false;
    
        while(beg <= end) {
            int mid = beg + (end-beg)/2;
            if(nums[mid] == target) {
                    last_index = mid;
                    found = true;
                    beg = mid + 1;
            }
            else if(nums[mid] < target) {
                beg = mid + 1;
            }
            else if(nums[mid] > target) {
                end = mid - 1;
            }
        }
        if(!found) return -1;
        return last_index;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        if(nums.size() == 0) return {-1,-1};

        ans.push_back(find_first(nums,target));
        ans.push_back(find_last(nums,target));

        return ans;
    }
};
