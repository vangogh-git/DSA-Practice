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
