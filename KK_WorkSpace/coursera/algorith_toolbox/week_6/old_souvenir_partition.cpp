/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : souvenir_partition.cpp

* Purpose :

* Creation Date : 12-12-2020

* Last Modified : Wed Dec 16 14:57:56 2020

* Created By :

* Problem Description :

_._._._._._._._._._._._._._._._._._._._._.*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<unistd.h>

using namespace std;

bool canDivide(vector<unsigned int>& vecIn)
{
	unsigned int sum=0;
	//printf("VecIn size =%ld\n", vecIn.size());
	for(auto i: vecIn)
	{
		//cout<<i<<" ";
		sum=sum+i;
	}
	//cout<<endl;

	if(sum%3 != 0)
		return false;
	
	auto share=sum/3;
	cout<<"Share="<<share<<endl;
	
	// create DP Matrix
	vector< vector<bool> > dp;

	for(auto r=0; r<=vecIn.size(); ++r)
	{
		vector<bool> rowVec;
		for(auto c=0; c<=share; ++c)
		{
			if(r==0)
			{
				if(c==0)
					rowVec.push_back(true);
				else
					rowVec.push_back(false);
			}
			else
			{
				if (c==0)
					rowVec.push_back(true);
				else
				{
					if (c<vecIn[r-1])
					{
						rowVec.push_back(dp[r-1][c]);
					}
					else if (c==vecIn[r-1])
					{
						rowVec.push_back(true);
					}
					else
					{
						// including + excluding
						////printf("r=%d, c=%d, including : dp[%d][%d] = %d , excluding: dp[%d][%d] =%d\n", r, c, r-1, r-c, dp[r-1][c-r]? 0:1, r-1, c, dp[r-1][c]? 0:1 );
						bool val = dp[r-1][c - vecIn[r-1]] + dp[r-1][c];
						rowVec.push_back(val);
					}
				}
			}
		}
		dp.push_back(rowVec);
	}

	printf("Column:-> ");
	for(int i=0; i<=share; ++i)
		cout<<i<<" ";
	cout<<endl;
	

	for(auto r=0; r<dp.size(); ++r )
	{
		bool pFlag=true;
		for(auto c=0; c<=share; ++c)
		{
			if(pFlag)
			{
				if (r==0)
				{
					printf("Row: 0 -> ");
					pFlag=false;
				}
				else
				{
					printf("Row: %d -> ", vecIn[r-1]);
					pFlag=false;
				}
				
				
			}

			cout<<dp[r][c]<<" ";
		}
		cout<<endl;
	}

	// Backtrack for the solution set.
	// Create a vector for keeping track of values used from input vector
	vector<int> notUsedVec(vecIn.size(), 1);

	vector< vector<int> > solVec;
	for(auto i=(dp.size() - 1); i>0; --i)
	{
		int rem = share;
		int row = i;
		
		vector<int> subVec;

		while(rem!=0 && dp[row][rem] && notUsedVec[row-1])
		{
			printf("rem/col = %d, Row -> %d , pushing in vecIn[%d] = %d \n", rem, vecIn[row-1], row-1, vecIn[row-1]);
			subVec.push_back(vecIn[row-1]);
			// Mark the pushed value as used
			printf("Marking  %d as used\n", vecIn[row-1]);
			notUsedVec[row-1] = 0;
			rem = rem - vecIn[row-1];

			if(rem<0)
			{
				return false;
			}
				

			if(rem!=0)
			{
				auto it = find(vecIn.begin(), vecIn.end(), rem);
				if (it!=vecIn.end())
				{
					int pos = it - vecIn.begin();
					if(notUsedVec[pos])
					{
						//notUsedVec[pos]=0;
						row = pos + 1;
						printf("Found but NOT used:  rem/col = %d, Row -> %d, pos = %d \n", rem, vecIn[row-1], pos);
					}
					else
					{
						do
						{
							row = row - 1;
						}
						while((!notUsedVec[row-1] || vecIn[row-1]>rem) && row>1);
						printf("Found and already USED : rem/col = %d, Row -> %d, pos = %d \n", rem, vecIn[row-1], pos);
					}
				}
				else
				{
					printf("REM NOT found, rem=%d, row=%d\n", rem, vecIn[row-1]);
					do
					{
						row = row - 1;
					}
					while((!notUsedVec[row-1] || vecIn[row-1]>rem) && row>1);

					printf("#ELSE 2 END : rem/col = %d, Row -> %d\n", rem, vecIn[row-1]);
				}
			}
		}
		printf("\n");
		if (subVec.size()!=0 && rem==0)
			solVec.push_back(subVec);

	}

	cout << "Solution vector size = " << solVec.size() << endl;
	for(int r=0; r<solVec.size(); ++r)
	{
		for (int c=0; c<solVec[r].size(); ++c)
		{
			cout<<solVec[r][c]<<" ";
		}
		cout<<endl;
	}
	

	for(auto i: notUsedVec )
	{
		if (i)
			return false;
	}

	return solVec.size() == 3 ? true : false;
}

int main()
{
	//while (1)
	//{
    // Main code
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
	//}
    return 0;
}
