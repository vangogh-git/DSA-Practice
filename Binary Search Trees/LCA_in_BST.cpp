// t.c : O(h)
// s.c : O(1)
// optimized approach

/* Structure of a Binary Search Tree node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    Node* findLCA(Node* root, Node* n1, Node* n2) {
        
        Node* ans = NULL;
        
        while(root != NULL) {
            if(root->data > n1->data && root->data > n2->data) {
                ans = root;
                root = root->left;
            }
            else if(root->data < n1->data && root->data < n2->data) {
                ans = root;
                root = root->right;
            }
            else {
                ans = root;
                break;
            }
        }
        return ans;
        
    }
};




// t.c : O(n)
// s.c : O(h)
// brute force approach

/* Structure of a Binary Search Tree node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    Node* findLCA(Node* root, Node* n1, Node* n2) {
        
        if(root == NULL) return NULL;
        else {
            Node* left = findLCA(root->left,n1,n2);
            Node* right = findLCA(root->right , n1,n2);
            
            if(root->data == n1->data || root->data == n2->data) {
                return root;
            }
            
            if(left != NULL && right != NULL) {
                return root;
            }
            else if(left == NULL && right !=NULL) {
                return right;
            }
            else if(left != NULL && right == NULL) {
                return left;
            }
            else {
                return NULL;
            }
        }
        
    }
};

//t.c : O(n)
// s.c : O(n)

/* Structure of a Binary Search Tree node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
    void finda1(Node* root , vector<Node*> &a1 , Node* n1) {
        while(root != NULL) {
            a1.push_back(root);
            if(root -> data < n1->data) {
                root = root->right;
            }
            else if(root -> data > n1->data) {
                root = root->left;
            }
            else{
                // found n1
                break;
            }
        }
    }
    
    void finda2(Node* root , vector<Node*> &a2 , Node* n2) {
        while(root != NULL) {
            a2.push_back(root);
            if(root -> data < n2->data) {
                root = root->right;
            }
            else if(root -> data > n2->data) {
                root = root->left;
            }
            else{
                // found n2
                break;
            }
        }
    }
  public:
    Node* findLCA(Node* root, Node* n1, Node* n2) {
        
        vector<Node*> a1;
        vector<Node*> a2;
        
        finda1(root,a1,n1);
        finda2(root,a2,n2);
        
        int  i=0 , j=0;
        Node* ans = NULL;
        while(i < a1.size() && j < a2.size()) {
            if(a1[i] == a2[j]) {
                ans = a1[i];
            }
            i++;
            j++;
        }
        return ans;
        
        
    }
};
