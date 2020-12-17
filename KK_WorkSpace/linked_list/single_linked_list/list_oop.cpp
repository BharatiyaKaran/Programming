#include <iostream>

using namespace std;

class Node 
{
	private:
	int data;
	Node * next;

	public:
	
	// Constructor
	Node(int value = 0)
	{
		data = value;
		next = NULL;
	}

	// Getters
	int getData() const { return data;}
	Node * getNext() const { return next;}
	
	// Setters
	void setData(int value) { data = value; }
	void setNext(Node* nextElem) { next = nextElem; }
};

// Function to add nodes at the head of the linked list.
void push(Node ** head_ref, int new_data)
{
	// Create a new node
	Node * new_node = new Node;
	// Fill the data in the new node
	new_node->setData(new_data);
	// Make the new node point to the head
	new_node->setNext(*head_ref);
	// Make the new node head of the linked list
	*head_ref = new_node;
}

// Function to print the linked list data
void printList(Node * head_ref)
{
	if (head_ref == NULL)
	{
		cout << "Empty list !\n";
		return;
	}

	while(head_ref!=NULL)
	{
		cout<< head_ref->getData() << " -> ";
		head_ref = head_ref->getNext();
	}

	cout << "\n";
}


// Function to add a node at a given point in the list
void insertBefore(Node ** head_ref, int node_data, int new_data)
{
	cout << "Adding node: " << new_data << " before: " << node_data << "\n"; 
	// Empty list
	if (*head_ref == NULL)
		return;
	
	Node * prev = NULL, *curr = *head_ref;
	while(curr!=NULL && curr->getData()!=node_data)
	{
		prev = curr;
		curr = curr->getNext();
	}

	// Node is the head of the list
	if (prev == NULL)
	{
		Node * new_node = new Node;
		new_node->setData(new_data);
		new_node->setNext(*head_ref);
		*head_ref = new_node;
		return;
	}
	
	// Node found in the list
	if (curr!=NULL)
	{
		Node * new_node = new Node;
		new_node->setData(new_data);
		new_node->setNext(curr);
		prev->setNext(new_node);
		return;
	}
	else	// Node not found in the list
	{
		cout << "Node " << node_data << " not found !\n";
		return;
	}
}

void insertAtEnd(Node ** head_ref, int new_data)
{
	cout << "Adding : " << new_data << " at the end of the list\n";
	// Check for empty list
	if (*head_ref == NULL)
	{
		Node * new_node = new Node;
		new_node->setData(new_data);
		new_node->setNext(*head_ref);
		*head_ref = new_node;
		return;
	}

	Node * temp = *head_ref;

	while(temp->getNext()!=NULL)
		temp = temp->getNext();

	Node * new_node = new Node;
	new_node->setNext(NULL);
	new_node->setData(new_data);
	temp->setNext(new_node);
}

// Function to delete a given node from the list
void deleteNodeFromList(Node ** head_ref, int del_data)
{
	cout << "Deleting node : " << del_data << "\n";
	// List is empty
	if (*head_ref==NULL)
		return;

	Node * prev = NULL, * current = *head_ref;
	while(current!=NULL && current->getData()!=del_data)
	{
		prev = current;
		current = current->getNext();
	}

	// Node is the head of the list 
	if (prev == NULL)
	{
		Node * temp = *head_ref;
		*head_ref = (*head_ref)->getNext();
		delete temp;
		return;
	}
	
	// Node found, delete it
	if (current!=NULL)
	{
		prev->setNext(current->getNext());
		delete current;
		return;
	}
	else	// Node not found
	{
		cout << "Node : " << del_data << " not found in the list \n";
		return;
	}
}

// Function to delete a node from kth position in the list
void deleteNodeAtKthPosition(Node ** head_ref, int k)
{
	cout << "Deleting node from position: " << k << endl;
	
	// Check for empty list
	if (*head_ref == 0)
	{
		cout << "List is already empty \n";
		return;
	}

	// Deleting the head 
	if (k==0)
	{
		Node * temp = *head_ref;
		*head_ref = (*head_ref)->getNext();
		delete temp;
		return;
	}

	Node * prev = NULL, * curr = *head_ref;
	int count = 0;
	while ( curr!=NULL && count!=k)
	{
		prev = curr;
		curr = curr->getNext();
		count++;
	}

	// If the end of list is reached without finding the Kth node	
	if(curr == NULL)
	{
		cout << "The length of the list is smaller than value : " << k << endl;
		return;
	}
	else	// Node found
	{
		prev->setNext(curr->getNext());
		delete curr;
		return;
	}
}

// Function to delete the complete list
void deleteCompleteList(Node ** head_ref)
{
	cout << "Deleting the complete linked list\n";
	if (*head_ref == NULL)
	{
		cout << "List is already empty !\n";
		return;
	}

	Node * curr = *head_ref;
	while(curr!=NULL)
	{
		Node * nextElem = curr->getNext();
		delete curr;
		*head_ref = nextElem;
		curr = nextElem;
	}
}


int main()
{
	Node * head = NULL;

	push(&head, 5);
	push(&head, 4);
	push(&head, 3);
	push(&head, 2);
	push(&head, 1);
	push(&head, 9);
	push(&head, 12);
	push(&head, 18);
	push(&head, 0);
	printList(head);
	insertBefore(&head, 5, 99); 
	printList(head);
	insertBefore(&head, 0, 29); 
	printList(head);
	insertBefore(&head, 9, 25); 
	insertBefore(&head, 19, 45); 
	printList(head);
	deleteNodeFromList(&head, 2);
	deleteNodeFromList(&head, 4);
	deleteNodeFromList(&head, 12);
	deleteNodeFromList(&head, 0);
	printList(head);
	deleteNodeFromList(&head, 2);
	printList(head);
	insertBefore(&head, 5, 4); 
	insertBefore(&head, 3, 2); 
	insertBefore(&head, 9, 12); 
	insertBefore(&head, 29, 0); 
	printList(head);
	deleteNodeFromList(&head, 99);
	printList(head);
	insertBefore(&head, 0, 99); 
	printList(head);
	insertAtEnd(&head, 100);
	printList(head);
	deleteNodeAtKthPosition(&head, 5);
	printList(head);
	deleteNodeAtKthPosition(&head, 0);
	printList(head);
	deleteNodeAtKthPosition(&head, 90);
	printList(head);
	//deleteCompleteList(&head);
	//printList(head);
}

