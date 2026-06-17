// time complexity : O(n)
// space complexity : O(n) in case of general string and O(1) in case of only lowercase a-z
// Note: we have used find() here now we need to understand that find() usually takes O(logn) time put since i am using it for unordered_map 
// which is based on hasing and not maps which are based on balanced BST hence it takes only O(1) time.


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

// same code just no need to use find()
//// important to check size of each is equal or not in the beginning itself expected in interviews/////

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        unordered_map<char,int> freq;
        for(char ch : s) {
            freq[ch]++;
        }
        for(char ch : t) {
            if(freq[ch] == 0) return false;
            freq[ch]--;
        }
        for(auto it : freq) {
            if(it.second != 0) return false; 
        }
        return true;
    }
};
