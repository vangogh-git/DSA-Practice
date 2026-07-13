class Solution {
    private: 
    int binaryCount(int num) {
        int quo = num / 2;
        int rem = num % 2;
        int count = 0;
        while(quo != 0) {
            num = quo;
            rem = num % 2;
            count += rem;
            quo = num / 2;
        }
        return count;
    }
  public:
    vector<int> sortBySetBitCount(vector<int>& arr) {
        
        vector<int> ans;
        int n = arr.size();
        for(int i=0 ; i<n ; i++) {
            int count = binaryCount(arr[i]);
            cout << count << " ";
            ans.push_back(count);
        }
        cout << endl;
        return ans;
    }
};
