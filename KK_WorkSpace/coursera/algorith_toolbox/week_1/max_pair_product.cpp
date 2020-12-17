#include <iostream> 
#include <vector>
#include <algorithm>

using namespace std;

long long max_pair_product(vector<long long> & prodVec)
{
	sort(prodVec.begin(), prodVec.end());
	long long maxPairProd = 0;
	maxPairProd = prodVec[prodVec.size() -1 ] * prodVec[prodVec.size() - 2];
	return maxPairProd;
}

int main()
{
	auto numOfElems = 0;
	cin >> numOfElems;
	vector <long long> prodVec;
	for (auto i=0; i<numOfElems; ++i)
	{
		long long inElem = 0;
		cin >> inElem;
		prodVec.push_back(inElem);
	}
	long long maxPairProd = max_pair_product(prodVec);
	cout << maxPairProd << endl;
	return 0;
}
