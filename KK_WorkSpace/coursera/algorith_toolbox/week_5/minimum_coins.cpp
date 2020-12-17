/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : minimum_coins.cpp

* Purpose :

* Creation Date : 23-11-2020

* Last Modified : Mon Nov 23 22:26:49 2020

* Created By : Kumar Karan 

* Problem Description : 
Input Format. Integer money.
Output Format. The minimum number of coins with denominations 1, 3, 4 that changes money.
Constraints. 1 <= money <= 10^3 .

_._._._._._._._._._._._._._._._._._._._._.*/

#include<iostream>

using namespace std;

int main()
{
    unsigned int coin[] = {1, 3, 4};
    unsigned int numOfCoins = sizeof(coin)/sizeof(coin[0]);

    unsigned int money=0;
    cin>>money;

    unsigned int memoArr[3][money+1];
    memoArr[0][0]=0;

    for (auto r=0; r<numOfCoins; ++r)
    {
        for(auto c=0; c<=money; ++c)
        {
            if(r>0)
            {
                if(coin[r] > c)
                {
                        memoArr[r][c]=memoArr[r-1][c];
                }
                else
                {
                        auto min = memoArr[r-1][c] < (1 + memoArr[r][c-coin[r]]) ?  memoArr[r-1][c] : (1 + memoArr[r][c - coin[r]]) ;
                        memoArr[r][c] = min;
                }
            }
            else
            {
                memoArr[r][c]=c;
            }
        }
    }

    /*for (auto r=0; r<numOfCoins; ++r)
    {
        for (auto c=0; c<=money; ++c)
            cout << memoArr[r][c] << " ; ";
        cout << endl;
    }
    cout <<endl;
    */

    cout << memoArr[2][money]<< endl;


}
