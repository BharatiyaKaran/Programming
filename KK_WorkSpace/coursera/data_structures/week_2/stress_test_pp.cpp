/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : parallel_processing.cpp

* Purpose :

* Creation Date : 22-12-2020

* Last Modified : Thu Dec 24 21:04:24 2020

* Created By : 

* Problem Description :

_._._._._._._._._._._._._._._._._._._._._.*/

#include<iostream>
#include<chrono>
#include<vector>
#include<queue>
#include<algorithm>
#include<unistd.h>

using namespace std;
using namespace std::chrono;

class Thread
{
	private:
		long long threadId;
		long long priority;
		long long prevJobEndTime;
        long long startTime;

	public:
		void setThreadId(long long tid) { this->threadId=tid; }
		void setPriority(long long pr) { this->priority=pr; }
		void setPrevJobEndTime(long long prJet) { this->prevJobEndTime=prJet; }
        void setStartTime(long long st) { this->startTime=st; }

		long long getThreadId(void) { return this->threadId; }
		long long getPriority(void) { return this->priority; }
		long long getPrevJobEndTime(void) { return this->prevJobEndTime; }
        long long getStartTime(void) { return this->startTime; }
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
        long long jobId;
		long long jobStartTime;
        long long timeToProcess;
		Thread *  tJptr;

    public:
        void setJobId(long long id) { this->jobId=id; }
        void setJobStartTime(long long st) { this->jobStartTime=st; }
        void setTimeToProcess(long long ttp) { this->timeToProcess=ttp; }
		void setThreadPtr(Thread* tptr) { this->tJptr=tptr; }

        long long getJobId(void) { return this->jobId; }
        long long getJobStartTime(void) { return this->jobStartTime; }
        long long getTimeToProcess(void) { return this->timeToProcess; }
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

void jobScheduler(vector<Job*> jPtrList, long long threadCount)
{
	// Create a priority queue of Thread pointers
	priority_queue<Thread*, vector<Thread*>, ThreadPriorityComparator> tPtrPq;
	for(long long t=0; t<threadCount; ++t)
	{
		Thread* tPtr=new Thread;
		tPtr->setThreadId(t);
		tPtr->setPriority(0);
		tPtr->setPrevJobEndTime(0);
		tPtr->setStartTime(0);
		tPtrPq.push(tPtr);
	}

	for(long long j=0; j< jPtrList.size(); ++j)
	{
		/*printf("\nJobId=%lld ThreadId:%lld, Priority:%lld, PrevJobTId:%lld\n", 
				jPtrList[j]->getJobId(), tPtrPq.top()->getThreadId(), tPtrPq.top()->getPriority(),
				prevJobThreadId);
				*/

			Thread* tPtrCurr=tPtrPq.top();
			jPtrList[j]->setThreadPtr(tPtrCurr);
			jPtrList[j]->setJobStartTime(tPtrCurr->getPriority());
			tPtrCurr->setStartTime(tPtrCurr->getPriority());
			//tPtrCurr->setPrevJobEndTime(jPtrList[j]->getTimeToProcess() + jPtrList[j]->getJobStartTime());
			tPtrCurr->setPriority(tPtrCurr->getPriority() + jPtrList[j]->getTimeToProcess());
			//printf("Assign Job#:%lld TTP:%lld to Thread#%lld and set Priority#%lld\n", 
			//		jPtrList[j]->getJobId(), jPtrList[j]->getTimeToProcess(),
			//		tPtrCurr->getThreadId(), tPtrCurr->getPriority());
					
			tPtrPq.pop();
			tPtrPq.push(tPtrCurr);
			//dumpPq(tPtrPq);
	}


	sort(jPtrList.begin(), jPtrList.end(), JobStartTimeComparator());

	for(unsigned long k=0; k<jPtrList.size(); ++k)
	{
		printf("%lld: %lld %lld\n", 
				jPtrList[k]->getJobId(),
				jPtrList[k]->getThreadPtr()->getThreadId(), 
				jPtrList[k]->getJobStartTime());
	}

}

int main()
{
    // Main code
	while(1)
	{
	auto start = high_resolution_clock::now();
	srand(time(0));

	// Business logic goes here
	long long numOfThreads=0, numOfJobs=0;
    //cin>>numOfThreads;
    //cin>>numOfJobs;

	numOfThreads=rand()%100000+1;
	numOfJobs=rand()%100000+1;
	
    vector<Job*> jobPtrList;
    for(long long i=0; i<numOfJobs; ++i)
    {
        long long ttp=0;
        //cin>>ttp;
		ttp=rand()%1000000000;
        Job* jPtr=new Job;
        jPtr->setJobId(i);
        jPtr->setThreadPtr(NULL);
        jPtr->setJobStartTime(0);
        jPtr->setTimeToProcess(ttp);
        jobPtrList.push_back(jPtr);
    }

    jobScheduler(jobPtrList, numOfThreads);
	printf("Threads#:%lld Jobs#:%lld\n", numOfThreads, numOfJobs);
	auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Time taken by function: "
         << duration.count() << " milliseconds" << endl;
	printf("\n##########\n");
	sleep(1);
	}

    return 0;
}
