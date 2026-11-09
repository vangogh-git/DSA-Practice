// t.c : O(nlogn + n)
// s.c : O(n)
// brute force approach

/* Structure of a Tree Node
class Node {
  public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
    private:
    int findPos(int element , vector<int> &inorder , int instart , int inend) {
        int pos = -1;
        int i = instart;
        while(i <= inend) {
            if(inorder[i] == element) {
                pos = i;
                break;
            }
            i++;
        }
        return pos;
    } 
    Node* solve(vector<int> pre , int &preIndex , vector<int> &inorder , int instart , int inend) {
        // base case
        if(preIndex >= pre.size()) {
            return nullptr;
        }
        if(instart > inend) {
            return nullptr;
        }
        
        Node* root = new Node(pre[preIndex]);
        preIndex++;
        int pos = findPos(root->data , inorder , instart , inend);
        root -> left = solve(pre , preIndex , inorder , instart , pos-1);
        root->right = solve(pre , preIndex , inorder , pos+1 , inend);
        
        return root;
    }
  public:
    Node* preToBST(vector<int>& pre) {
        
        vector<int> inorder = pre;
        
        sort(inorder.begin() , inorder.end());
        
        int preIndex = 0;
        Node* ans = solve(pre, preIndex, inorder, 0 , inorder.size()-1);
        return ans;
    }
};


// t.c : O(3n) ~ O(n)
// s.c : O(h)

/* Structure of a Tree Node
class Node {
  public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
    private:
    Node* solve(vector<int> &pre, int &preIndex , int upperbound) {
        if(preIndex == pre.size() || pre[preIndex] > upperbound) {
            return NULL;
        }
        
        Node* root = new Node(pre[preIndex]);
        preIndex++;
        
        root -> left = solve(pre , preIndex , root->data);
        root -> right = solve(pre , preIndex , upperbound);
        return root;
    }
  public:
    Node* preToBST(vector<int>& pre) {
        
        int upperbound = INT_MAX;
        int preIndex = 0;
        return solve(pre , preIndex , upperbound);
    }
};
