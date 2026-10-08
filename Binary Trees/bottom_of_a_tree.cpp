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
    vector<int> bottomView(Node *root) {
        vector<int> ans;
        map<int,int> mp;
        queue<pair<Node*,int>> q;
        if(root == NULL) {
            return ans;
        }
        
        q.push(make_pair(root,0));
        
        while(!q.empty()) {
            pair<Node* , int> temp = q.front();
            q.pop();
            
            Node* frontNode = temp.first;
            int pos = temp.second;
            
            mp[pos] = frontNode -> data;
            
            if(frontNode -> left) {
                q.push(make_pair(frontNode->left,pos-1));
            }
            if(frontNode -> right) {
                q.push(make_pair(frontNode->right,pos+1));
            }
        }
        for(auto &it : mp) {
            ans.push_back(it.second);
        }
        return ans;
    }
};
