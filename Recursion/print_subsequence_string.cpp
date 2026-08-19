// t.c : O(n^2 * 2^n)
// s.c : O(n * 2^n)

class Solution {
    private:
    void findSub(string &s , string output , int i , vector<string> &ans) {
        if(i == s.size()) {
            ans.push_back(output);    
        }
        else {
            // include 
            findSub(s , output + s[i] , i+1 , ans);
            // exclude
            findSub(s , output , i+1 , ans);
        }
    }
  public:
    vector<string> powerSet(string &s) {
        
        vector<string> ans;
        findSub(s , "" , 0 , ans);
        sort(ans.begin() , ans.end());
        return ans;
        
    }
};
