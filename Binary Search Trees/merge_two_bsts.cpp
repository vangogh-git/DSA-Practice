// t.c : O(n+m)
// s.c :  O(h1+h1) // if not asked to return a vector it would be this much space only

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
}; */

class Solution {
    void mergeLL(Node* &temp , Node* &temp1 , Node* &temp2) {
        
        while(temp1 != NULL && temp2 != NULL) {
            if(temp1->data < temp2->data) {
                temp -> right = temp1;
                temp1 -> left = temp;
                temp1 = temp1 -> right;
            }
            else {
                temp -> right = temp2;
                temp2 -> left = temp;
                temp2 = temp2 -> right;
            }
            temp = temp -> right;
        }
        
        while(temp1 != NULL) {
            temp -> right = temp1;
            temp1 -> left = temp;
            temp1 = temp1 -> right;
            temp = temp -> right;
        }
        
        while(temp2 != NULL) {
            temp -> right = temp2;
            temp2 -> left = temp;
            temp2 = temp2 -> right;
            temp = temp -> right;    
        }
    }
    void convert(Node* root , Node* &head) {
        if(root == NULL) {
            return ;
        }
        
        convert(root->right , head);
        
        root -> right = head;
        if(head != NULL) 
            head -> left = root;
        head = root;
        
        convert(root->left , head);
    }
  public:
    vector<int> merge(Node *r1, Node *r2) {
        
        
        Node* head1 = NULL;
        Node* head2 = NULL;
        
        convert(r1 , head1);
        convert(r2 , head2);
        
        Node* head = new Node(-1);
        Node* temp = head;
        Node* temp1 = head1;
        Node* temp2 = head2;
        mergeLL(temp,head1,head2);
        
        temp = head->right;
        
        vector<int> ans;
        while(temp != NULL) {
            ans.push_back(temp -> data);
            temp = temp ->right;
        }
        return ans;
    }
};


//t.c : O(n+m)
// s.c : O(n+m)
// better approach


// t.c : O(n+m log n+m)
// s.c : O(n+m)

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
}; */

class Solution {
    private:
    void solve(Node* root , vector<int> &inorder) {
        if(root == NULL) return ;
        
        solve(root->left , inorder);
        inorder.push_back(root->data);
        solve(root->right , inorder);
    }
    
  public:
    vector<int> merge(Node *r1, Node *r2) {
        
        vector<int> inorder1;
        vector<int> inorder2;
        
        solve(r1 , inorder1);
        solve(r2 , inorder2);
        
        vector<int> ans = inorder1;
        for(int i=0 ; i<inorder2.size() ; i++) {
            ans.push_back(inorder2[i]);
        }
        
        sort(ans.begin() , ans.end());
        return ans;
        
    }
};
