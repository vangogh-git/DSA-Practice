// time complexity : O(n+m)
// space complexity : O(n+m)

#include <iostream>
#include <unordered_map>
using namespace std;

bool validShuffle(string &str1 , string &str2 , string &shuffle) {
    unordered_map<char,int> freq;
    
    // fill the hashmap
    for(int i=0 ; i<str1.size() ; i++) {
        freq[str1[i]]++;
    }
    for(int i=0 ; i<str2.size() ; i++) {
        freq[str2[i]]++;
    }
    
    // now check with the shuffled string
    for(int i=0 ; i<shuffle.size() ; i++) {
        if(freq[shuffle[i]] != 0) {
            freq[shuffle[i]]--;
        }
        else{
            return false;
        }
    }
    for(auto it : freq) {
        if(it.second != 0) return false;
    }
    return true;
}

int main() {
    
    string str1;
    cin >> str1;
    
    string str2;
    cin >> str2;
    
    string shuffle;
    cin >> shuffle;
    
  if(validShuffle(str1 , str2 , shuffle) ) {
      cout << "yes" << endl;
  }
  else {
      cout << "no" << endl;
  }
    
}
