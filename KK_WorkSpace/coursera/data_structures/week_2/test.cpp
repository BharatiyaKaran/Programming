/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : test.cpp

* Purpose :

* Creation Date : 22-12-2020

* Last Modified : Tue Dec 22 20:46:48 2020

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

	// Business logic goes here

	auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;

    return 0;
}
