// t.c : O(n)
// s.c : O(h)
// using recursion

class Solution {
  public:
    bool search(Node* root, int key) {
        
        if(root == NULL) {
            return false;
        }
        if(root->data == key) {
            return true;
        }
        else {
            if(key < root->data) {
                return search(root->left,key);
            }
            if(key > root->data) {
                return search(root->right,key);
            }
        }
        
    }
};


// queue based solution
// t.c : O(n)
// s.c : O(n)

/* Definition for Node
class Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    bool search(Node* root, int key) {
        
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()) {
            Node* temp = q.front();
            q.pop();
            
            if(key > temp -> data) {
                if(temp -> right) {
                    q.push(temp->right);
                }
                else{
                    return false;
                }
            }
            if(key < temp -> data) {
                if(temp -> left) {
                    q.push(temp->left);
                }
                else{
                    return false;
                }
            }
            
            if(key == temp -> data) {
                return true;
            }
        }
        return false;
    }
};
