#include <iostream>
#include <queue>
using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this -> data = data;
        this -> left = NULL;
        this -> right = NULL;
    }
};

Node* buildTree(Node* root) {
    cout << "enter the data: ";
    int data;
    cin >> data;
    root = new Node(data);

    if(data == -1) {
        return NULL;
    }

    cout << "enter the data to insert on the left:" << endl;
    root -> left = buildTree(root -> left);
    cout << "enter the data to insert on the right:" << endl;
    root -> right = buildTree(root -> right);
    return root;
}

void levelOrderTraversal(Node* root) {
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if(temp == NULL) {
            cout << endl;
            if(!q.empty()) {
                q.push(NULL);
            }
        }
        else {
            cout << temp -> data << " ";
            if(temp -> left) {
               q.push(temp -> left);
            }
            if(temp -> right) {
               q.push(temp -> right);
            }
        }
    }
}

int main() {

    Node* root = NULL;
    root = buildTree(root);

    levelOrderTraversal(root);
}
