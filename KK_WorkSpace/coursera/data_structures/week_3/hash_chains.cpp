#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::string;
using std::vector;
using std::cin;

struct Query {
    string type, s;
    size_t ind;
};

struct Node
{
	string str;
	Node* next;
};

class LinkedList
{
	private:
		Node* head;
	
	public:


		LinkedList(Node* headRef=NULL)
		{
			head = headRef;
		}

		Node* & getHead() { return this->head; }

		Node* find(const string &input)
		{
			Node* temp = head;
			if(temp==NULL)
				return NULL;

			while(temp->next!=NULL && temp->str!=input)
			{
				temp = temp->next;
			}
			if(temp->str==input)
			{
				return temp;
			}
			else
			{
				return NULL;
			}
		}

		void add(const string &input)
		{
			Node* temp = head;
			Node* nPtr = new Node;
			nPtr->str = input;
			nPtr->next = NULL;
			if(temp==NULL)
			{
				head = nPtr;
			}
			else
			{
				head = nPtr;
				head->next = temp;
			}
		}

		void del(Node* &nodePtr)
		{	

			Node* temp = head;
			if(nodePtr==head)
			{
				head = head->next;
				delete temp;
			}
			else
			{
				Node* next  = temp;
				Node* prev  = temp;
				while(temp->next!=NULL && temp != nodePtr)
				{
					prev = temp;
					temp = temp->next;
					next = temp->next;
				}
				if(temp == nodePtr)
				{
					prev->next = next;
					delete temp;
				}
			}
		}

		void displayNodes(void)
		{
			Node* temp = this->head;
			if(temp==NULL)
				return;
			
			while(temp!=NULL)
			{
				printf("%s ", temp->str.c_str());
				temp = temp->next;
			}

		}

};

class QueryProcessor 
{
    int bucket_count;
    // store all strings in one vector
    vector<string> elems;
	//  Create a vector of chain linked lists of size bucket list
	vector<LinkedList> chainElems;

    size_t hash_func(const string& s) const 
	{
        static const size_t multiplier = 263;
        static const size_t prime = 1000000007;
        unsigned long long hash = 0;
        for (int i = static_cast<int> (s.size()) - 1; i >= 0; --i)
            hash = (hash * multiplier + s[i]) % prime;
        return hash % bucket_count;
    }

public:
    QueryProcessor(int bucket_count): bucket_count(bucket_count) 
	{
		chainElems.resize(bucket_count);
	}


    Query readQuery() const 
	{
        Query query;
        cin >> query.type;
        if (query.type != "check")
            cin >> query.s;
        else
            cin >> query.ind;
        return query;
    }

    void writeSearchResult(bool was_found) const 
	{
        std::cout << (was_found ? "yes\n" : "no\n");
    }

    void processQuery(const Query& query) 
	{
        if (query.type == "check") 
		{
            // use reverse order, because we append strings to the end
			if(chainElems[query.ind].getHead() != NULL)
			{
				chainElems[query.ind].displayNodes();
			}
            std::cout << "\n";
        } else 
		{
			unsigned int index=hash_func(query.s);
			Node* temp = NULL;
			temp = chainElems[index].find(query.s);

            if (query.type == "find")
                writeSearchResult(temp != NULL);
            else if (query.type == "add") 
			{
				if(temp == NULL)
				{
					chainElems[index].add(query.s);
				}
            } else if (query.type == "del") 
			{
				if( temp != NULL )
					chainElems[index].del(temp);
            }
        }
    }

    void processQueries() 
	{
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i)
            processQuery(readQuery());
    }
};

int main() 
{
    //std::ios_base::sync_with_stdio(false);
    int bucket_count;
    cin >> bucket_count;
    QueryProcessor proc(bucket_count);
    proc.processQueries();
    return 0;
}
