#include<iostream>
#include<map>
#include<map>
#include<algorithm>
#include<cstdlib>

using namespace std;

int main()
{
	unsigned int num = 0, capacity = 0;
        cin >> num >> capacity;
	//srand(time(0));
	//num = rand()%100;
	//capacity = rand()%100;
	//cout << "num = " << num << " cap = " << capacity << endl;
	map <double, double > valByWtValMap;

	for (auto i=0; i<num; ++i)
	{
		double val = 0, wt = 0;
		cin >> val >> wt;
		//val = rand()%100;
		//wt = rand()%100;
		if (wt != 0)
			valByWtValMap.insert( pair <double, double> ( val/wt, wt ) );
	}

	/*for (auto it: valByWtValMap)
		cout << it.first << " ->  "  << it.second << " \n ";
	cout << endl;*/

	// Real buisness logic
	double max_loot = 0;
	for (auto i = valByWtValMap.rbegin(); i != valByWtValMap.rend(); ++i)
	{
		//cout << "i->first " << i->first << " i->sec " << i->second <<endl;
		//cout << "Loot : " << max_loot << " Cap : " << capacity <<endl<<endl;
		auto rem = capacity - i->second ;
		if (rem<=0)
		{
			max_loot = max_loot + (i->first * capacity);
			break;
		}
		else
		{
			max_loot = max_loot + (i->second * i->first);
			capacity = capacity - i->second ;
		}
		
	}
	cout.precision(10);
	cout << max_loot << endl;

}
