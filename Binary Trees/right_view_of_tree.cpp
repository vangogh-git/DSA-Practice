// t.c : O(n)
// s.c : O(n)


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
