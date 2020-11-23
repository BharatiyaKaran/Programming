#include<iostream>
#include<vector>
using namespace std;

int main()
{
	unsigned int n = 0;
	//cout << "Enter the value of n for printing the Fibonacci series\n";
	cin >> n;
	vector <unsigned long long> fibVec;
	fibVec.push_back(0);
	fibVec.push_back(1);

	for ( auto i = 2; i<=n ; ++i)
	{
		  fibVec.push_back( (fibVec[i-1] % 10) + (fibVec[i-2] % 10) ) ;
	}
	
	/*for (auto it: fibVec)
	{
		cout << it << " ; ";
	}
	cout << endl;*/

	if ( n <= 1)
	{
		cout << n << endl;
	}
	else
	{
		cout << ( fibVec[n] % 10 ) << endl;
	}
	return 0;
}
