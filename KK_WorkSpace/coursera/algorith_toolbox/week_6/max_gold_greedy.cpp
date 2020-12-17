/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : max_gold.cpp

* Purpose :

* Creation Date : 02-12-2020

* Last Modified : Wed Dec  2 15:33:44 2020

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

using namespace std;

unsigned int calc_max_gold(const vector<unsigned int> & vec, unsigned int cap)
{
    unsigned int max_gold=0;
    for(auto i=0; i<vec.size(); ++i)
    {
        if( (cap/vec[i]) >= 1)
        {
            max_gold = max_gold + vec[i];
            cap = cap - vec[i];
        }
    }

    return max_gold;
}

int main()
{
    unsigned int cap=0, n=0;
    cin>>cap>>n;
    vector<unsigned int> wtVec;

    // insert the value of weights into a vector
    for(auto i=0; i<n; ++i)
    {
        unsigned int wt=0;
        cin>>wt;
        wtVec.push_back(wt);
    }

    sort(wtVec.begin(), wtVec.end(), greater<unsigned int>());
    /*for(auto i:wtVec)
    {
        cout<< i << " ;";
    }
    cout<<endl;*/

   auto max_gold= calc_max_gold(wtVec, cap);
   cout << max_gold<<endl;
}

