#include<iostream>

using namespace std;

int main()
{

	while (1)
	{
		cout << "\n### Press 1 for adding two numbers ###\n";
		cout << "### Press 2 for subtracting two numbers ###\n";
		int var1, var2, var3;
		int condVar;
		cin >> condVar;

		switch (condVar)
		{
	
			case 1:
				cout << "You selected to add\n";
				cout << "Enter first number \n";
				cin >> var1;
				cout << "You entered: " << var1 << endl;
				cout << "Enter second number \n";
				cin >> var2;
				cout << "You entered: " << var1 << endl;
				var3 = var1 + var2;
				cout << "The sum is : " << var3 << endl;
				break;

			case 2:
				cout << "You selected to subtract\n";
				cout << "Enter first number \n";
				cin >> var1;
				cout << "You entered: " << var1 << endl;
				cout << "Enter second number \n";
				cin >> var2;
				cout << "You entered: " << var1 << endl;
				var3 = var1 - var2;
				cout << "The difference is : " << var3 << endl;
				break;

			default:
				cout << "Invalid input exiting \n";
				exit(0);	

		}	
	}
}
