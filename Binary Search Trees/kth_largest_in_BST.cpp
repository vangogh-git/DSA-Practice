// t.c : O(n)
// s.c : O(h)
// better approach

/* Structure of a Binary Tree Node
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
    void inorder(Node* root , int k , int &cnt, int &ans) {
        if(root == NULL) {
            return ;
        }
        
        inorder(root->right , k , cnt, ans);
        cnt++;
        if(cnt == k) ans = root->data;
        inorder(root->left,k , cnt, ans);
    }
  public:
    int kthLargest(Node *root, int k) {
        int cnt = 0;
        int ans = -1;
        inorder(root,k,cnt,ans);
        
        return ans;
    }
};


// t.c : O(n)
// s.c : O(h)

/* Structure of a Binary Tree Node
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
    void inorder(Node* root , vector<int> &arr) {
        if(root == NULL) {
            return ;
        }
        
        inorder(root->left , arr);
        arr.push_back(root->data);
        inorder(root->right,arr);
    }
  public:
    int kthLargest(Node *root, int k) {
        
        vector<int> arr;
        inorder(root,arr);
        
        return arr[arr.size()-k];
    }
};
