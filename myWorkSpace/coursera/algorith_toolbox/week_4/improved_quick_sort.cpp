#include<iostream>
#include<vector>
#include<cstdlib>

using namespace std;

void partition(vector<unsigned int> &vec, int start, int end, int &pIndex1, int &pIndex2)
{
	auto pivot = vec[end];
	pIndex1 = start;
	for (auto i=start; i<end; ++i)
	{
		if( vec[i] <= pivot )
		{
			swap(vec[i], vec[pIndex1]);
			++pIndex1;
		}


	}
	swap (vec[pIndex1], vec[end]);

	pIndex2 = start;
	for (auto i=start; i<pIndex1; ++i)
	{
		if(vec[i] < pivot)
		{
			swap(vec[i], vec[pIndex2]);
			++pIndex2;
		}
	}
	swap(vec[pIndex2], vec[pIndex1]);
}

void quickSort(vector<unsigned int> &vec, int start, int end)
{


	if (start < end)
	{
		auto pIndex1=0, pIndex2=0;
		partition(vec, start, end, pIndex1, pIndex2);
		quickSort(vec, start, pIndex2 - 1);
		quickSort(vec, pIndex1 + 1, end);
	}
}

int main()
{
	srand(time(0));
	unsigned int aVal=0;
	unsigned int num =0;
	cin>> num;

	vector<unsigned int> aVec;
	for(auto i=0; i<num; ++i)
	{
		//aVal = rand() % 100;
		cin>>aVal;
		aVec.push_back(aVal);
	}

	auto len = aVec.size();
	quickSort(aVec, 0, len - 1);

	for (auto i: aVec)
		cout << i << " ";
	cout << endl;
}

