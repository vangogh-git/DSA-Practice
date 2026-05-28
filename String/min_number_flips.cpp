class Solution {
  public:
    int minFlips(string& s) {
        
        string start_zero = "";
        string start_one = ""; 
        
        for(int i=0 ; i<s.size() ; i++) {
            if(i % 2 == 0) {
                start_zero.push_back('0');
                start_one.push_back('1');
            }
            else{
                start_zero.push_back('1');
                start_one.push_back('0');
            }
        }
        
        // now compare the final strings with the original and
        // return minimum count
        int cnt = 0;
        
        for(int i=0 ; i<s.size() ; i++) {
            if(s[i] == start_zero[i]) {
                cnt++;
            }
        }
        
        int mini = cnt;
        cnt = 0;
        for(int i=0 ; i<s.size() ; i++) {
            if(s[i] == start_one[i]) {
                cnt++;
            }
            mini = min(mini , cnt);
        }
        
        return mini;
        
          
    }
};
