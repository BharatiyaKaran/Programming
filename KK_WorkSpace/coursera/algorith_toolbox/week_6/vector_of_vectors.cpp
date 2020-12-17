/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : vector_of_vectors.cpp

* Purpose :

* Creation Date : 03-12-2020

* Last Modified : Thu Dec  3 18:15:33 2020

* Created By : Kumar Karan 

* Problem Description : 

_._._._._._._._._._._._._._._._._._._._._.*/

#include<iostream>
#include<vector>

using namespace std;

int main()
{
    srand(time(0));
    unsigned int r=0, c=0;
    cout<<"Enter the values of r and c\n";
    cin>>r>>c;
    printf("You entered r=%d, c=%d\n", r, c);
    // vector of vectors
    vector< vector<unsigned int> > Vec2D;

    for(int i=0; i<r; ++i)
    {
        vector<unsigned int> rowVec;
        for(int j=0; j<c; ++j)
        {
            int val=rand()%10;
            rowVec.push_back(val);
        }

        Vec2D.push_back(rowVec);
    }

    // print the contents of Vec2D
    for(int i=0; i<Vec2D.size(); ++i)
    {
        for(int j=0; j<Vec2D[i].size(); ++j)
        {
            cout<<Vec2D[i][j]<<" ;";
        }
        cout<<endl;
    }
    cout<<endl;

    cout<<"THE END!\n";

}
