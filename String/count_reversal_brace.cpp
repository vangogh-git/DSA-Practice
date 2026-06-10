//time complexity: O(n)
//space complexity: O(n)
// using stack

class Solution {
  public:
    int countMinReversals(string s) {
        
        // odd condition
        if(s.size() & 1) {
            return -1; // odd case
        }
        
        // valid string removal
        stack<char> st;
        for(int i=0 ; i<s.size() ; i++) {
            if(s[i] == '{') {
                st.push(s[i]);
            }
            else {
                // it is a closed brace
                if(!st.empty() && st.top() == '{') {
                    st.pop();
                }
                else{
                    st.push(s[i]);
                }
            }
        }
        
        // now find the invalid string answer
        int a=0 , b = 0;
        while(!st.empty()) {
            if(st.top() == '{') {
                a++;
            }
            else{
                b++;
            }
            st.pop();
        }
        
        return (a+1)/2 + (b+1)/2;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(1)
// optimized solution

class Solution {
  public:
    int countMinReversals(string s) {
        
        if(s.size() & 1) return -1;
        
        int open = 0;
        int reversals = 0;
        for(int i=0 ; i<s.size() ; i++) {
            if(s[i] == '{') {
                open++;
            }
            else{
                // s[i] == '}' in this case
                if(open > 0) {
                    open--;
                }
                else{
                    reversals++;
                    open++;
                }
            }
        }
        
        // remaining open braces
        reversals += (open/2);
        return reversals;
        
    }
};
