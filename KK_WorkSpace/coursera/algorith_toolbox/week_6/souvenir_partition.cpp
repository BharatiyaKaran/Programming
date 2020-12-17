/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : souvenir_partition.cpp

* Purpose :

* Creation Date : 12-12-2020

* Last Modified : Thu Dec 17 19:57:44 2020

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
	unsigned long sum=0;
	////printf("VecIn size =%ld\n", vecIn.size());
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

	for(unsigned long j: vecIn)
	{
		if(j>share)
			return false;
	}
	
	// create DP Matrix
	vector< vector<bool> > dp;

	for(unsigned long r=0; r<=vecIn.size(); ++r)
	{
		vector<bool> rowVec;
		for(unsigned long c=0; c<=share; ++c)
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
						//////printf("r=%d, c=%d, including : dp[%d][%d] = %d , excluding: dp[%d][%d] =%d\n", r, c, r-1, r-c, dp[r-1][c-r]? 0:1, r-1, c, dp[r-1][c]? 0:1 );
						bool val = dp[r-1][c - vecIn[r-1]] + dp[r-1][c];
						rowVec.push_back(val);
					}
				}
			}
		}
		dp.push_back(rowVec);
	}

	//printf("Column: -> ");
	/*for(unsigned long i=0; i<=share; ++i)
		cout<<i<<" ";
	cout<<endl;
	*/

	for(unsigned long r=0; r<dp.size(); ++r )
	{
		bool pFlag=true;
		for(unsigned long c=0; c<=share; ++c)
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
					//printf("Row:%d-%d -> ",r, vecIn[r-1]);
					pFlag=false;
				}
				
				
			}

			//cout<<dp[r][c]<<" ";
		}
		//cout<<endl;
	}

	// Backtrack for the solution set.
	// Create a vector for keeping track of values used from input vector
	vector<bool> markUsed(vecIn.size(), false);

	vector< vector<int> > solVec;
	for(auto i=(dp.size() - 1); i>0; --i)
	{
		unsigned long rem = share;
		unsigned long row = i;
		
		// vector to save the values of the subsets
		vector<int> subVec;


		bool doOnce=true;

		// vector to save the position of the visited values
		vector<int> visited;

		unsigned long tryCount=0;

		while(rem>0 && dp[row][rem] && !markUsed[row-1])
		{
			if(doOnce)
			{
				//printf("\n### While loop start for %d at position %d###\n", vecIn[row-1], row-1);
				doOnce=false;
			}
				rem = rem - vecIn[row-1];
				//printf("Mark %d at position %d as used and add '%d' to solution vector\n", vecIn[row-1], row-1, vecIn[row-1]);
				//printf("Remainder=%d\n", rem);
				markUsed[row-1]=true;
				subVec.push_back(vecIn[row-1]);
				visited.push_back(row-1);

			//	while(dp[row-1][rem]!=0 && rem!=0 && !markUsed[row-2])
				while(dp[row-1][rem]!=0 && rem!=0)
				{
					row=row-1;
					//printf("Row=%d, Value of Row=%d\n", row-1, vecIn[row-1]);
				}

				
				if(rem!=0)
				{
					row=row+tryCount;
					//printf("Added try count=%d, new row=%d\n", tryCount, row);
				}

				if(row==i)
					break;

				while(markUsed[row-1] && rem!=0 && row<(dp.size()-1))
				{
					//printf("%d Already Used so increment row->Row=%d, Value of Row=%d\n",vecIn[row-1], row-1, vecIn[row-1]);
					row++;
				}
	

				if(vecIn[row-1]>rem && rem!=0)
				{
					// Solution not found in first try, increment try count
					tryCount++;

					//printf("vecIn value:%d Greater than what remains: %d\n", vecIn[row-1], rem);
					for( auto v: visited )
					{
						//printf("Marking Visted value: %d at position: %d back to Not used\n", vecIn[v], v);
						markUsed[v]=false;
					}
					//reset the while loop criteria
					row=i;
					rem=share;
					markUsed[row-1]=false;
					subVec.clear();
					visited.clear();
					//printf("###Reset the while loop remainder to %d, row to %d and clear the solution vector\n\n", rem, row);
					continue;
				}
		}
		if (subVec.size()!=0 && rem==0)
			solVec.push_back(subVec);
	}

		/*cout << "Solution vector size = " << solVec.size() << endl;
		for(unsigned long r=0; r<solVec.size(); ++r)
		{
			for (unsigned long c=0; c<solVec[r].size(); ++c)
			{
				cout<<solVec[r][c]<<" ";
			}
			cout<<endl;
		}	
	*/

		for(unsigned long i=0; i< markUsed.size(); ++i )
		{
			if (!markUsed[i])
			{
				//printf("Not used %d\n", vecIn[i]);
				return false;
			}
			else
			{
				//printf("Used: %d\n",vecIn[i]);
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
	//num = rand()%21;

	vector<unsigned long> vecIn;
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
