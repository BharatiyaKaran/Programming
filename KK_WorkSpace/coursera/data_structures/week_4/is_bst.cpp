#include <algorithm>
#include <iostream>
#include <vector>
#include <limits.h>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using namespace std;

struct Node {
  long long key;
  long long left;
  long long right;

  Node() : key(0), left(-1), right(-1) {}
  Node(long long key_, long long left_, long long right_) : key(key_), left(left_), right(right_) {}
};

struct treeNode
{
	long long key;
	treeNode* left;
	treeNode* right;
	treeNode() : key(0), left(NULL), right(NULL) {}
};


treeNode* constructBST(vector<Node>& tree)
{
	// Construct a binary search tree
	treeNode* root=NULL;
	vector<treeNode*> tPtrList;
	tPtrList.resize(tree.size());
	for(unsigned long long i=0; i<tree.size(); ++i)
	{
		treeNode* temp = new treeNode;
		if(i==0)
		{
			temp->key=tree[i].key;
			tPtrList[i]=temp;
			root=tPtrList[i];
		}
		else
		{
			temp->key=tree[i].key;
			tPtrList[i]=temp;
		}
	}
	
	// Update treeNode's left and right children information
	for(unsigned long long j=0; j<tPtrList.size(); ++j)
	{
		if(tree[j].left!=-1)
			tPtrList[j]->left=tPtrList[tree[j].left];

		if(tree[j].right!=-1)
			tPtrList[j]->right=tPtrList[tree[j].right];
	}

	return root;
}

bool checkBST(treeNode* &node, long long min, long long max)
{
	if(node==NULL)
		return true;

	if(node->key<min || node->key>max)
		return false;


	return checkBST(node->left, min, node->key)
			&& checkBST(node->right, node->key, max);

}

bool IsBinarySearchTree(treeNode* &root)
{
	if(root==NULL)
		return true;
	treeNode* temp = root;
	long long min=INT_MIN;
	long long max=INT_MAX;
	
	if(!checkBST(temp->left, min, temp->key) || !checkBST(temp->right, temp->key, max))
		return false;

	return true;
}

int main() {
  long long nodes;
  cin >> nodes;
  vector<Node> tree;
  for (long long i = 0; i < nodes; ++i) 
  {
    long long key, left, right;
    cin >> key >> left >> right;
    tree.push_back(Node(key, left, right));
  }

  treeNode* root=constructBST(tree);

  if (IsBinarySearchTree(root)) {
    cout << "CORRECT" << endl;
  } else {
    cout << "INCORRECT" << endl;
  }
  return 0;
}
