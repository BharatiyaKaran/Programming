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
	int getData() const { return data; }
	Node * getNext() const { return next; }

	// Setters
	void setData(int value) { data = value; }
	void setNext(Node * node) { next = node; }
};

class SingleLinkList
{
	private:
		Node * head_ref;

	public:
		// Constructor
		SingleLinkList( Node * head = NULL)
		{
			head_ref = head;
		}

		// Copy assignment operator
		SingleLinkList& operator=(SingleLinkList& other)
		{
			// Check for self assignment
			if (&other == this)
				return *this;

			this->setHead(other.getHead());

			return *this;
		}

	// Getters
	Node * getHead() const { return head_ref; }

	// Setters
	void setHead(Node * head) { head_ref = head; }

	// Methods
	Node* mergeTwoSortedLists(Node * head1, Node * head2);
	void push(int new_data);
	void displayList();
};

// Function to add a node at the head
void SingleLinkList::push(int new_data)
{
	Node *  new_node = new Node;
	new_node->setData(new_data);
	new_node->setNext(this->getHead());
	this->setHead(new_node);
}

// Function to display the contents of the list
void SingleLinkList::displayList()
{
	cout << "Printing list contents ...\n";

	// Check for empty list
	if (this->getHead() == NULL)
	{
		cout << "List is empty!\n";
		return;
	}

	Node * temp = this->getHead();
	
	while(temp!=NULL)
	{
		cout << temp->getData() << " -> " ;
		temp = temp->getNext();
	}
	cout << "\n";
}

// Function to merge two sorted lists
Node *  SingleLinkList::mergeTwoSortedLists(Node * head1, Node * head2)
{
	cout << "Merging two sorted lists ...\n";

	// Check if both the heads are same
	if (head1 == head2)
	{
		cout << "Both heads are same, do nothing ...\n";
		return head1;
	}

	// Check if either of the 2 lists is empty
	if (head1 == NULL)
	{
		if (head2 == NULL)
			return NULL;
		else
			return head2;
	}
	else
	{
		if (head2 == NULL)
			return head1;
	}

	Node * SortedHead = NULL;
	
	if (head1->getData() <= head2->getData() )
	{
		SortedHead = head1;
		head1 = head1->getNext();
	}
	else
	{
		SortedHead = head2;
		head2 = head2->getNext();
	}

	Node * temp = SortedHead;

	while ( head1 != NULL && head2 != NULL)
	{
		if ( head1->getData() <= head2->getData() )
		{ 
			temp->setNext(head1);
			temp = temp->getNext();
			head1 = head1->getNext();

		}
		else
		{
			temp->setNext(head2);
			temp = temp->getNext();
			head2 = head2->getNext();
			
		}
	}

	if (head1==NULL)
		temp->setNext(head2);
	else
		temp->setNext(head1);

	return SortedHead;
}
// Main driver program
int main()
{
	SingleLinkList SObj1, SObj2;
	SingleLinkList * SPtr1 = & SObj1;
	SingleLinkList * SPtr2 = & SObj2;
	SingleLinkList SortedObj;
	SingleLinkList * SortedPtr = & SortedObj;

	SPtr1->displayList();

	SPtr2->push(64);
	SPtr2->push(59);
	SPtr2->push(36);
	SPtr2->push(15);
	SPtr2->push(5);
	SPtr2->push(5);
	SPtr2->push(3);
	SPtr2->push(2);
	SPtr2->displayList();

	SortedPtr->setHead(SortedPtr->mergeTwoSortedLists(SPtr1->getHead(), SPtr2->getHead()));
	cout << "Merged sorted list :\n";
	SortedPtr->displayList();
}
