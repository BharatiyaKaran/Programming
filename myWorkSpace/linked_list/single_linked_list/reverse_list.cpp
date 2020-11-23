#include <iostream>

using namespace std;

class Node
{
	private:
		int data;
		Node * next;

	public:
		// Constructor
		Node(int value=0)
		{
			data = value;
			next = NULL;
		}

		// Copy assignment operator
		Node& operator=(const Node& other)
		{
			// Check for self assignment
			if(&other == this)
				return *this;

			this->setData(other.getData());
			this->setNext(other.getNext());

			return *this;
		}



	// Getters
	int getData() const { return data; }
	Node * getNext() const { return next; }

	// Setters
	void setData(int value) { data = value; }
	void setNext(Node * nextElem) { next = nextElem;}

};

class SingleLinkList
{
	private:
		Node * head_ref;

	public:
		// Constructor
		SingleLinkList(Node * head=NULL) { head_ref = head; }

	// Getters
	Node * getHead() const { return head_ref; }

	// Setters
	void setHead(Node * head) { head_ref = head; }

	// Methods
	void reverseLinkedList();
	void push(int data);
	void displayList();
};

void SingleLinkList::push(int data)
{
	Node * new_node = new Node;
	new_node->setData(data);
	new_node->setNext(head_ref);
	setHead(new_node);
}

void SingleLinkList::displayList()
{
	cout << "##### Printing the contents of the list #####\n";
	if (head_ref == NULL)
	{
		cout << "List is empty!\n";
		return;
	}

	Node * temp = getHead();
	while(temp!=NULL)
	{
		cout << temp->getData() << " -> ";
		temp = temp->getNext();
	}
	cout << "\n";
}

void SingleLinkList::reverseLinkedList()
{
	cout << "##### Reversing the linked list #####\n";
	if ( (head_ref == NULL) || (head_ref->getNext() == NULL))
	{
		cout << "Either the List is empty or has just one element, so do nothing!\n";
		return;
	}

	Node * prev = NULL, * curr = head_ref, * nextElem = NULL;

	while(curr!=NULL)
	{
		nextElem = curr->getNext();
		curr->setNext(prev);
		prev = curr;
		curr = nextElem;
	}

	head_ref = prev;
}

		

// Main driver program
int main()
{
	SingleLinkList * SPtr = new SingleLinkList;
	SPtr->displayList();
        SPtr->push(95);	
        SPtr->push(75);	
        SPtr->push(55);	
        SPtr->push(45);	
        SPtr->push(159);	
        SPtr->push(24);	
        SPtr->push(53);	
        SPtr->push(257);	
        SPtr->push(199);
	SPtr->displayList();
	SPtr->reverseLinkedList();
	SPtr->displayList();
}
