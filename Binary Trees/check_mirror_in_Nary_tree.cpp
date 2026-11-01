// t.c : O(e)
// s.c : O(e)

class Solution {
  public:
    bool checkMirrorTree(int e, vector<int>& t1, vector<int>& t2) {
        
        unordered_map<int,stack<int>> mp;
        
        // tree1 -> push
        for(int i=0 ; i<t1.size()-1 ; i+=2) {
            mp[t1[i]].push(t1[i+1]);
        }
        
        
        // tree2 -> pop
        for(int i=0 ; i<t2.size()-1 ; i+=2) {
            if(mp.count(t2[i])==0) {
                return false;
            }
            else if(mp[t2[i]].top() != t2[i+1]) {
                return false;
            }
            else {
                mp[t2[i]].pop();
            }    
        }
        return true;
    }
};
