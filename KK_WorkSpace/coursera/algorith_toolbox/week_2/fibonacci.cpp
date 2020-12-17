#include<iostream>
#include<vector>
using namespace std;

int main()
{
	unsigned int n = 0;
	//cout << "Enter the value of n for printing the Fibonacci series\n";
	cin >> n;
	vector <unsigned int> fibVec;
	fibVec.push_back(0);
	fibVec.push_back(1);

	for ( auto i = 2; i<=n ; ++i)
	{
		  fibVec.push_back(fibVec[i-1] + fibVec[i-2]) ;
	}
	
	/*auto count = 0;
	for (auto it: fibVec)
	{
		cout << fibVec[count] << endl;
		cout << it << " ; "  << endl;
		++count;
	}
	cout << endl;*/
	if ( n <= 1)
	{
		cout << n << endl;
	}
	else
	{
		cout << fibVec[n] << endl;
	}
	return 0;
}
