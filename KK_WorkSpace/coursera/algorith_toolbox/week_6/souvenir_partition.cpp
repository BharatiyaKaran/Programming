/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : souvenir_partition.cpp

* Purpose :

* Creation Date : 12-12-2020

* Last Modified : Fri Dec 18 14:14:55 2020

* Created By :

* Problem Description :

_._._._._._._._._._._._._._._._._._._._._.*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<unistd.h>

using namespace std;

bool canDivide(vector<unsigned long>& vecIn)
{
	unsigned int sum=0;
	//printf("VecIn size =%ld\n", vecIn.size());
	for(auto i: vecIn)
	{
		//cout<<i<<" ";
		sum=sum+i;
	}
	//cout<<endl;

	if((sum%3!=0) || vecIn.size()<3)
		return false;
	
	auto share=sum/3;
	//cout<<"Share="<<share<<endl;

	for(unsigned int j: vecIn)
	{
		if(j>share)
			return false;
	}
	
	// create DP Matrix
	vector< vector<bool> > dp;

	for(unsigned int r=0; r<=vecIn.size(); ++r)
	{
		vector<bool> rowVec;
		for(unsigned int c=0; c<=share; ++c)
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
						//printf("r=%u, c=%u, including : dp[%u][%u] = %u , excluding: dp[%u][%u] =%u\n", r, c, r-1, r-c, dp[r-1][c-r]? 0:1, r-1, c, dp[r-1][c]? 0:1 );
						bool val = dp[r-1][c - vecIn[r-1]] + dp[r-1][c];
						rowVec.push_back(val);
					}
				}
			}
		}
		dp.push_back(rowVec);
	}


	//printf("Column: -> ");
	/*for(unsigned int i=0; i<=share; ++i)
		cout<<i<<" ";
	cout<<endl;
	*/

	// print the DP Array
	for(unsigned int r=0; r<dp.size(); ++r )
	{
		bool pFlag=true;
		for(unsigned int c=share; c<=share; ++c)
		{
			if(pFlag)
			{
				if (r==0)
				{
					//printf("Row:0-0 -> ");
					pFlag=false;
				}
				else
				{
					//printf("Row:%u-%u -> ",r, vecIn[r-1]);
					pFlag=false;
				}
			}

			//cout<<dp[r][c]<<" ";
			//if(dp[r][c])
				//printf("Row: %u Value:%u DP[%u][%u]=%d\n", r, vecIn[r-1], r, c, dp[r][c]?1:0);
		}
		//cout<<endl;
	}


	// Backtrack for the solution set.
	// Create a vector for keeping track of values used from input vector
	vector<bool> markUsed(vecIn.size(), false);

	vector< vector<int> > solVec;
	for(auto i=(dp.size() - 1); i>0; --i)
	{
		unsigned int rem = share;
		unsigned int row = i;
		
		// vector to save the values of the subsets
		vector<int> subVec;


		bool doOnce=true;

		// vector to save the position of the visited values
		vector<int> visited;

		unsigned int tryCount=0;
		bool usedTryCountOnce=false;

		while(rem>0 && dp[row][rem] && !markUsed[row-1])
		{
			if(doOnce)
			{
				//printf("\n### While loop start for %u at position %u###\n", vecIn[row-1], row-1);
				doOnce=false;
			}
				rem = rem - vecIn[row-1];
				//printf("Mark %u at position %u as used and add '%u' to solution vector\n", vecIn[row-1], row-1, vecIn[row-1]);
				//printf("Remainder=%u\n", rem);
				markUsed[row-1]=true;
				subVec.push_back(vecIn[row-1]);
				visited.push_back(row-1);

			//	while(dp[row-1][rem]!=0 && rem!=0 && !markUsed[row-2])
				while(dp[row-1][rem]!=0 && rem!=0)
				{
					row=row-1;
					//printf("Row=%u, Value of Row=%u\n", row-1, vecIn[row-1]);
				}

				
				if(rem!=0 && !usedTryCountOnce)
				{
					row=row+tryCount;
					usedTryCountOnce=true;
					//printf("Added try count=%u, new row=%u\n", tryCount, row);
				}

				if(row==i)
					break;

				while(markUsed[row-1] && rem!=0 && row<(dp.size()-1))
				{
					//printf("%u Already Used so increment row->Row=%u, Value of Row=%u\n",vecIn[row-1], row-1, vecIn[row-1]);
					row++;
				}
	

				if(vecIn[row-1]>rem && rem!=0)
				{
					// Solution not found in first try, increment try count
					tryCount++;
					usedTryCountOnce=false;

					//printf("vecIn value:%u Greater than what remains: %u\n", vecIn[row-1], rem);
					for( auto v: visited )
					{
						//printf("Marking Visted value: %u at position: %d back to Not used\n", vecIn[v], v);
						markUsed[v]=false;
					}
					//reset the while loop criteria
					row=i;
					rem=share;
					markUsed[row-1]=false;
					subVec.clear();
					visited.clear();
					//printf("###Reset the while loop remainder to %u, row to %u and clear the solution vector\n\n", rem, row);
					continue;
				}
		}
		if (subVec.size()!=0 && rem==0)
			solVec.push_back(subVec);
	}

		/*cout << "Solution vector size = " << solVec.size() << endl;
		for(unsigned int r=0; r<solVec.size(); ++r)
		{
			for (unsigned int c=0; c<solVec[r].size(); ++c)
			{
				cout<<solVec[r][c]<<" ";
			}
			cout<<endl;
		}	
	
*/
		for(unsigned int i=0; i< markUsed.size(); ++i )
		{
			if (!markUsed[i])
			{
				//printf("Not used %u\n", vecIn[i]);
				return false;
			}
			else
			{
				//printf("Used: %u\n",vecIn[i]);
			}
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
	//num = (rand()%20)+1;

	vector<unsigned long> vecIn;
	for(auto i=0; i<num; ++i)
	{
		auto val=0;
		cin>>val;
		//val = (rand()%30)+1;
		vecIn.push_back(val);
	}

	//printf("Number of Input entries=%u\n", vecIn.size());
	// Display input entries
/*	for(auto i: vecIn)
		cout<<i<<" ";
	cout<<endl;
*/
	sort(vecIn.begin(), vecIn.end());
	printf("%d\n", canDivide(vecIn)? 1:0);
	//cout<<"###########\n\n";
	//sleep(1);
	//}
    return 0;
}
