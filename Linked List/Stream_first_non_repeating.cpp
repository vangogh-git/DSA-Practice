// this solution is brute force approach
// it will go into Time Limit Exceeded...

class Solution {
    private:
    char find_nonRepeating_char(unordered_map<char,int> freq , string &s , int i) {
        for(int j=0 ; j<=i ; j++) {
            if(freq[s[j]] == 1) {
                return s[j];
            }
        }
        return '#';
    }
  public:
    string firstNonRepeating(string &s) {
        unordered_map<char,int> freq;
        string ans = "";
        for(int i=0 ; i<s.size() ; i++) {
                freq[s[i]]++;
            ans += find_nonRepeating_char(freq,s,i);
        }
        return ans;
    }
};
