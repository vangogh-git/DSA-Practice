// time complexity : O(n^2)
// space complexity : O(1)
// brute force approach

class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& arr) {
        
        vector<int> ans;
        for(int i=0 ; i<arr.size() ; i++) {
            int product = 1;
            for(int j=0 ; j<arr.size() ; j++) {
                if(j == i) {
                    continue;
                }
                else {
                    product *= arr[j];
                }
            }
            ans.push_back(product);
        }
        return ans;
    }
};

// time complexity : O(n)
// space complexity : O(n)
// better approach

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n) , suffix(n) , answer;

        prefix[0] = nums[0];
        for(int i=1 ; i<n ; i++) {
            prefix[i] = prefix[i-1] * nums[i];
        }

        suffix[n-1] = nums[n-1];
        for(int i=n-2 ; i>=0 ; i--) {
            suffix[i] = suffix[i+1] * nums[i];
        }

        for(int i=0 ; i<n ; i++) {
            if(i == 0) {
                answer.push_back(suffix[i+1]);
            }
            else if(i == n-1) {
                answer.push_back(prefix[i-1]);
            }
            else {
                answer.push_back(suffix[i+1] * prefix[i-1]);
            }
        }

        return answer;

        
    }
};

// time complexity : O(n)
// space complexity : O(1)
// optimal Approach -> interview level




