// t.c : O(n)
// s.c : O(n)

/* Structure for tree and linked list
class Node {
  public:
    int data;
    Node *left, *right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};*/
class Solution {
    private:
    void solve(Node* root , vector<Node*> &arr) {
        if(root == NULL) {
            return ;
        }
        else {
            solve(root->left ,arr);
            arr.push_back(root);
            solve(root->right , arr);
        }
    }
  public:
    Node* treeToDLL(Node* root) {
    
        vector<Node*> arr;
        solve(root , arr);
        
        Node* newNode = new Node(-1);
        Node* temp = newNode;
        
        for(int i=0 ; i<arr.size() ; i++) {
            temp -> right = arr[i];
            temp -> right -> left = temp;
            temp = temp -> right;
        }
        
        Node* head = newNode -> right;
        head -> left = NULL;
        newNode -> right = NULL;
        return head;
    }
};

// t.c : O(n)
// s.c : O(h) where h is the height of the recursive tree.

/* Structure for tree and linked list
class Node {
  public:
    int data;
    Node *left, *right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};*/
class Solution {
    private:
    void solve(Node* root , Node* &temp) {
        if(root == NULL) {
            return ;
        }
        else {
            solve(root->left ,temp);
            temp -> right = root;
            temp -> right -> left = temp;
            temp = temp -> right;
            solve(root->right , temp);
        }
    }
  public:
    Node* treeToDLL(Node* root) {
    
        Node* newNode = new Node(-1);
        Node* temp = newNode;

        solve(root , temp);
        
        Node* head = newNode -> right;
        head -> left = NULL;
        newNode -> right = NULL;
        return head;
    }
};
