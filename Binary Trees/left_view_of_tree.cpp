// t.c : O(n)
// s.c : O(n)
// queue based approach

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
    vector<int> leftView(Node *root) {
        
        
        vector<int> ans;
        queue<Node*> q;
        q.push(root);
        q.push(NULL);
        
        if(root == NULL) return ans;

        ans.push_back(root->data);
        
        while(!q.empty()) {
            Node* temp = q.front();
            q.pop();
            
            if(temp != NULL) {
                if(temp -> left) {
                    q.push(temp -> left);
                }
                if(temp ->right) {
                    q.push(temp -> right);
                }
            }
            if(temp == NULL) {
                if(!q.empty() && q.front() != NULL) {
                    q.push(NULL);
                    ans.push_back(q.front()->data);
                }
                else {
                    break;
                }
            }
        }
        return ans;
    }
};


// t.c : O(n)
// s.c : O(n)
// recursive approach

/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

class Solution {
    private:
    void solve(Node* root , vector<int> &ans , int level){
        
        if(root == NULL){
            return ;
        }
        
        // if new level is entered into
        if(level == ans.size()){
            ans.push_back(root -> data);
        }
        
        solve(root -> left , ans , level + 1);
        solve(root -> right , ans , level + 1);
        
    }
  public:
    vector<int> leftView(Node *root) {
        
        vector<int> ans;
        solve(root , ans , 0);
        return ans;
        
    }
};
