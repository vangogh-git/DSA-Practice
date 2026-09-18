// time complexity : O(n)
// space complexity : O(1)


#include <bits/stdc++.h> 
/*********************************************************

    Following is the class structure of the Node class:

    class Node
	{
	public:
	    int data;
	    Node *next;
	    Node *prev;
	    Node(int data)
	    {
	        this->data = data;
	        this->next = NULL;
	        this->prev = NULL;
	    }
	};

************************************************************/

Node* findKth(Node* &head , int k) {

	int cnt = 1;
	Node* myNode = head;
	while(cnt != k && myNode != NULL) {
		myNode = myNode -> next;
		cnt++;
	}
	return myNode;;
}

Node* reverse(Node* &head) {
	Node* prev = NULL;
	Node* curr = head;
	while(curr != NULL) {
		Node* next = curr -> next;
		curr -> next = curr -> prev;
		curr -> prev = next;
		prev = curr;
		curr = next;
	} 
	return prev;
}

Node* reverseDLLInGroups(Node* head, int k)
{	
    Node* temp = head;
	Node* prevNode = NULL;

	while(temp != NULL) {

		Node* kthNode = findKth(temp,k);

		if(kthNode == NULL) {
			Node* newHead = reverse(temp);

			if(prevNode != NULL) {
				prevNode -> next = newHead;
				newHead -> prev = prevNode;
			}
			else {
				head = newHead;
			}
			break;
		}

		Node* nextNode = kthNode -> next;
		kthNode -> next = NULL;
		if(nextNode != NULL)
			nextNode -> prev = NULL;

		kthNode = reverse(temp);
		if(temp == head) {
			head = kthNode;
		}
		else {
			prevNode -> next = kthNode;
			kthNode -> prev = prevNode;
		}
		prevNode = temp;	
		temp = nextNode;
	} 

	return head;
}

