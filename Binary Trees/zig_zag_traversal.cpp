// time complexity : O(n)
// space complexity: O(n)

/* Structure of Binary Tree Node
class Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
  public:
    vector<int> zigZagTraversal(Node* root) {
        
        vector<int> ans;
        queue<Node*> q;
        bool leftToRight = true;
        
        if(root == NULL) return ans;
        
        q.push(root);
        
        while(!q.empty()) {
            int size = q.size();
            vector<int> temp(size);
            
            for(int i=0 ; i<size ; i++) {
                Node* frontNode = q.front();
                q.pop();
                
                int index = leftToRight ? i : size-i-1;
                temp[index] = frontNode -> data;
                if(frontNode -> left) {
                    q.push(frontNode -> left);
                }
                if(frontNode -> right) {
                    q.push(frontNode -> right);
                }
            }
            
            leftToRight = !leftToRight;
            for(auto i : temp) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
