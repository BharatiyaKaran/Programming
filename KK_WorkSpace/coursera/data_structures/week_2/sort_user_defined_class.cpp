/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : sort_user_defined_class.cpp

* Purpose :

* Creation Date : 23-12-2020

* Last Modified : Wed Dec 23 22:13:35 2020

* Created By : Kumar Karan

* Problem Description :

_._._._._._._._._._._._._._._._._._._._._.*/

#include<iostream>
#include<chrono>
#include<vector>
#include<algorithm>

using namespace std;
using namespace std::chrono;

class Ticket
{
	public:
		int num;

};

class TicketComparator
{
	public:
	bool operator() (Ticket* &t1, Ticket* &t2)
	{
		if(t1->num<t2->num)
			return true;
		return false;
	}
};

int main()
{
    // Main code
	auto start = high_resolution_clock::now();
	srand(time(0));

	int count=0;
	cin>>count;

	vector<Ticket*> tPtrList;
	for(int i=0; i<count; ++i)
	{
		int val=rand()%100+1;
		Ticket* tPtr=new Ticket;
		tPtr->num=val;
		tPtrList.push_back(tPtr);
	}

	printf("Before sorting:\n");
	for( auto t: tPtrList)
		printf("Ticket#:%d\n", t->num);
	printf("\n\n");

	sort(tPtrList.begin(), tPtrList.end(), TicketComparator());

	printf("After sorting:\n");
	for( auto t: tPtrList)
		printf("Ticket#:%d\n", t->num);
	printf("\n");

	// Business logic goes here

	auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;

    return 0;
}
