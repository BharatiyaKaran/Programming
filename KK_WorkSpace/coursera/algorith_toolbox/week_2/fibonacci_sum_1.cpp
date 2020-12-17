#include<iostream>
#include<vector>

using namespace std;

unsigned int get_unit_digit_sum ( unsigned int n)
{
	if ( n <= 1)
		return n;
	
	vector<unsigned int> fibVec;
	fibVec.push_back(0);
	fibVec.push_back(1);

	auto fibSum = 1;
	for (auto i=2; i<=n; ++i)
	{
		fibVec.push_back( (fibVec[i-1] % 10 ) + (fibVec[i-2] % 10 ) );
		fibSum = fibSum + fibVec[i] ;
	}

	return (fibSum % 10);
}


int main()
{
	unsigned int n = 0, unit_digit_sum = 0;
	cin >> n;
	unit_digit_sum = get_unit_digit_sum(n);
	cout << unit_digit_sum << endl;

}
