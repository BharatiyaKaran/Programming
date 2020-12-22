/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : min_heapify.cpp

* Purpose :

* Creation Date : 21-12-2020

* Last Modified : Tue Dec 22 15:18:20 2020

* Created By : 

* Problem Description :

_._._._._._._._._._._._._._._._._._._._._.*/

#include<iostream>
#include<vector>

using namespace std;

class SwapVal
{
	private:
		unsigned int val1;
		unsigned int val2;
	
	public:
		void setVal1(unsigned int val) { this->val1=val; }
		void setVal2(unsigned int val) { this->val2=val; }

		unsigned int getVal1(void) { return this->val1; }
		unsigned int getVal2(void) { return this->val2; }
};

void minHeapify(vector<unsigned int> inpt)
{
	unsigned int len=inpt.size();
	vector<SwapVal*> svPtrList;
	unsigned int sCount=0;
	for(int i=(len/2-1); i>=0; --i)
	{
		int leftChildInd=2*i+1;
		int rightChildInd=2*i+2;;
		int minChildInd=0;
		if(rightChildInd>=len)
		{
			minChildInd=leftChildInd;
		}
		else
		{
			minChildInd=inpt[leftChildInd]<inpt[rightChildInd] ? leftChildInd:rightChildInd;
		}
		//printf("LCI=%d, RCI=%d, MCI=%d\n", leftChildInd, rightChildInd, minChildInd);
		
		int parentInd=i;
		while(minChildInd<len && inpt[parentInd]>inpt[minChildInd])
		{
			//printf("PI=%d, CI=%d\n", parentInd, minChildInd);
			swap(inpt[parentInd], inpt[minChildInd]);
			//printf("Swapped parent[%d]=%u and child[%d]=%u\n",parentInd, inpt[parentInd],minChildInd, inpt[minChildInd]);
			SwapVal* svPtr = new SwapVal;
			svPtr->setVal1(parentInd);
			svPtr->setVal2(minChildInd);
			svPtrList.push_back(svPtr);
			sCount++;
			parentInd=minChildInd;
			int lchInd=2*minChildInd+1;
			int rchInd=2*minChildInd+2;
			if(rchInd>=len)
			{
				minChildInd=lchInd;
			}
			else
			{
				minChildInd=inpt[lchInd]<inpt[rchInd] ? lchInd:rchInd;
			}
			//printf("#WHILE->LCI=%d, RCI=%d, MCI=%d\n", lchInd, rchInd, minChildInd);
		}
	}

	//printf("List after heapify up:\n");
	/*for(auto j: inpt)
		cout<<j<<" ";
	cout<<endl;
*/
	// Display output
	printf("%u\n", sCount);
	if (sCount>(4*len))
		printf("Swaps:%d > 4n(%d)\n", sCount, 4*len);
	for(int j=0; j<svPtrList.size(); ++j)
	{
		printf("%u %u\n", svPtrList[j]->getVal1(), svPtrList[j]->getVal2());
		//printf("%u %u\n", inpt[svPtrList[j]->getVal1()], inpt[svPtrList[j]->getVal2()]);
	}
}

int main()
{
    // Main code
	unsigned int n=0;
	cin>>n;

	vector<unsigned int> input;
	for(int i=0; i<n; ++i)
	{
		unsigned int val=0;
		cin>>val;
		input.push_back(val);
	}
	
	minHeapify(input);

    return 0;
}
