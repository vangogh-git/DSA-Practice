// time complexity : O(n)
// space complexity : O(n)

class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        vector<char> ans(s.size());
        for(int i=0 ; i<s.size() ; i++) {
            ans[indices[i]] = s[i];
        }
        string res = "";
        for(char ch : ans) {
            res += ch;
        }
        return res;
    }
};
