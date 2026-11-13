// t.c : O(n)
// s.c : O(log n) for a balanced bst but O(n) in worst case for skewed tree

/* Binary Tree Node Structure
class Node {
    public:
    int data;
     Node *left;
     Node *right;
     Node *next;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
        next = nullptr;
    }
};
*/
class Solution {
    Node* prev = NULL;
  public:
    void populateNext(Node *root) {
        
        if(root == NULL) return ;
        
        populateNext(root->left);
        if(prev != NULL) {
            prev -> next = root;
        }
        prev = root;
        populateNext(root->right);
    }
};


// t.c : O(n)
// s.c : O(n)
// brute force approach

/* Binary Tree Node Structure
class Node {
    public:
    int data;
     Node *left;
     Node *right;
     Node *next;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
        next = nullptr;
    }
};
*/
class Solution {
    private:
    void inorder(Node* root , vector<Node*> &arr) {
        if(root == NULL) return ;
        
        inorder(root->left , arr);
        arr.push_back(root);
        inorder(root->right , arr);
    }
  public:
    void populateNext(Node *root) {
        
        vector<Node*> arr;
        inorder(root,arr);
        for(int i=0 ; i<arr.size()-1 ; i++) {
            arr[i] -> next = arr[i+1];
        }
    }
};
