// time Complexity : O(n! * n)
//space Complexity : O(n)
// Recursion + backtracking + swapping

class Solution {
    private:
    void solve(vector<string> &output , string &s , int i) {
        //base case
        if(i == s.size()) {
            output.push_back(s);
            return ;
        }
        unordered_set<char> used;
        for(int pos=i ; pos<s.size() ; pos++) {
            if(used.count(s[pos])) continue;
            used.insert(s[pos]);
            swap(s[pos] , s[i]);
            solve(output , s , i+1);
            //backtrack
            swap(s[pos] , s[i]);
        }
    }
  public:
    vector<string> findPermutation(string &s) {
        int n = s.size();
        vector<string> output;
        int i=0;
        solve(output , s,i);
        return output;
        
    }
};
