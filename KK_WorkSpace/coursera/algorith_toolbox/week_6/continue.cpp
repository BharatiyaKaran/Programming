/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : continue.cpp

* Purpose :

* Creation Date : 16-12-2020

* Last Modified : Wed Dec 16 17:22:36 2020

* Created By : Kumar Karan

* Problem Description :

_._._._._._._._._._._._._._._._._._._._._.*/

#include<iostream>

using namespace std;

int main()
{
    // Main code
	int i = 0;
	while (i < 10) {
  	if (i == 4) {
    	i++;
    	continue;
  }
  cout << i << "\n";
  i++;
}

    return 0;
}
