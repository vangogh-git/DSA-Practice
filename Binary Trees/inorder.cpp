// time complexity : O(n)
// space complexity : O(h) // recursive call stack where h is the height of the tree

/* Structure of Binary Tree Node
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
    void inorder(Node* &root , vector<int> &ans) {
        if(root == nullptr) {
            return ;
        }
        else {
            inorder(root->left , ans);
            ans.push_back(root->data);
            inorder(root->right , ans);
        }
    }
  public:
    vector<int> inOrder(Node* root) {
        
        vector<int> ans;
        inorder(root , ans);
        return ans;
    }
};


// time complexity : O(n)
// space complexity : O(n) // stack data structure

/* Structure of Binary Tree Node
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
  public:
    vector<int> inOrder(Node* root) {
        vector<int> ans;
        stack<Node*> s;
        
        Node* curr = root;
        
        while(curr!=nullptr || !s.empty()) {
            while(curr != nullptr) {
                s.push(curr);
                curr = curr -> left;
            }
            
            curr = s.top();
            s.pop();
            
            ans.push_back(curr -> data);
            curr = curr -> right;
        }
        return ans;
    }
};
