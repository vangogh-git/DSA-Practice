// t.c : O(n)
// s.c : O(n)
// queue based approach

/*
Definition for Node
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
  public:
    vector<int> rightView(Node *root) {
        
        vector<int> ans;
        if(root == NULL) {
            return ans;
        }
        ans.push_back(root->data);
        
        queue<Node*> q;
        q.push(root);
        q.push(NULL);
        
        while(!q.empty()) {
            Node* temp = q.front();
            q.pop();
            
            if(temp != NULL) {
                if(temp -> right) {
                    q.push(temp -> right);
                }
                if(temp -> left) {
                    q.push(temp -> left);
                }
            }
            if(temp == NULL) {
                if(!q.empty() && q.front()!=NULL) {
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

// t.c: O(n)
// s.c : O(n)
// recursive approach

/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

class Solution {
    private:
    void solve(Node* root , vector<int> &ans , int level){
        
        // base case
        if(root == NULL){
            return ;
        }
        
        if(level == ans.size()){
            ans.push_back(root -> data);
        }
        
        solve(root -> right , ans , level + 1);
        solve(root -> left , ans , level + 1);
        
    }
  public:
    vector<int> rightView(Node *root) {
       
       vector<int> ans;
       solve(root , ans , 0);
       return ans;
        
    }
};
