// time complexity : O(n)
// space complexity : O(1)
// brute force approach

/* Structure of Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right; 
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
    vector<int> reverseLevelOrder(Node *root) {
        vector<int> ans;
        queue<Node*> q;
        
        q.push(root);
        
        while(!q.empty()) {
            Node* temp = q.front();
            ans.push_back(temp->data);
            q.pop();
            
            if(temp -> right) {
                q.push(temp -> right);
            }
            
            if(temp -> left) {
                q.push(temp -> left);
            }
        }
        
        int i=0;
        int j=ans.size()-1;
        
        while(i <= j) {
            swap(ans[i++] , ans[j--]);
        }
        
        return ans;
    }
};


// time complexity : O(n)
// space complexity : O(1)
// stack based approach

/* Structure of Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right; 
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
    vector<int> reverseLevelOrder(Node *root) {
        vector<int> ans;
        stack<Node*> s;
        queue<Node*> q;
        
        q.push(root);
        
        while(!q.empty()) {
            Node* temp = q.front();
            s.push(temp);
            q.pop();
            
            if(temp -> right) {
                q.push(temp -> right);
            }
            
            if(temp -> left) {
                q.push(temp -> left);
            }
        }
        
        while(!s.empty()) {
            ans.push_back(s.top()->data);
            s.pop();
        }
        
        return ans;
    }
};
