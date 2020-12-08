/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : max_gold.cpp

* Purpose :

* Creation Date : 02-12-2020

* Last Modified : Thu Dec  3 16:59:42 2020

* Created By : Kumar Karan 

* Problem Description : 
Task. Given n gold bars, find the maximum weight of gold that fits into a bag of capacity W.
Input Format. The first line of the input contains the capacity W of a knapsack and the number n of bars
of gold. The next line contains n integers w0, w1, w2, ... w(n-1) defining the weights of the bars of gold. 
Constraints. 1<=W<=10^4; 1<=n<=300; 0<=w0,w1,w2,...w(n-1)<=10^5.
Output Format. Output the maximum weight of gold that fits into a knapsack of capacity W.
_._._._._._._._._._._._._._._._._._._._._.*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<unistd.h>

using namespace std;

unsigned int calc_max_gold(const vector<unsigned int> & vec, unsigned int cap)
{
    printf("In fun calc_max_gold: Vector Size=%d, Capacity=%lld\n", vec.size(), cap);
    unsigned int dpArr[vec.size() + 1][cap + 1];
    
    // fill the DP Array
    for (auto r=0; r<=vec.size(); ++r)
    {
        for(auto c=0; c<=cap; ++c)
        {
            if(r==0)
            {
                dpArr[r][c]=0;
            }
            else
            {
                if(c==0)
                {
                    dpArr[r][c]=0;
                }
                else
                {
                    if(c < vec[r-1])
                    {
                        dpArr[r][c]= dpArr[r-1][c];
                    }
                    else
                    {
                        dpArr[r][c]= dpArr[r-1][c] > (vec[r-1] + dpArr[r-1][c-vec[r-1]]) ? dpArr[r-1][c] : (vec[r-1] + dpArr[r-1][c-vec[r-1]]);
                    }
                }
            }
        }
    }

    // print the DP array
    /*cout<<"DP Array:\n";
    for(unsigned int r=0; r<=vec.size(); ++r)
    {
        for(unsigned int c=0; c<=cap; ++c)
        {
            cout<<dpArr[r][c]<<" ;";
        }
        cout<<endl;
    }
    cout<<endl;
    */

    return dpArr[vec.size()][cap];
}

int main()
{
    while (1)
    {

    srand(time(0));
    unsigned int cap=0, n=0;
    //cin>>cap>>n;
    vector<unsigned int> wtVec;
    cap = rand() % 10001;
    n = rand() % 300;

    // insert the value of weights into a vector
    for(unsigned int i=0; i<n; ++i)
    {
        unsigned int wt=0;
        //cin>>wt;
        wt = rand() % 100001;
        wtVec.push_back(wt);
    }

    //sort(wtVec.begin(), wtVec.end(), greater<unsigned int>());
    sort(wtVec.begin(), wtVec.end());
    /*cout<< "Weights:\n";
    for(unsigned int i:wtVec)
    {
        cout<< i << " ;";
    }
    cout<<endl<<endl;
    */

   unsigned int max_gold= calc_max_gold(wtVec, cap);
   cout << "Max_Gold =";
   cout << max_gold<<endl<<endl;

   sleep(1);
    }
}

