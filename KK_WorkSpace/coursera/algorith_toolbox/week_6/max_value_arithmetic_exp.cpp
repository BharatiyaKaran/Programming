/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : max_value_arithmetic_exp.cpp

* Purpose :

* Creation Date : 18-12-2020

* Last Modified : Fri Dec 18 23:28:33 2020

* Created By : 

* Problem Description :

_._._._._._._._._._._._._._._._._._._._._.*/

#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<limits.h>
#include<stdlib.h>

using namespace std;

long long performOperation(long long val1, long long val2, char op)
{
	long long result=0;

	switch(op)
	{
		case '+':
			result=val1+val2;
			break;

		case '-':
			result=val1-val2;
			break;

		case '*':
			result=val1*val2;
			break;
	}

	return result;
}

long long evalExpression(const vector<long long> &num, const vector<char> &sign)
{
	
	// Make a vector of vectors
	vector<vector<long long>> dpMin, dpMax;

	// update DP matrix with 0s

	for(unsigned long r=0; r<num.size(); ++r)
	{
		vector<long long> rowVec;

		for(unsigned long c=0; c<num.size(); ++c)
		{
			rowVec.push_back(0);	
		}
		dpMin.push_back(rowVec);
		dpMax.push_back(rowVec);
	}

	for(unsigned long i=0; i<num.size(); ++i)
	{
		dpMin[i][i]=num[i];
		dpMax[i][i]=num[i];
	}



	for(unsigned long gap=1; gap<num.size(); ++gap)
	{


		for(unsigned long row=0; row<(num.size() - gap); ++row)
		{
			unsigned long col=row+gap;

			long long min_val=LLONG_MAX, max_val=LLONG_MIN;

			// Fill the DP matrix
			for(unsigned long k=row; k<col; ++k)
			{
				long long a=0, b=0, c=0, d=0;
				a=performOperation(dpMax[row][k], dpMax[k+1][col], sign[k]);
				//printf("a=dpMax[%lu][%lu](%d) %c  dpMax[%lu][%lu](%d)=%d\n", row, k, dpMax[row][k], sign[k], k+1, col, dpMax[k+1][col], a);
				b=performOperation(dpMax[row][k], dpMin[k+1][col], sign[k]);
				//printf("b=dpMax[%lu][%lu](%d) %c  dpMin[%lu][%lu](%d)=%d\n", row, k, dpMax[row][k], sign[k], k+1, col, dpMin[k+1][col], b);
				c=performOperation(dpMin[row][k], dpMax[k+1][col], sign[k]);
				//printf("c=dpMin[%lu][%lu](%d) %c  dpMax[%lu][%lu](%d)=%d\n", row, k, dpMin[row][k], sign[k], k+1, col, dpMax[k+1][col], c);
				d=performOperation(dpMin[row][k], dpMin[k+1][col], sign[k]);
				//printf("d=dpMin[%lu][%lu](%d) %c  dpMin[%lu][%lu](%d)=%d\n", row, k, dpMin[row][k], sign[k], k+1, col, dpMin[k+1][col], d);

				long long tempMin=0, tempMax=0;
				tempMin=min(min(a,b), min(c,d));
				tempMax=max(max(a,b), max(c,d));

				// Update minimum and maximum values;
				if(tempMin<min_val)
				{
					min_val=tempMin;
				}

				if(tempMax>max_val)
				{
					max_val=tempMax;
				}

					dpMin[row][col]=min_val;
					dpMax[row][col]=max_val;

				//printf("\ndpMin[%lu][%lu]=%d k=%lu, Min=%d\n", row, col, dpMin[row][col], k, min_val);
				//printf("dpMax[%lu][%lu]=%d k=%lu, Max=%d\n", row, col, dpMax[row][col], k, max_val);
				//printf("##############################\n");
			}
		}
	}
		
		//Display DPMin and DPMax
		/*printf("Printing dpMIN:\n");
		for(unsigned long row=0; row<num.size(); ++row)
		{
			for(unsigned long col=0; col<num.size(); ++col)
			{
				if(col<row)
				{
					printf("%3d ",0);
				}
				else
				{
					printf("%3d ", dpMin[row][col]);
				}
			}
			printf("\n");
		}
		printf("\n");

		printf("Printing dpMAX:\n");
		for(unsigned long row=0; row<num.size(); ++row)
		{
			for(unsigned long col=0; col<num.size(); ++col)
			{
				if(col<row)
				{
					printf("%3d ",0);
				}
				else
				{
					printf("%3d ", dpMax[row][col]);
				}
			}
			printf("\n");
		}
		printf("\n");
		*/
	
		return dpMax[0][num.size()-1];
}

int main()
{
    // Main code
	//string exp="5-8+7*4-8+9";
	string exp;
	cin>>exp;
	//cout<<exp<<endl;
	vector<long long> num;
	vector<char> sign;

	for(unsigned long i=0; i<exp.size(); ++i)
	{
		if(i%2==0)
		{
			num.push_back(exp[i]-48);
		}
		else
		{
			sign.push_back(exp[i]);
		}
	}

	cout<<evalExpression(num, sign)<<endl;
    return 0;
}
