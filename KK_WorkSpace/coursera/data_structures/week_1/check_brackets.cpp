/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : check_brackets.cpp

* Purpose :

* Creation Date : 19-12-2020

* Last Modified : Sat Dec 19 20:35:25 2020

* Created By : 

* Problem Description :

_._._._._._._._._._._._._._._._._._._._._.*/

#include<iostream>
#include<stack>

using namespace std;

class bracketData
{
	private:
		char type;
		unsigned int position;

	public:
		void setType(char val) {type=val;}
		void setPos(unsigned int pos) { position=pos; }

		char getType(void) { return this->type; }
		unsigned int getPos(void) { return this->position; }

};

bool isBalanced(const string &input, unsigned int &pos)
{
	stack<bracketData> brackets;
	bool bracketPresent=false;
	for(auto i: input)
	{
		++pos;

		if (i=='(' || i=='{' || i=='[' ||
				i==')' || i=='}' || i==']'
		   )
		{
			bracketPresent=true;
			if(i=='(' || i=='{' || i=='[')
			{
				bracketData bdObj;
				bdObj.setType(i);
				bdObj.setPos(pos);
				brackets.push(bdObj);
			}
			else
			{
				if(brackets.empty())
					return false;

				if( (brackets.top().getType()=='(' && i!=')') ||
						(brackets.top().getType()=='{' && i!='}') ||
						(brackets.top().getType()=='[' && i!=']')
			  	)
				{
					return false;
				}
				else
				{
					brackets.pop();
				}
			}
		}
	}


/*	while(!brackets.empty())
	{
		char temp=brackets.top();
		cout<<brackets.top()<<" ";
		brackets.pop();
		//brackets.push(temp);
	}
	cout<<endl;
*/
	if(!brackets.empty())
	{
		pos = brackets.top().getPos();
	}

	if(bracketPresent)
	{
		return brackets.empty();
	}
	else
	{
		return false;
	}
}

int main()
{
    // Main code
	//string input="{[]}()";
	string input;
	cin>>input;
	//cout<<"Input: "<<input<<endl;
	unsigned int pos=0;
	if(isBalanced(input, pos))
	{
		cout<<"Success\n";
	}
	else
	{
		cout<<pos<<endl;
	}
    return 0;
}
