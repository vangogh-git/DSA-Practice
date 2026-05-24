// Time Complexity: O(n * m^2)
// Space Comeplexity: O(1)
// we used .find() to find the prefix match
// whcih in turn costed us O(m) time for finding


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        string prefix = strs[0];

        for(int i=0 ; i<strs.size() ; i++) {
            while(strs[i].find(prefix) != 0) {
                // shrink 
                prefix.pop_back();
                if(prefix == "") return "";
            }
        }

        return prefix;
    }
};

// Optimal Solution
// Time Complexity : O(n*m)
// Space Complexity : O(1)

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = strs[0];

        for(int i=0 ; i<strs.size() ; i++) {
            int j = 0;
            while(j < strs[i].size() && j < prefix.size() && 
                strs[i][j] == prefix[j]
            ) {
                j++;
            }

            prefix = prefix.substr(0 , j);
            if(prefix == "") return "";
        }
        return prefix;
    }
};
