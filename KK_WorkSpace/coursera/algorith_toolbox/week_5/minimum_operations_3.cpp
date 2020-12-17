/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : minimum_operations_3.cpp

* Purpose :

* Creation Date : 25-11-2020

* Last Modified : Wed Nov 25 13:46:31 2020

* Created By : Kumar Karan 

* Problem Description : 

_._._._._._._._._._._._._._._._._._._._._.*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<unsigned int>  min_op(unsigned int n)
{
    vector<unsigned int> sequence;
    if (n<=1)
        sequence.push_back(0);

    while(n>=1)
    {
        sequence.push_back(n);
        if (n%3 == 0)
        {
            n=n/3;
            continue;
        }

        else if(n%2 == 0)
        {
            n=n/2;
            continue;
        }

        else
        {
            n=n-1;
        }
    }

    return sequence;
}

int main()
{
    unsigned int n=0;
    cin>>n;
    vector<unsigned int> seq = min_op(n);
    cout<<seq.size()-1<<endl;

    for(auto i:seq)
        cout<<i<<" ;";
    cout<<endl;
}

