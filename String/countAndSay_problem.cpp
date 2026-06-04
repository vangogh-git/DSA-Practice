//time complexity : O(length * 2^n)
//space complexity : O(n)
// using replace function -> brute force approach

class Solution {
    private:
    void solve(int n , string &s) {
        //base case
        if( n== 1){
            s = "1";
            return ;
        }

        solve(n-1 , s);
        
        
        int cnt = 1;
        for(int i=0 ; i<s.size() ; i++) {
            char element = s[i];
            if(i+1 < s.size() && s[i] == s[i+1] ) {
                cnt++;
            }
            else if(i + 1 == s.size() || s[i] != s[i+1]) {
                s.replace(i-cnt+1 , cnt , to_string(cnt) + element);
                i = (i - cnt + 1) + 1;
                cnt = 1;
            }
        }
    }
public:
    string countAndSay(int n) {
        string s = "";
        solve(n , s);
        return s;

    }
};
