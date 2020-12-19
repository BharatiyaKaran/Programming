/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : compute_tree_height.cpp

* Purpose :

* Creation Date : 19-12-2020

* Last Modified : Sun Dec 20 01:01:29 2020

* Created By : 

* Problem Description :

_._._._._._._._._._._._._._._._._._._._._.*/

#include<iostream>
#include<vector>
#include<algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

class Node
{
	private:
		int key;
		Node * parent;

	public:
		void setKey(int val) { key=val; }
		void setParent(Node* pPtr) { parent=pPtr; }

		int getKey(void) { return this->key; }
		Node* getParent(void) { return this->parent; }
};

int main()
{
    // Main code
	unsigned int n;
	cin>>n;
	
	vector<int> values;
	vector<Node*> treeNodes;
	auto start = high_resolution_clock::now();

	for(int i=0; i<n; ++i)
	{
		int val=0;
		cin>>val;
		values.push_back(val);
	}
	
	auto break_1 = high_resolution_clock::now();
	auto duration = duration_cast<milliseconds>(break_1 - start);
	cout << "Time taken till pushing values in vector: "
         << duration.count() << " milliseconds" << endl;


	for(int j=0; j<n; ++j)
	{
		Node* tPtr = new Node;
		tPtr->setKey(j);
		tPtr->setParent(NULL);
		treeNodes.push_back(tPtr);
	}

	auto break_2 = high_resolution_clock::now();
	duration = duration_cast<milliseconds>(break_2 - break_1);
	cout << "Time taken till pushing nodes in treeNode vector "
         << duration.count() << " milliseconds" << endl;

	for(int k=0; k<n; ++k)
	{
		if(values[k]!=-1)
		{
			treeNodes[k]->setParent(treeNodes[values[k]]);
		}
	}

	auto break_3 = high_resolution_clock::now();
	duration = duration_cast<milliseconds>(break_3 - break_2);
	cout << "Time taken till updating parent information in treeNode vector "
         << duration.count() << " milliseconds" << endl;

	// Maintain a vector for height of each node
	vector<int> nodeHeight(n,0);

	unsigned int maxHeight=0;
	for(int h=0; h<n; h++)
	{
		unsigned int count=0;
		// Take a copy of current tree node in a temporary node
		Node* tempNode=treeNodes[h];
		if(tempNode->getParent()!=NULL && nodeHeight[tempNode->getParent()->getKey()]!=0)
		//if(false)
		{	
			count=1+nodeHeight[tempNode->getParent()->getKey()];
			nodeHeight[tempNode->getKey()]=count;
			//printf("#IF->nodeHeight[%d]=%d\n", treeNodes[h]->getKey(), nodeHeight[treeNodes[h]->getKey()]);
		}
		else
		{
			if(tempNode->getParent()==NULL)
			{
				nodeHeight[tempNode->getKey()]=1;
				//printf("nodeHeight[%d]=%d\n", tempNode->getKey(), nodeHeight[tempNode->getKey()]);
			}
			else
			{
				while(tempNode->getParent()!=NULL && nodeHeight[tempNode->getKey()]==0)
				{
					//printf("Child:%d -> Parent:%d\n", tempNode->getKey(), tempNode->getParent()->getKey() );
					tempNode=tempNode->getParent();
					++count;
				}
				if(tempNode->getParent()!=NULL)
				{
					nodeHeight[treeNodes[h]->getKey()]=count+nodeHeight[tempNode->getKey()];
				}
				else
				{
					nodeHeight[treeNodes[h]->getKey()]=count+1;
				}
				//printf("#ELSE->nodeHeight[%d]=%d\n", treeNodes[h]->getKey(), nodeHeight[treeNodes[h]->getKey()]);
			}
		}
		//printf("Height for node %d = %u\n", treeNodes[h]->getKey(), count);
		//if(count>maxHeight)
		//	maxHeight=count;
		maxHeight= *max_element(nodeHeight.begin(), nodeHeight.end());
	}

	auto break_4 = high_resolution_clock::now();
	duration = duration_cast<milliseconds>(break_4 - break_3);
	cout << "Time taken for calculating HEIGHT information "
         << duration.count() << " milliseconds" << endl;

	duration = duration_cast<milliseconds>(break_4 - start);
	cout << "###Total Time taken "
         << duration.count() << " milliseconds" << endl;

	printf("%u\n", maxHeight);

    return 0;
}
