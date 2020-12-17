/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : max_gold.cpp

* Purpose :

* Creation Date : 02-12-2020

* Last Modified : Thu Dec  3 18:56:21 2020

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
    //printf("In fun calc_max_gold: Vector Size=%d, Capacity=%d\n", vec.size(), cap);
    // create a vector of vectors
    vector< vector<unsigned int> > dpVec;

    // fill the DP Array
    for (auto r=0; r<=vec.size(); ++r)
    {
        vector<unsigned int> rowVec;

        for(auto c=0; c<=cap; ++c)
        {
            if(r==0)
            {
                rowVec.push_back(0);
            }
            else
            {
                if(c==0)
                {
                    rowVec.push_back(0);
                }
                else
                {
                    if(c < vec[r-1])
                    {
                        rowVec.push_back(dpVec[r-1][c]);
                    }
                    else
                    {
                        auto maxVal = dpVec[r-1][c] > (vec[r-1] + dpVec[r-1][c-vec[r-1]]) ? dpVec[r-1][c] : (vec[r-1] + dpVec[r-1][c-vec[r-1]]);
                        rowVec.push_back(maxVal);
                    }
                }
            }

        }
        //printf("Inserting rowVec of size=%d into the DP Vector of vectors of size=%d\n", rowVec.size(), dpVec.size());
        dpVec.push_back(rowVec);

    }

    // print the DP array
    /*cout<<"DP Array:\n";
    for(unsigned int r=0; r<=vec.size(); ++r)
    {
        for(unsigned int c=0; c<=cap; ++c)
        {
            cout<<dpVec[r][c]<<" ;";
        }
        cout<<endl;
    }
    cout<<endl;
    */

    return dpVec[vec.size()][cap];
}

int main()
{
    srand(time(0));
    unsigned int cap=0, n=0;
    cin>>cap>>n;
    vector<unsigned int> wtVec;
    //cap = rand() % 10001;
    //n = rand() % 301;

    // insert the value of weights into a vector
    for(unsigned int i=0; i<n; ++i)
    {
        unsigned int wt=0;
        cin>>wt;
        //wt = rand() % 100001;
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
   //cout << "Max_Gold =";
   cout << max_gold<<endl;

}

