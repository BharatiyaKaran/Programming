/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : minimum_operations_2.cpp

* Purpose :

* Creation Date : 24-11-2020

* Last Modified : Tue Nov 24 18:30:50 2020

* Created By : Kumar Karan 

* Problem Description : 

_._._._._._._._._._._._._._._._._._._._._.*/

#include<iostream>

using namespace std;

int main()
{
    unsigned int num=0;
    cin>>num;

    unsigned int val[3]={1, 2, 3};
    unsigned int dp[3][num+1];
    
    unsigned int length = sizeof(val)/sizeof(val[0]);

    dp[0][0]=0;
    dp[1][0]=0;
    dp[2][0]=0;
    dp[0][1]=0;
    dp[1][1]=0;
    dp[2][1]=0;

    for (auto r=0; r<length; ++r)
    {
        for(auto c=2; c<=num; ++c)
        {
            if(r==0)
                dp[r][c]=c;
            else
            {
               if( (c%val[r]) == 0)
               {
                   dp[r][c] = dp[r-1][c] < (dp[r][c/val[r]] + 1) ? dp[r-1][c]: (dp[r][c/val[r]] + 1);
               }
               else
               {
                   dp[r][c] = dp[r-1][c] < (dp[r][c-1] + 1) ? dp[r-1][c] : (dp[r][c-1] + 1);
               }
            }
        }
    }
    
    for (auto r=0; r<3; ++r)
    {
        cout << "### R=" <<r <<endl;
        for (auto c=0; c<=num; ++c)
            cout<< dp[r][c]<<" ;";
        cout<<endl;
    }

    cout<< dp[2][num]<<endl;
}
    
