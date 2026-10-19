// t.c : O(n)
// s.c : O(n)

/* Structure of a Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
    private:
    string solve(Node* root , unordered_map<string,int> &mapped) {
        if(root == NULL) return "$";
        string s = "";
        if(root->left == NULL && root->right == NULL) {
            s = to_string(root->data);
            return s;
        }
        
        s += to_string(root->data);
        s += "," + solve(root->left,mapped);
        s += "," + solve(root->right,mapped);
        mapped[s]++;
        return s;
    }
  public:
    bool dupSub(Node* root) {
        unordered_map<string,int> mapped;
        
        solve(root,mapped);
        for(auto it : mapped) {
            if(it.second >= 2) {
                return true;
            }
        }
        return false;
        
    }
};
