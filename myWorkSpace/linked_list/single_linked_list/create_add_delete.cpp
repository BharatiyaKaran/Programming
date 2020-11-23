#include <iostream>

using namespace std;

class Node 
{
	public:
	int data;
	Node * next;
};

// Function to add nodes at the head of the linked list.
void push(Node ** head_ref, int new_data)
{
	// Create a new node
	Node * new_node = new Node;
	// Fill the data in the new node
	new_node->data = new_data;
	// Make the new node point to the head
	new_node->next = *head_ref;
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
		cout<< head_ref->data << " -> ";
		head_ref = head_ref->next;
	}

	cout << "\n";
}

// Function to delete a given node from the list
void deleteNodeFromList(Node ** head_ref, int data)
{
	cout << " Deleting node : " << data << "\n";
	// List is empty
	if (*head_ref==NULL)
		return;

	Node * prev = NULL, * current = *head_ref;
	while(current!=NULL && current->data!=data)
	{
		prev = current;
		current = current->next;
	}

	// Node is the head of the list 
	if (prev == NULL)
	{
		Node * temp = *head_ref;
		*head_ref = (*head_ref)->next;
		delete temp;
		return;
	}
	
	if (current!=NULL)
	{
		prev->next = current->next;
		delete current;
		return;
	}
	else
	{
		cout << " Node : " << data << " not found in the list \n";
		return;
	}
}

// Function to add a node at a given point in the list
void insertBefore(Node ** head_ref, int node_data, int new_data)
{
	cout << "Adding node: " << new_data << " before: " << node_data << "\n"; 
	// Empty list
	if (*head_ref == NULL)
		return;
	
	Node * prev = NULL, *curr = *head_ref;
	while(curr!=NULL && curr->data!=node_data)
	{
		prev = curr;
		curr = curr->next;
	}

	// Node is the head of the list
	if (prev == NULL)
	{
		Node * new_node = new Node;
		new_node->data = new_data;
		new_node->next = *head_ref;
		*head_ref = new_node;
		return;
	}

	if (curr!=NULL)
	{
		Node * new_node = new Node;
		new_node->data = new_data;
		new_node->next = curr;
		prev->next = new_node;
		return;
	}
	else
	{
		cout << "Node " << node_data << " not found !\n";
		return;
	}
}

void insertAtEnd(Node ** head_ref, int new_data)
{
	// Check for empty list
	if (*head_ref == NULL)
	{
		Node * new_node = new Node;
		new_node->data = new_data;
		new_node->next = *head_ref;
		*head_ref = new_node;
		return;
	}

	Node * temp = *head_ref;

	while(temp->next!=NULL)
		temp = temp->next;

	Node * new_node = new Node;
	new_node->next = NULL;
	new_node->data = new_data;
	temp->next = new_node;
}

void deleteCompleteList(Node ** head_ref)
{
	if (*head_ref == NULL)
	{
		cout << "List is already empty !\n";
		return;
	}

	Node * curr = *head_ref;
	while(curr!=NULL)
	{
		Node * nextElem = curr->next;
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
	deleteCompleteList(&head);
	printList(head);
}

