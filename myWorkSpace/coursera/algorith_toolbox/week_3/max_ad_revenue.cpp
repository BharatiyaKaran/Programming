#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>

using namespace std;

int main()
{
	int num=0;
	cin >> num;
	
	srand(time(0));

	vector<int> profit_per_click;
	vector<int> avg_num_clicks;

	for (auto i=0; i<num; ++i)
	{
		int ppcVal=0;
		//cin>>ppcVal;
		ppcVal = (rand()%1000);
		profit_per_click.push_back(ppcVal);
	}

	for (auto i=0; i<num; ++i)
	{
		int ancVal=0;
		//cin>>ancVal;
		ancVal = ( (rand()%100000) - 50000);
		avg_num_clicks.push_back(ancVal);
	}

	sort(profit_per_click.begin(), profit_per_click.end());
	sort(avg_num_clicks.begin(), avg_num_clicks.end());

	long long max_revenue = 0;
	for (auto i=0; i<num; ++i)
	{
		cout << "ppc val = " << profit_per_click[i] << " ; anc val = " << avg_num_clicks[i] <<endl;
		max_revenue = max_revenue + (profit_per_click[i]*avg_num_clicks[i]);
	}
	cout << max_revenue << endl;
}

