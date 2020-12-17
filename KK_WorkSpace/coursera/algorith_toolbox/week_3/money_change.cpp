#include<iostream>

using namespace std;

int main()
{
	long long inVal = 0;
	cin >> inVal;

	long long n = 0;
	n = n + inVal/10;
	inVal = inVal % 10;
	n = n + inVal/5;
	inVal = inVal % 5;
	n = n + inVal;

	cout << n << endl;
	return 0;
}


