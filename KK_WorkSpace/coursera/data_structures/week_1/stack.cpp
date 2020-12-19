/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : stack.cpp

* Purpose :

* Creation Date : 19-12-2020

* Last Modified : Sat Dec 19 17:07:09 2020

* Created By : Kumar Karan

* Problem Description :

_._._._._._._._._._._._._._._._._._._._._.*/

#include<iostream>
#include<vector>

using namespace std;

class kStack
{
	private:
		vector<int> data;

	public:

		void push(int val);
		void pop(void);
		int top(void);
		bool empty(void);
		int size();
};

void kStack::push(int val)
{
	data.push_back(val);
}

void kStack::pop(void)
{
	data.pop_back();
}

int kStack::top(void)
{
	return data[data.size()-1];
}

bool kStack::empty(void)
{
	return data.size()==0? true:false;
}

int kStack::size(void)
{
	return data.size();
}


int main()
{
    // Main code
	kStack test;

	if(test.empty())
		cout<<"Stack empty\n";
	
	test.push(5);
	cout<<"Size: "<<test.size()<<endl;
	cout<<test.top()<<endl;

	test.pop();
	cout<<"Size: "<<test.size()<<endl;

    return 0;
}
