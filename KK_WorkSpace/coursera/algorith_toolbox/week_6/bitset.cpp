/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : bitset.cpp

* Purpose :

* Creation Date : 16-12-2020

* Last Modified : Wed Dec 16 16:57:54 2020

* Created By : Kumar Karan

* Problem Description :

_._._._._._._._._._._._._._._._._._._._._.*/

#include<iostream>
#include<bitset>

using namespace std;

int main()
{
    // Main code
	bitset<4> test;
	cout<< test.set() << endl;
	cout<<"position of the bit to be set\n";
	unsigned int pos;
	cin>>pos;
	cout<< test.set(((3)-pos),0) << endl;

    return 0;
}
