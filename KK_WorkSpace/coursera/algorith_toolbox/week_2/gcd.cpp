#include<iostream>

using namespace std;

unsigned int calc_gcd(unsigned int num1, unsigned int num2)
{
	num1 = num1 % num2;
	if ( num1 == 0)
		return num2;
	else
		calc_gcd(num2,num1);
}



int main()
{
	unsigned int num1=0, num2=0, gcdNum=0;
	cin>>num1>>num2;
	gcdNum = calc_gcd(num1,num2);
	cout << gcdNum << endl;
}
	
