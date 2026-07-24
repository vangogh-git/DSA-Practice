//time complexity : O(n)
//space complexity: O(n)

class Solution {
  public:
    int findSubarray(vector<int> &arr) {
        int n = arr.size();
        vector<int> prefix(n,0);
        unordered_map<int,int> freq;
        int cnt = 0;
        for(int i=0 ; i<n ; i++) {
            if( i==0 ) {
                prefix[i] = arr[i];
            }
            else {
                prefix[i] = prefix[i-1] + arr[i];
            }
            if(prefix[i] == 0) cnt++;
            freq[prefix[i]]++;
        }
        
        for(auto it : freq) {
            int m = it.second;
            cnt += (m*(m-1))/2;
        }
        return cnt;
        
    }
};
