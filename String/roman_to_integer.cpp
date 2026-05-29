// Brute Force Approach
// Time Complexity : O(n)
// Space Complexity: O(1)

class Solution {
  public:
    int romanToDecimal(string &s) {
        
        unordered_map<char,int> value = {
            {'I', 1} , {'V' , 5} , {'X' , 10} , {'L' , 50} ,
            {'C', 100} , {'D' , 500} , {'M' , 1000}
        };
        
        int ans = 0;
        
        for(int i=0 ; i<s.size() ; ) {
            if( i+1 < s.size() &&
            ((s.substr(i ,2) == "IV") || (s.substr(i ,2) == "IX") || (s.substr(i ,2) == "XL") || (s.substr(i ,2) == "XC") || (s.substr(i ,2) == "CD") || (s.substr(i ,2) == "CM")) ){
                int temp = value[s[i+1]] - value[s[i]];
                ans += temp;
                i += 2;
            }
            else{
                ans += value[s[i]];
                i += 1;
            }
        }
        
        return ans;
    }
};


