#include<iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;

int main()
{
	cout<<"Hello Ayushi!\n";
	time_t myTime=time(NULL);
	printf("%s\n", ctime(&myTime));
	
	// run for loop for 10^10 times
	long long i=0, j=10000000000;
	for (i=0; i<j; ++i)
	{
		//Do nothing
	}
	myTime=time(NULL);
	printf("Time after for loop : %s\n", ctime(&myTime));

}
