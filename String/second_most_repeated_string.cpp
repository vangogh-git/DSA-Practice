// Time Complexity: O(n)
// Space Complexity: O(n)
// Used Mapping Aprroach


class Solution {
  public:
    int secFrequent(vector<string> &arr) {
        
        // first find the count frequency
        unordered_map<string,int> freq;
        
        for(string s: arr) {
            freq[s]++;
        }
         
         
        // edge casees
        if(arr.empty() || freq.size() == 1) {
            return -1;
        }
        
        int val = freq.begin() -> second;
        int cnt = 0;
        for(auto it : freq) {
            if(it.second == val) {
                cnt ++;
            }
        }
        
        if(cnt == freq.size()) {
            return -1;
        }
        
        // now find maxFreq
        int maxFreq = 0;
        for(auto it : freq) {
            if(it.second > maxFreq) {
                maxFreq = it.second;
            }
        }
        
        // now find second max frequency
        int secondMax = 0;
        for(auto it : freq) {
            if (it.second > secondMax && it.second < maxFreq) {
                secondMax = it.second;
            }
        }
        
        return secondMax;
    }
};
