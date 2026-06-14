// Time Complexity : O(n)
// Space Comeplexity : O(n)
// NON-RECURSIVE SOLUTION


class Solution {
  public:
    string removeDuplicates(string& s) {
        string ans = "";
        char prev = '#';
        for(int i=0 ; i<s.size() ; i++) {
            if(s[i] != prev) {
                ans += s[i];
                prev = s[i];
            }
        }
        
        return ans;
    }
};

/////////////////////////
// RECURSIVE SOLUTION

class Solution {
    private: 
    void solve(string &s , string &ans , char prev , int index){
        // base case
        if(index >= s.size()) {
            return ;
        }
        
        if(s[index] != prev) {
            ans += s[index];
            prev = s[index];
        }
        
        solve(s , ans , prev , index + 1);
    }
  public:
    string removeDuplicates(string& s) {
        int i = 0;
        string ans = "";
        char prev = '#';
        solve(s , ans , prev , i);
        return ans;
    }
};


// STACK BASED APPROACH
// T.C : O(n)
// S.C : O(n)
class Solution {
  public:
    string removeDuplicates(string& s) {
        
        stack<char> st;
        
        for(char ch : s) {
            if(st.empty() || ch != st.top() ) {
                st.push(ch);
            }
        }
        
        // now we have the required stack
        // stack -> ans
        string ans = "";
        
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }
        
        // we reverse ans and return it
        reverse(ans.begin() , ans.end());
        return ans;
    }
};
