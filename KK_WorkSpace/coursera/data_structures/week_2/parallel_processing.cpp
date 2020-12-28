/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : parallel_processing.cpp

* Purpose :

* Creation Date : 22-12-2020

* Last Modified : Fri Dec 25 14:46:35 2020

* Created By : 

* Problem Description :

_._._._._._._._._._._._._._._._._._._._._.*/

#include<iostream>
#include<chrono>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;
using namespace std::chrono;

class Thread
{
	private:
		unsigned long long threadId;
		unsigned long long priority;		// Time when ready to process a new job, i.e, nextStartTime
        unsigned long long startTime;

	public:
		void setThreadId(unsigned long long tid) { this->threadId=tid; }
		void setPriority(unsigned long long pr) { this->priority=pr; }
        void setStartTime(unsigned long long st) { this->startTime=st; }

		unsigned long long getThreadId(void) { return this->threadId; }
		unsigned long long getPriority(void) { return this->priority; }
        unsigned long long getStartTime(void) { return this->startTime; }
};

// Comparator function for min priority queue
class ThreadPriorityComparator
{
    public:
    bool operator()(Thread* &t1, Thread* &t2)
    {
        if(t1->getPriority()!=t2->getPriority())
            return t1->getPriority()>t2->getPriority();
		//else if(t1->getStartTime()!=t2->getStartTime())
		//	return t1->getStartTime()>t2->getStartTime();
        return t1->getThreadId()>t2->getThreadId();
    }
};

class Job
{
    private:
        unsigned long long jobId;
		unsigned long long jobStartTime;
        unsigned long long timeToProcess;
		Thread *  tJptr;

    public:
        void setJobId(unsigned long long id) { this->jobId=id; }
        void setJobStartTime(unsigned long long st) { this->jobStartTime=st; }
        void setTimeToProcess(unsigned long long ttp) { this->timeToProcess=ttp; }
		void setThreadPtr(Thread* tptr) { this->tJptr=tptr; }

        unsigned long long getJobId(void) { return this->jobId; }
        unsigned long long getJobStartTime(void) { return this->jobStartTime; }
        unsigned long long getTimeToProcess(void) { return this->timeToProcess; }
		Thread * getThreadPtr(void) { return this->tJptr; }

};

class JobStartTimeComparator
{
	public:
		bool operator()(Job* &j1, Job* &j2) 
		{
			if(j1->getJobStartTime()<j2->getJobStartTime())
				return true;
			return false;
		}
};

void dumpPq(priority_queue<Thread*, vector<Thread*>, ThreadPriorityComparator> tPtrPq)
{
	printf("Dumping PQ contents\n");
	while(!tPtrPq.empty())
	{
		printf("Thread#:%lld Priority#%lld StartTime:%lld\n", 
				tPtrPq.top()->getThreadId(), tPtrPq.top()->getPriority(),
				tPtrPq.top()->getStartTime());
		tPtrPq.pop();
	}
	printf("\n");
}

void jobScheduler(vector<Job*> jPtrList, unsigned long long threadCount)
{
	// Create a priority queue of Thread pointers
	priority_queue<Thread*, vector<Thread*>, ThreadPriorityComparator> tPtrPq;
	for(unsigned long long t=0; t<threadCount; ++t)
	{
		Thread* tPtr=new Thread;
		tPtr->setThreadId(t);
		tPtr->setPriority(0);
		tPtr->setStartTime(0);
		tPtrPq.push(tPtr);
	}

	for(unsigned long long j=0; j< jPtrList.size(); ++j)
	{
		/*printf("\nJobId=%lld ThreadId:%lld, Priority:%lld, PrevJobTId:%lld\n", 
				jPtrList[j]->getJobId(), tPtrPq.top()->getThreadId(), tPtrPq.top()->getPriority(),
				prevJobThreadId);
				*/
			Thread* tPtrCurr=tPtrPq.top();
			jPtrList[j]->setThreadPtr(tPtrCurr);
			jPtrList[j]->setJobStartTime(tPtrCurr->getPriority());
			tPtrCurr->setStartTime(tPtrCurr->getPriority());
			tPtrCurr->setPriority(tPtrCurr->getStartTime() +  jPtrList[j]->getTimeToProcess());
			//printf("Assign Job#:%lld TTP:%lld  Thread#%lld and set its Priority#%lld\n", 
			//		jPtrList[j]->getJobId(), jPtrList[j]->getTimeToProcess(),
			//		tPtrCurr->getThreadId(), tPtrCurr->getPriority());
			tPtrPq.pop();
			tPtrPq.push(tPtrCurr);
			//dumpPq(tPtrPq);
	}


	sort(jPtrList.begin(), jPtrList.end(), JobStartTimeComparator());

	for(unsigned long long k=0; k<jPtrList.size(); ++k)
	{
		printf("%lld %lld\n", 
				jPtrList[k]->getThreadPtr()->getThreadId(), 
				jPtrList[k]->getJobStartTime());
	}

}

int main()
{
    // Main code
	//auto start = high_resolution_clock::now();

	// Business logic goes here
	unsigned long long numOfThreads=0, numOfJobs=0;
    cin>>numOfThreads;
    cin>>numOfJobs;

    vector<Job*> jobPtrList;
	jobPtrList.resize(numOfJobs);
    for(unsigned long long i=0; i<numOfJobs; ++i)
    {
        unsigned long long ttp=0;
        cin>>ttp;
        Job* jPtr=new Job;
        jPtr->setJobId(i);
        jPtr->setThreadPtr(NULL);
        jPtr->setJobStartTime(0);
        jPtr->setTimeToProcess(ttp);
        //jobPtrList.push_back(jPtr);
        jobPtrList[i]=jPtr;
    }

    jobScheduler(jobPtrList, numOfThreads);
/*	auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Time taken by function: "
         << duration.count() << " milliseconds" << endl;
*/
    return 0;
}
