/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : compute_tree_height.cpp

* Purpose :

* Creation Date : 19-12-2020

* Last Modified : Sun Dec 20 17:00:04 2020

* Created By : 

* Problem Description :

_._._._._._._._._._._._._._._._._._._._._.*/

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

class Node
{
	private:
		int key;
		Node * parent;
		int height;

	public:
		void setKey(int val) { key=val; }
		void setHeight(int ht) { height=ht; }
		void setParent(Node* pPtr) { parent=pPtr; }

		int getKey(void) { return this->key; }
		int getHeight(void) { return this->height; }
		Node* getParent(void) { return this->parent; }
};

int main()
{
    // Main code
	unsigned int n;
	cin>>n;
	
	vector<int> values;
	vector<Node*> treeNodes;
	//auto start = high_resolution_clock::now();

	for(int i=0; i<n; ++i)
	{
		int val=0;
		cin>>val;
		values.push_back(val);
	}
	
	/*auto break_1 = high_resolution_clock::now();
	auto duration = duration_cast<milliseconds>(break_1 - start);
	cout << "Time taken till pushing values in vector: "
         << duration.count() << " milliseconds" << endl;
*/

	for(int j=0; j<n; ++j)
	{
		Node* tPtr = new Node;
		tPtr->setKey(j);
		tPtr->setParent(NULL);
		if(values[j]==-1)
			tPtr->setHeight(1);
		else
			tPtr->setHeight(0);
		treeNodes.push_back(tPtr);
	}

	/*auto break_2 = high_resolution_clock::now();
	duration = duration_cast<milliseconds>(break_2 - break_1);
	cout << "Time taken till pushing nodes in treeNode vector "
         << duration.count() << " milliseconds" << endl;
*/
	for(int k=0; k<n; ++k)
	{
		if(values[k]!=-1)
		{
			treeNodes[k]->setParent(treeNodes[values[k]]);
		}
	}

	/*auto break_3 = high_resolution_clock::now();
	duration = duration_cast<milliseconds>(break_3 - break_2);
	cout << "Time taken till updating parent information in treeNode vector "
         << duration.count() << " milliseconds" << endl;
*/
	unsigned int maxHeight=0;
	for(int h=0; h<n; h++)
	{
		unsigned int count=0;
		// Take a copy of current tree node in a temporary node
		Node* tempNode=treeNodes[h];

		//printf("\n###LOOP For %d ###\n", tempNode->getKey());

		if(tempNode->getHeight()!=0)
		{
			//printf("Already calculated height of %d=%d, continue..\n", tempNode->getKey(), tempNode->getHeight());
			continue;
		}

		if(tempNode->getParent()!=NULL && tempNode->getParent()->getHeight()!=0)
		{	
			count=1+tempNode->getParent()->getHeight();
			tempNode->setHeight(count);
			//printf("#IF->Parent height available, set Height of %d to %d\n", treeNodes[h]->getKey(), treeNodes[h]->getHeight());
		}
		else
		{
				queue<Node*> parentQ;
				while(tempNode->getParent()!=NULL && tempNode->getParent()->getHeight()==0)
				{
					//printf("Child:%d -> Parent:%d\n", tempNode->getKey(), tempNode->getParent()->getKey() );
					//printf("Child Height:%d -> Parent Height:%d\n", tempNode->getHeight(), tempNode->getParent()->getHeight() );
					tempNode=tempNode->getParent();
					++count;
					parentQ.push(tempNode);
				}
					treeNodes[h]->setHeight(1+count+tempNode->getParent()->getHeight());
					while(!parentQ.empty())
					{
						--count;
						parentQ.front()->setHeight(1+count+tempNode->getParent()->getHeight());
						//printf("#Queue: Set height of %d to %d\n", parentQ.front()->getKey(), parentQ.front()->getHeight());
						parentQ.pop();
					}
				
				//printf("#ELSE->Parent height NOT available, set Height of %d to %d\n", treeNodes[h]->getKey(), treeNodes[h]->getHeight());
		}
	}
		for(int m=0; m<treeNodes.size(); ++m)
		{
			if(treeNodes[m]->getHeight()>maxHeight)
				maxHeight=treeNodes[m]->getHeight();
		}

	/*auto break_4 = high_resolution_clock::now();
	duration = duration_cast<milliseconds>(break_4 - break_3);
	cout << "Time taken for calculating HEIGHT information "
         << duration.count() << " milliseconds" << endl;
*/
/*	auto end = high_resolution_clock::now();
	auto duration = duration_cast<milliseconds>(end - start);
	cout << "###Total Time taken "
         << duration.count() << " milliseconds" << endl;
*/
	printf("%u\n", maxHeight);

    return 0;
}
