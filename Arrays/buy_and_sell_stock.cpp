// Using stack STL
// time complexity : O(n)
// space complexity: O(n) worst case

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        stack<int> st;
        st.push(prices[0]);

        int n = prices.size();
        int diff = 0;
        int maxDiff = INT_MIN;

        for(int i=1 ; i<n ; i++) {
            if(prices[i] > st.top() ) {
                diff = prices[i] - st.top();
                if(diff > maxDiff) {
                    maxDiff = diff;
                }
            }
            else{
                st.push(prices[i]);
            }
        }

        if(maxDiff > 0) {
            return maxDiff;
        }
        else{
            return 0;
        }
    }
};
