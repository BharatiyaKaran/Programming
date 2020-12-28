#include <iostream>
#include <vector>
#include<queue>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;
using namespace std;

class Thread
{
    private:
        int threadId;
        long long priority;        // Time when ready to process a new job, i.e, nextStartTime
        long long startTime;

    public:
        void setThreadId(int tid) { this->threadId=tid; }
        void setPriority(long long pr) { this->priority=pr; }
        void setStartTime(long long st) { this->startTime=st; }

        int getThreadId(void) { return this->threadId; }
        long long getPriority(void) { return this->priority; }
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
        //  return t1->getStartTime()>t2->getStartTime();
        return t1->getThreadId()>t2->getThreadId();
    }
};


class JobQueue {
 private:
  int num_workers_;
  vector<int> jobs_;

  vector<int> assigned_workers_;
  vector<long long> start_times_;

  void WriteResponse() const {
    for (int i = 0; i < jobs_.size(); ++i) {
      cout << assigned_workers_[i] << " " << start_times_[i] << "\n";
    }
  }

  void ReadData() {
    int m;
    cin >> num_workers_ >> m;
    jobs_.resize(m);
    for(int i = 0; i < m; ++i)
      cin >> jobs_[i];
  }

  void AssignJobs() 
  {
    // Create a priority queue of Thread pointers
    priority_queue<Thread*, vector<Thread*>, ThreadPriorityComparator> tPtrPq;
    for(unsigned long long t=0; t<num_workers_; ++t)
    {
        Thread* tPtr=new Thread;
        tPtr->setThreadId(t);
        tPtr->setPriority(0);
        tPtr->setStartTime(0);
        tPtrPq.push(tPtr);
    }
		
    assigned_workers_.resize(jobs_.size());
    start_times_.resize(jobs_.size());
    vector<long long> next_free_time(num_workers_, 0);
    for (int i = 0; i < jobs_.size(); ++i) 
	{
      int duration = jobs_[i];
      /*int next_worker = 0;
      for (int j = 0; j < num_workers_; ++j) {
        if (next_free_time[j] < next_free_time[next_worker])
          next_worker = j;
      }
      assigned_workers_[i] = next_worker;
      start_times_[i] = next_free_time[next_worker];
      next_free_time[next_worker] += duration;
	  */
	  Thread* tPtrCurr=tPtrPq.top();
	  assigned_workers_[i] = tPtrCurr->getThreadId();
	  start_times_[i] = next_free_time[tPtrCurr->getThreadId()];
	  next_free_time[tPtrCurr->getThreadId()] += duration;
	  tPtrCurr->setPriority(next_free_time[tPtrCurr->getThreadId()]);
	  tPtrPq.pop();
	  tPtrPq.push(tPtrCurr);
    }
  }

 public:
  void Solve() {
    ReadData();
    AssignJobs();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  JobQueue job_queue;
  job_queue.Solve();
  return 0;
}
