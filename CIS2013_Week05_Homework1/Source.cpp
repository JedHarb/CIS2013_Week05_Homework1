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

void printCalendar(int x, int y) //x = month. y = year.
{
/* Gregorian Calendar rules:
- Day of the year advances by 1 day of the week each year (Jan 1 2017 is Sunday, Jan 1 2018 is Monday).
- Advances by 2 on Feb 29th (leap years).
- Leap year is every 4 years, but not at the turn of the century when the century isn't divisible by 4.
(1600, 2000, 2400, etc. are leap years. 1700, 1800, 1900, 2100, etc. are not leap years)
- This means every 400 years, the same last 2 digits of the year, same day of the month will be the same day of the week.
(Jan 1 of 1617, 2017, and 2417 are all Sundays.)
- The Gregorian Calendar was introduced in 1582, so we will set Jan 1 1582 (Wed) as the first choosable day and Dec 31 9999 as the last.

Calculation:
- Start at the start date with the number of advances at 3 (for Wednesday).
- Given a month and year, subtract the given year from 1582 to get the total years difference (one advance for each year).
- Also count each leap year between the two (add an additional advance for each).
- Also add additional advances depending on the month chosen
(Jan 0, Feb 3, Mar 3, Apr 6, May 1, Jun 4, Jul 6, Aug 2, Sep 5, Oct 0, Nov 3, Dec 5).
- If the chosen year is a leap year, and the chosen month is after February, add 1 advance.
- Take the total number of advances modulus 7.
- Apply this to the calendar month starting on Sunday as 0 advances, and each advance adds a blank space.
*/
	int advances = 3;
	int difference = y - 1582;
	int leapYears = 0;
	int monthAdvances = 0;
	int newLine = 0;

	for (int leapCheck = 1582; leapCheck <= y; leapCheck++) //check each year for a leap year between the start and the selected year
	{
		if (leapCheck % 4 == 0)
		{
			if (leapCheck % 100 == 0)
			{
				//cout << leapCheck << " divisible by 100" << endl;
				if (leapCheck % 400 == 0)
				{
					//cout << leapCheck << " divisible by 400" << endl;
					leapYears++;
				}
			}
			else
			{
				//cout << leapCheck << " divisible by 4" << endl;
				leapYears++;
			}
		}

		if (y % 4 == 0) // if the selected year is a leap year, subtract 1 from the advance count
		{
			if (y % 100 == 0)
			{
				if (y % 400 == 0)
				{
					leapYears--;
				}
			}
			else
			{
				leapYears--;
			}
		}

		if (x > 2) // if the selected year is a leap year and it the selected month is after Feb, add 1 back to the advance count
		{
			if (y % 4 == 0)
			{
				if (y % 100 == 0)
				{
					if (y % 400 == 0)
					{
						leapYears++;
					}
				}
				else
				{
					leapYears++;
				}
			}
		}
	}

	switch (x)
	{
	case 1:
		monthAdvances = 0;
		break;
	case 2:
		monthAdvances = 3;
		break;
	case 3:
		monthAdvances = 3;
		break;
	case 4:
		monthAdvances = 6;
		break;
	case 5:
		monthAdvances = 1;
		break;
	case 6:
		monthAdvances = 4;
		break;
	case 7:
		monthAdvances = 6;
		break;
	case 8:
		monthAdvances = 2;
		break;
	case 9:
		monthAdvances = 5;
		break;
	case 10:
		monthAdvances = 0;
		break;
	case 11:
		monthAdvances = 3;
		break;
	case 12:
		monthAdvances = 5;
		break;
	default:
		cout << "you should not see this message";
	}

	advances += difference;
	advances += leapYears;
	advances += monthAdvances;
	advances = advances % 7;

	for (int emptyBlock = 0; emptyBlock < advances; emptyBlock++)
	{
		printEmpty();
		newLine++;
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
	switch (x)
	{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			for (int numberBlock = 29; numberBlock < 32; numberBlock++)
			{
				printNumber(numberBlock);
				newLine++;
				if (newLine == 7)
				{
					newLine = 0;
					cout << endl;
				}
			}
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			for (int numberBlock = 29; numberBlock < 31; numberBlock++)
			{
				printNumber(numberBlock);
				newLine++;
				if (newLine == 7)
				{
					newLine = 0;
					cout << endl;
				}
			}
			break;
		default:
			;
	}
	if (x == 2)
	{

		if (y % 4 == 0)
		{
			if (y % 100 == 0)
			{
				if (y % 400 == 0)
				{
					printNumber(29);
				}
			}
			else
			{
				printNumber(29);
			}
		}
	}
}

int main()
{
	char play_again = 'y';
	while (play_again == 'y')
	{
		int chosenMonth = 0;
		bool validChosenMonth = false;
		int chosenYear = 0;
		bool validChosenYear = false;

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
		cout << "Choose a year between 1582 and 9999 (for example, 1863)" << endl;
		while (validChosenYear == false)
		{
			cin >> chosenYear;
			if (chosenYear < 1582 || chosenYear > 9999)
			{
				cout << "Sorry, I didn't get that. Choose a year between 1582 and 9999." << endl;
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
		printCalendar(chosenMonth, chosenYear);

		// ask to restart

		cout << endl << "Play again? (Type y for yes.) ";
		cin >> play_again;
		cout << endl;
	}

	return 0;
}
