// time complexity : O(n)
// space complexity : O(h) where h is the height of the tree

/* Structure of binary tree Node
class Node {
  public:
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/
class Solution {
    private:
    void buildTree(Node* &root , string &s , int &i) {
            if(i<s.size() && isdigit(s[i])) {
                int num = 0;
                while(i<s.size() && isdigit(s[i])) {
                    num = num * 10 + s[i]-'0';
                    i++;
                }
                root->data = num;
            }
            if(i < s.size() && s[i] == '(') {
                root->left = new Node(-1);
                i++;
                buildTree(root->left , s , i);
                if(root -> left -> data == -1) root->left = NULL;
            }
            if(i < s.size() && s[i] == '('){
                root -> right = new Node(-1);
                i++;
                buildTree(root->right , s , i);
                if(root-> right -> data == -1) root-> right = NULL;
            }
            if(i>= s.size() || s[i] == ')') {
                i++;
                return ;
            }
    }
  public:
    Node *treeFromString(string &s) {
        
        int i=0;
        Node* root = new Node(0);
        buildTree(root , s , i);
        return root;
    }
};
