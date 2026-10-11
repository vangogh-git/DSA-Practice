// t.c : O(n)
// s.c : O(n) because of using unordered map

/* Definition for Node
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
    void solve(Node* root , int level , unordered_map<int,Node*> &mp) {
        if(root == NULL) {
            return ;
        }
        
        solve(root->left , level+1, mp);
        solve(root->right , level+1, mp);
        if(root->left == NULL && root->right == NULL) {
            mp[level] = root;
        }
    }
  public:
    bool check(Node* root) {
        unordered_map<int,Node*> mp;
        solve(root,0,mp);
        if(mp.size() > 1) return false;
        else return true;
    }
};


// t.c : O(n)
// s.c : O(h) where h is the height of the tree

/* Definition for Node
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
    bool solve(Node* root , int level , int &leafNode) {
        if(root == NULL) {
            return true;
        }
        if(root->left == NULL && root->right == NULL) {
           if(leafNode == -1) {
               leafNode = level;
           }
           return (level == leafNode);
        }
        bool left =  solve(root->left , level+1, leafNode);
        bool right = solve(root->right , level+1, leafNode);
        if(left && right) {
            return true;
        }
        else {
            return false;
        }
    }
  public:
    bool check(Node* root) {
        int leafNode = -1;
        return solve(root,0,leafNode);
    }
};
