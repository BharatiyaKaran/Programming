#include<iostream>

using namespace std;

long long calc_gcd(long long num1, long long num2)
{
	num1 = num1 % num2;
	if ( num1 == 0)
		return num2;
	else
		calc_gcd(num2,num1);
}



int main()
{
	long long num1=0, num2=0, gcdNum=0, lcmNum=0 ;
	cin>>num1>>num2;
	gcdNum = calc_gcd(num1,num2);
	lcmNum = ( num1 * num2) / gcdNum ;
	cout << lcmNum << endl;
}
	
