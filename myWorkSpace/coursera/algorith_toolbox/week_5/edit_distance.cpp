/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : edit_distance.cpp

* Purpose :

* Creation Date : 28-11-2020

* Last Modified : Sat Nov 28 17:16:12 2020

* Created By : Kumar Karan 

* Problem Description : 

_._._._._._._._._._._._._._._._._._._._._.*/

#include<iostream>

using namespace std;



int main()
{
    string str1, str2;
    cin>>str1;
    cin>>str2;


    // memoisation array
    unsigned int dp[str2.length() + 1][str1.length() + 1];
    
    for (auto r=0; r<=str2.length(); ++r)
    {
        for(auto c=0; c<=str1.length(); ++c)
        {
            if(r==0)
                dp[r][c]=c;

            else
            {
                if(c==0)
                {
                    dp[r][c]=r;
                } 
    
                else 
                {
                    if(str2[r-1]==str1[c-1])
                    {
                        dp[r][c]=dp[r-1][c-1];
                    }
                    else
                    {
                        auto min=0;
                        if(dp[r-1][c]<=dp[r-1][c-1] && dp[r-1][c]<=dp[r][c-1])
                           min=dp[r-1][c];
                        else if(dp[r-1][c-1]<=dp[r-1][c] && dp[r-1][c-1]<=dp[r][c-1])
                            min=dp[r-1][c-1];
                        else
                            min=dp[r][c-1];

                        dp[r][c]=min + 1;
                    }

                }

            }
        }
    }

    // display the memoisation matrix
    /*for(auto r=0; r<=str2.length(); ++r)
    {
        for(auto c=0; c<=str1.length(); ++c)
        {
            cout<<dp[r][c]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    */
    cout<<dp[str2.length()][str1.length()] <<endl;
}
