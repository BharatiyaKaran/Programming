/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : majority_element.cpp

* Purpose :

* Creation Date : 23-11-2020

* Last Modified : Mon Nov 23 19:12:39 2020

* Created By : Kumar Karan 

* Problem Description : 

_._._._._._._._._._._._._._._._._._._._._.*/

#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdlib>

using namespace std;

unsigned int check_majority(vector<unsigned int> &vec)
{
	auto len = vec.size();
	auto halfMark = 0;
	if ( (len%2) == 0 )
		halfMark = len/2;
	else
		halfMark = len/2 + 1;

	unsigned int res = 0;
	sort(vec.begin(), vec.end());
	for (auto i=0; i<halfMark; ++i)
	{
		//cout << "i= " << i<< " ; vec[i]= " << vec[i] << " ;halfMark = " << (i+len/2) << " ; vec[i+(len/2)] = " << vec[i+(len/2)] <<endl;
		if(vec[i] == vec[i+(len/2)])
		{
			res = 1;
			return res;
		}
	}
	return res;
}

int main()
{
	srand(time(0));
	unsigned int num=0;
	cin>>num;
	vector <unsigned int> aVec;
	for (auto i=0; i<num; ++i)
	{
		unsigned int aVal=0;
		cin>>aVal;
		//aVal = rand();
		aVec.push_back(aVal);
	}

	unsigned int res = -1;
	res = check_majority(aVec);
	cout << res <<endl;
}
