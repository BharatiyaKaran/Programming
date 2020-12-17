/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : minimum_operations_1.cpp

* Purpose :

* Creation Date : 24-11-2020

* Last Modified : Wed Nov 25 15:34:14 2020

* Created By : Kumar Karan 

* Problem Description : 

_._._._._._._._._._._._._._._._._._._._._.*/

#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>

using namespace std;

int main()
{
    unsigned int num=0;
    cin>>num;

    vector<unsigned int> sequence;
    
    // dp array
    unsigned int dp[num+1];
    dp[0]=0;
    dp[1]=0;

    for(auto i=2; i<=num; ++i)
    {
        unsigned int min=INT_MAX;
        if( (i%3)==0 )
        {
            min=dp[i/3] + 1;
        }
        if( (i%2)==0 )
        {
            dp[i]=dp[i/2] + 1;
            if(dp[i]<min)
                min=dp[i];
        }
        dp[i]=dp[i-1] + 1;
        if(dp[i]<min)
            min=dp[i];

        dp[i]=min;
    }

    /*for(auto i=0; i<=num; ++i)
        cout << i << " ;" ;
    cout<<endl;
    
    for(auto i:dp)
        cout << i<<" ;";
    cout<<endl;
    */


    cout<<dp[num]<<endl;

    //print the optimal sequence
    if(num<=1)
        sequence.push_back(0);
    else
    {
        auto i=num;
        while(i>1)
        {
            if(dp[i-1]<dp[i])
            {
                sequence.push_back(i);
                --i;
            }
            else
            {
                sequence.push_back(i);
                if(i%3==0)
                {   
                    i=i/3;
                    continue;
                }
                else if(i%2==0)
                {
                    i=i/2;
                    continue;
                }
                else
                {
                    auto curr=dp[i];
                    while(dp[i]>=curr)
                    {
                        --i;
                    }
                }
            }
        }
        sequence.push_back(1);
    }
    
    reverse(sequence.begin(), sequence.end());
    for(auto i:sequence)
        cout<<i<<" ";
    cout<<endl;

}

