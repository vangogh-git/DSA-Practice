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

// time complexity : O(n)
// space complexity : O(1)
// Using BOYER MOORE'S VOTING ALGORITHM

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int element = nums[0];
        int cnt = 1;
        for(int i=1 ; i<nums.size() ; i++) {
            if(nums[i] == element) {
                cnt++;
            }
            else {
                cnt--;
                if(cnt == 0) {
                    element = nums[i];
                    cnt = 1;
                }
            }
        }
        cnt = 0;
        for(int i=0 ; i<nums.size() ; i++) {
            if(nums[i]  == element) {
                cnt++;
            }
        }
        if(cnt > nums.size()/2) return element;
        else return -1;
    }    
};
