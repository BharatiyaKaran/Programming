#include<iostream>
#include<vector>

using namespace std;

int binary_search(unsigned int val, const vector<unsigned int> &vec, int start, int end)
{
	if (start > end)
		return -1;
	unsigned int m = (start + end)/2;
	int pos=-1;
	if (vec[m] ==  val)
	{
		return m;
	}
	else
	{
		if(val > vec[m])
		{
			pos = binary_search(val, vec, m+1, end);
		}
		else
		{
			pos = binary_search(val, vec, start, m-1);
		}
	}
	return pos;
}
void print_index(const vector<unsigned int> &vec1, const vector<unsigned int> &vec2)
{
	for (auto i = 0; i<vec2.size(); ++i)
	{
		int pos=0;
		pos = binary_search(vec2[i], vec1, 0, vec1.size() - 1);
		cout << pos << " ";
	}
	cout << endl;
}

int main()
{
	unsigned int num=0;
	cin>>num;
	vector <unsigned int> aVec;
	for (auto i=0; i<num; ++i)
	{
		unsigned int aVal=0;
		cin>>aVal;
		aVec.push_back(aVal);
	}

	unsigned int k=0;
	cin>>k;
	vector <unsigned int> bVec;
	for (auto i=0; i<k; ++i)
	{
		unsigned int bVal=0;
		cin>> bVal;
		bVec.push_back(bVal);
	}

	print_index(aVec, bVec);
}
