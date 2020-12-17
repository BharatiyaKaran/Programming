/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : souvenir_partition.cpp

* Purpose :

* Creation Date : 16-12-2020

* Last Modified : Wed Dec 16 18:11:41 2020

* Created By : Kumar Karan

* Problem Description :

_._._._._._._._._._._._._._._._._._._._._.*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<unistd.h>

using namespace std;

bool canDivide(vector<unsigned int> & vecIn)
{
	unsigned int sum=0;
	for (int i=0; i<vecIn.size(); ++i)
	{
		sum=sum+vec[i];
	}

	if(sum%3!=0)
		return false;

	unsigned int share=sum/3;
	printf("Share=%d\n", share);

	unsigned int numOfValidSet=0;

	vector<bool> markUsedVec(vecIn.size(), false);

	for(int i=0; i<vecIn.size(); ++i)
	{
		unsigned int rem=share;
		rem=rem - vec[i];
		markUsedVec[i]=true;

		if (rem>0)
		{
			for(int j=0; j<vecIn.size(); ++j)
			{
				if(i==j)
					continue;
			}
		}
		else
		{
			if(rem==0)
			{
				numOfValidSet++;
			}
			else
			{
				printf("Value %d is greater than share:%d\n", vec[i], share);
				return false;
			}
		}
	}

	for(auto i: markUsedVec)
	{
		if(!i)
			return false;
	}

	if(numOfValidSet==3)
		return true;

}
			

int main()
{
    // Main code
	//while (1)
    //{
    srand(time(0));
    auto num=0;
    cin>>num;
    //num = rand()%21;

    vector<unsigned int> vecIn;
    for(auto i=0; i<num; ++i)
    {
        auto val=0;
        cin>>val;
        //val = rand()%11;
        vecIn.push_back(val);
    }

    /*for(auto i: vecIn)
        cout<<i<<" ";
    cout<<endl;
    */


    sort(vecIn.begin(), vecIn.end());
    printf("%d\n", canDivide(vecIn)? 1:0);
    //cout<<"###########\n";
    //sleep(1);


    return 0;
}
