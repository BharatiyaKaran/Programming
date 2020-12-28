/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : min_priority_queue.cpp

* Purpose :

* Creation Date : 23-12-2020

* Last Modified : Wed Dec 23 14:45:29 2020

* Created By : Kumar Karan

* Problem Description :

_._._._._._._._._._._._._._._._._._._._._.*/

#include<iostream>
#include <chrono>
#include<queue>

using namespace std;
using namespace std::chrono;

class Thread
{
	private:
	long long threadId;
	long long priority;

	public:
	void setThreadId(long long tid) { this->threadId=tid; }
	void setPriority(long long pr) { this->priority=pr; }

	long long getThreadId(void) { return this->threadId; }
	long long getPriority(void) { return this->priority; }
};

class ThreadPriorityComparator
{
	public:
	bool operator()(Thread* &t1, Thread* &t2)
	{
		if(t1->getPriority()>t2->getPriority())
			return true;
		return false;
	}
};

int main()
{
    // Main code
	auto start = high_resolution_clock::now();

	// Business logic goes here
	priority_queue<Thread*, vector<Thread*>, ThreadPriorityComparator> tPtrPq;
	long long num=0;
	cin>>num;

	for(long long i=0; i<num; ++i)
	{
		Thread* tPtr=new Thread;
		long long pr=0;
		cin>>pr;
		tPtr->setPriority(pr);
		tPtr->setThreadId(i);
		tPtrPq.push(tPtr);
	}

	for(long long i=0; i<num; ++i)
    {
		printf("TId:%lld , Priority:%lld\n", tPtrPq.top()->getThreadId(), tPtrPq.top()->getPriority());
		tPtrPq.pop();
	}

	auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;

    return 0;
}
