#include<iostream>
#include<vector>

using namespace std;

bool check_reach(unsigned int stopVal, unsigned int cur_pos, unsigned int mileage)
{
	if ( (stopVal - cur_pos) <= mileage )
		return true;
	else
		return false;
}

int main()
{
	unsigned int dist=0, mileage=0, numOfStops=0;
	cin>>dist>>mileage>>numOfStops;
	vector<unsigned int> stopValVec;
	
	// fill the stop values in a vector
	for (auto i=0; i<numOfStops; ++i)
	{
		unsigned int stopVal=0;
		cin>>stopVal;
		stopValVec.push_back(stopVal);
	}

	stopValVec.push_back(dist);
	
	//  Real logic
	unsigned int cur_pos = 0;
	unsigned int stopCount = 0;
	for (auto i=0; i<stopValVec.size(); ++i)
	{
		if(!check_reach(stopValVec[i], cur_pos, mileage))
		{
			cur_pos = stopValVec[i-1];
			++stopCount;
			if (!check_reach(stopValVec[i], cur_pos, mileage))
			{
				cout << -1 << endl;
				exit(0);
			}
		}
	}

	cout << stopCount << endl;

}
