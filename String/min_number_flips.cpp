// Brute Force Solution
// Time Complexity: O(n)
// Space Complexity: O(n)


class Solution {
  public:
    int minFlips(string& s) {
        // code here
        string start_zero = "";
        string start_one = "";
        
        for(int i=0 ; i<s.size() ; i++) {
            if(i % 2 == 0) {
                start_zero.push_back('0');
                start_one.push_back('1');
            }
            else{
                //odd places 
                start_zero.push_back('1');
                start_one.push_back('0');
            }
        }
    
    int cnt_zero = 0;
    int cnt_one = 0;
    
    for(int i=0 ; i<s.size() ; i++) {
        if(s[i] == start_zero[i]) {
            cnt_zero++;
        }
        if(s[i] == start_one[i]) {
            cnt_one++;
        }
    }
    
    return min(cnt_zero , cnt_one);
        
    }
};

