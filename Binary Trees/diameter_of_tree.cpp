// time complexity : O(n)
// space complexity : O(h)
// optimized approach

/* Structure of binary tree Node 
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
    int ans = 0;
    int height(Node* root) {
        if(root == NULL) {
            return 0;
        }
        else {
            int lh = height(root->left);
            int rh = height(root->right);
            ans = max(ans , lh+rh);
            return max(lh,rh)+1;
        }
    }
  public:
    int diameter(Node* root) {
        height(root);
        return ans;
    }
};



// time complexity : O(n)
// space complexity : O(h)
// optimized approach

/* Structure of binary tree Node 
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
    pair<int,int> diameterFast(Node* root) {
        if(root == NULL) {
            pair<int,int> p = make_pair(0,0);
            return p;
        }
        else {
            pair<int,int> left = diameterFast(root->left);
            pair<int,int> right = diameterFast(root->right);
            
            int op1 = left.first;
            int op2 = right.first;
            int op3 = left.second + right.second;
            
            pair<int,int> ans;
            ans.first = max(op1 , max(op2 , op3));
            ans.second = max(left.second,right.second)+1;
            return ans;
        }
    }
  public:
    int diameter(Node* root) {
        return diameterFast(root).first;
    }
};
