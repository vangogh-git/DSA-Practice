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
    string solve(Node* root , unordered_map<string,int> &mp , vector<Node*> &ans) {
        if(root == NULL) {
            return "$";
        }
        else {
            string s = "";
            s = to_string(root->data);
            s += solve(root->left , mp , ans);
            s += solve(root->right , mp , ans);
            mp[s]++;
            if(mp[s] == 2) {
                ans.push_back(root);
            }
            return s;
        }
    }
  public:
    vector<Node*> printAllDups(Node* root) {
        vector<Node*> ans;
        unordered_map<string,int> mp;
        solve(root,mp,ans);
        
        return ans;
    }
};
