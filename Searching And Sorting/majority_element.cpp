// time complexity: O(nlogn)
// space complexity : O(n)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        unordered_map<int,int>freq;
        for(auto it : freq) {
            it.second = 0;
        }
        int parameter = nums.size()/2;
        for(int i=0 ; i<nums.size() ; i++) {
            freq[nums[i]]++;
            if(freq[nums[i]] > parameter) {
                return nums[i];
            }
        }
        return -1;
    }
};

// time complexity : O(nlogn)
// space complexity : O(1) ignoring sort's internal stack
// better solution not the most optimal

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 1;
        sort(nums.begin() , nums.end());
        int i;
        for(i=1 ; i<nums.size() ; i++) {
            if(nums[i] == nums[i-1]) {
                cnt++;
            }
            else {
                if(cnt > nums.size()/2) {
                    return nums[i-1];
                }
                else {
                    cnt = 1;
                }
            }
        }
        return nums[i-1];
    }
};
