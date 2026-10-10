// time complexity : O(nlogd) where d is the number of diagonals
// space complexity : O(n)

/* Structure of binary tree node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
    private:
    void solve(Node* root , int pos , map<int,vector<int>> &mp) {
        if(root == NULL) {
            return ;
        }
        else {
            mp[pos].push_back(root->data);
            
            solve(root->left , pos+1 , mp);
            solve(root->right , pos , mp);
        }
    }
  public:
    vector<int> diagonal(Node *root) {
        
        map<int,vector<int>> mp;
        vector<int> ans;
        if(root == NULL) return ans;
        
        solve(root , 0 , mp);

        for(auto it: mp) {
            for(int val : it.second) {
                ans.push_back(val);
            }
        } 
        return ans;
    }
};
