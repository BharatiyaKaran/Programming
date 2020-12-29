#include <iostream>
#include <vector>
#include <algorithm>
#if defined(__unix__) || defined(__APPLE__)
#include <sys/resource.h>
#endif

using std::vector;
using std::ios_base;
using std::cin;
using std::cout;
using namespace std;

struct Node
{
	unsigned int key;
	Node* left;
	Node* right;

	Node(unsigned int data=0)
	{
		left=right=NULL;
	}
};

class TreeOrders 
{
  int n;
  vector <int> key;
  vector <int> left;
  vector <int> right;
 	Node* root;

public:

	TreeOrders() { root = NULL; }
	Node* getRoot() { return this->root; }
  void read() {
    cin >> n;
    key.resize(n);
    left.resize(n);
    right.resize(n);
    for (int i = 0; i < n; i++) {
      cin >> key[i] >> left[i] >> right[i];
    }
  }

	void construct_tree(void)
	{
		vector<Node*> nPtrList;
		nPtrList.resize(n);
		for(unsigned int i=0; i<n; ++i)
		{
			if(i==0)
			{
				Node* temp = new Node;
				temp->key = key[i];
				nPtrList[i]=temp;
				root = temp;
			}
			else
			{
				Node* temp = new Node;
				temp->key = key[i];
				nPtrList[i]=temp;
			}
		}

		for(unsigned int j=0; j<n; ++j)
		{
			// Update left and right children
			if(left[j]!=-1)
			{
				nPtrList[j]->left = nPtrList[left[j]];
			}

			if(right[j]!=-1)
			{
				nPtrList[j]->right = nPtrList[right[j]];
			}
		}

	}

 void in_order(Node* root) 
  {
	Node* temp = root;
	if(temp==NULL)
		return;
	in_order(temp->left);
	printf("%d ", temp->key);
	in_order(temp->right);
  }

  void pre_order(Node* root) 
  {
	Node* temp = root;
	if(temp==NULL)
		return;
	printf("%d ", temp->key);
	pre_order(temp->left);
	pre_order(temp->right);
  }

  void post_order(Node* root) 
  {
	Node* temp = root;
	if(temp==NULL)
		return;
	post_order(temp->left);
	post_order(temp->right);
	printf("%d ", temp->key);
  }
};


int main_with_large_stack_space() 
{
  //ios_base::sync_with_stdio(0);
  TreeOrders t;
  t.read();
  t.construct_tree();
  Node* root=t.getRoot();
  t.in_order(root);
  printf("\n");
  t.pre_order(root);
  printf("\n");
  t.post_order(root);
  printf("\n");
  return 0;
}

int main (int argc, char **argv)
{
#if defined(__unix__) || defined(__APPLE__)
  // Allow larger stack space
  const rlim_t kStackSize = 16 * 1024 * 1024;   // min stack size = 16 MB
  struct rlimit rl;
  int result;

  result = getrlimit(RLIMIT_STACK, &rl);
  if (result == 0)
  {
      if (rl.rlim_cur < kStackSize)
      {
          rl.rlim_cur = kStackSize;
          result = setrlimit(RLIMIT_STACK, &rl);
          if (result != 0)
          {
              std::cerr << "setrlimit returned result = " << result << std::endl;
          }
      }
  }
#endif

  return main_with_large_stack_space();
}

