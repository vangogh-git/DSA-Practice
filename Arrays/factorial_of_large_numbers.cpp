// Time Complexity: O(n^2)
// Space Complexity: O(1)


// User function template for C++

class Solution {
  public:
    vector<int> factorial(int n) {
        // code here
        vector<int> ans;
        ans.push_back(1);
        for(int i=2 ; i<=n ; i++) {
            int carry = 0;
            
            for(int j=0 ; j<ans.size() ; j++) {
                int val = ans[j] * i + carry;
                int digit = val % 10;
                ans[j] = digit;
                carry = val / 10;
            }
            
            while(carry) {
                ans.push_back(carry % 10);
                carry /= 10;
            }
        }
        reverse(ans.begin() , ans.end());
        return ans;
    }
};
