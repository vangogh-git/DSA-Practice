// time complexity : O(n)
// space complexity : O(n) in case of general string and O(1) in case of only lowercase a-z


class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> freq;
        for(char ch : s) {
            freq[ch] ++;
        }

        // now we have the count
        for(char ch : t) {
            if(freq.find(ch) != freq.end() ) {
                // present
                freq[ch]--;
            }
            else{
                // not present
                return false;
            }
        }

        for(auto it : freq) {
            if(it.second != 0) return false;
        }

        return true;
    }
};
