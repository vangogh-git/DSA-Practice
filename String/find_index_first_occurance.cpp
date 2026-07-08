// time complexity : O(n*m)
// space complexity : O(1)
// brute force Approach

class Solution {
public:
    int strStr(string haystack, string needle) {
        int index = -1;
        int n = haystack.size();
        int m = needle.size();
        // edge cases
        if(n == 0 || n < m) return -1;

        for(int i=0 ; i<n ; i++) {
            if(haystack[i] == needle[0]) {
                index = i;
                int k = i+1;
                int j = 1;
                bool found = true;
                while(j < m && k < n) {
                    if(needle[j] == haystack[k] ) {
                        k++;
                    }
                    else{
                        k = i+1;
                        found = false;
                        break;
                    }
                }
                if(found) {
                    return index;
                    break;
                }
                else {
                    index = -1;
                }
            }
        }
        return -1;
    }
};
