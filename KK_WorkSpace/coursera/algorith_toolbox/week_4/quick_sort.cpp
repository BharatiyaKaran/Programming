#include<iostream>
#include<vector>
#include<cstdlib>

using namespace std;

int partition(vector<unsigned int> &vec, int start, int end)
{
	cout << "Start = "<< start << " ; End = " << end <<endl;
	auto pivot = vec[end];
	cout << "Pivot = " << pivot <<endl;
	auto pIndex = start;
	for (auto i=start; i<end; ++i)
	{
		if( vec[i] <= pivot )
		{
			swap(vec[i], vec[pIndex]);
			++pIndex;
		}
	}
	swap (vec[pIndex], vec[end]);
	cout << "Partition Index = " << pIndex <<endl;
	return pIndex;
}

void quickSort(vector<unsigned int> &vec, int start, int end)
{
	for (auto i:vec)
		cout << i << " ;";
	cout << endl;

	if (start < end)
	{
		auto pInd = partition(vec, start, end);
		quickSort(vec, start, pInd - 1);
		quickSort(vec, pInd + 1, end);
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
		aVal = rand() % 100;
		aVec.push_back(aVal);
	}

	auto len = aVec.size();
	quickSort(aVec, 0, len - 1);

	for (auto i: aVec)
		cout << i << " ; ";
	cout << endl;
}

