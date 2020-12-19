/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : time.cpp

* Purpose :

* Creation Date : 19-12-2020

* Last Modified : Sat Dec 19 23:27:42 2020

* Created By : Kumar Karan

* Problem Description :

_._._._._._._._._._._._._._._._._._._._._.*/

#include<iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main()
{
    // Main code
	auto start = high_resolution_clock::now();
	int count=0;
	for(long i=0; i<100000; ++i)
	{
		// do nothing
		++count;
		++count;
		++count;
	}
	auto stop = high_resolution_clock::now();

	auto duration = duration_cast<microseconds>(stop - start);

    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;

    return 0;
}
