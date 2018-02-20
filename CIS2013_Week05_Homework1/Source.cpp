#include<iostream>
using namespace std;

// homework is to ask for a month, and a year. then print up a calendar 
// for that month with the correct days of the week ( s m t w t f s )

// find the day of the week that the year started on, then you can run a calculator (function) to find the day each month starts on


void getMonth(int i)
{
	switch (i)
	{
	case 1:
		cout << "January";
		break;
	case 2:
		cout << "February";
		break;
	case 3:
		cout << "March";
		break;
	case 4:
		cout << "April";
		break;
	case 5:
		cout << "May";
		break;
	case 6:
		cout << "June";
		break;
	case 7:
		cout << "July";
		break;
	case 8:
		cout << "August";
		break;
	case 9:
		cout << "September";
		break;
	case 10:
		cout << "October";
		break;
	case 11:
		cout << "November";
		break;
	case 12:
		cout << "December";
		break;
	default:
		cout << "unknown month";
	}
}

void printEmpty()
{
	cout << "   ";
}

void printNumber(int i)
{
	if (i < 10)
	{
		cout << " ";
	}
	cout << i << " ";
}

void printCalendar(int x, int y)
{
// math to find modulus away from sunday, and print that many blank spots so that 1 starts on the right day
	int newLine = y;
		for (int emptyBlock = x; emptyBlock < y; emptyBlock++)
		{
			printEmpty();
		}

		for (int numberBlock = 1; numberBlock < 29; numberBlock++)
		{
			printNumber(numberBlock);
			newLine++;
			if (newLine == 7)
			{
				newLine = 0;
				cout << endl;
			}
			
		}		
}




int main()
{
	int chosenMonth = 0;
	bool validChosenMonth = false;
	int chosenYear = 0;
	bool validChosenYear = false;

	int printYear = 0;

	int endProgram = 'y';
	

	cout << "Choose a month by typing its corresponding number (for example, 11 for November)" << endl;

	while (validChosenMonth == false)
	{
		cin >> chosenMonth;
		if (chosenMonth > 12 || chosenMonth < 1)
		{
			cout << "Sorry, I didn't get that. Choose a number between 1 and 12." << endl;
		}
		else
		{
			validChosenMonth = true;
		}
	}
	cout << "Choose a year (for example, 1863)" << endl;
	while (validChosenYear == false)
	{
		cin >> chosenYear;
		if (chosenYear < 1)
		{
			cout << "Sorry, I didn't get that. Choose a year greater than 0." << endl;
		}
		else
		{
			validChosenYear = true;
		}
	}


	cout << endl << "  ";
	getMonth(chosenMonth);
	cout << "    " << chosenYear << endl;
	cout << "Su Mo Tu We Th Fr Sa" << endl;
	printCalendar(0, 3);

	cout << endl << "End of program";
	cin >> endProgram;

	return 0;
}
