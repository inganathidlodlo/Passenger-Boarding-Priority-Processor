#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
using namespace std;

enum BoardingGroup {
	BUSINESS = 1,
	PRIORITY,
	STANDARD,
	ASSISTED,
};

BoardingGroup readingBoardingGroup() {
	int code;
	while (true)
	{
		cout << "Group (1= Business, 2 = Priority, 3 = Standard, 4 = Assisted): ";
		if (cin >> code && code >= 1 && code <= 4)
			return static_cast<BoardingGroup>(code);

		cout << "Invalid input. Please enter a number between 1 to 4." << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
}
string groupToString(BoardingGroup group)
{
	switch (group)
	{
	case BUSINESS: return "BUSINESS";
	case PRIORITY: return "PRIORITY";
	case STANDARD: return "STANDARD";
	case ASSISTED: return "ASSISTED";
	}
	return "UNKNOWN";
}

double loungeCredit(BoardingGroup group)
{
	switch (group)
	{
	case BUSINESS: return 250.0;
	case PRIORITY: return 120.0;
	default: return 0.0; //STANDARD and ASSISTED
	}
}
int main()
{
	const int NUM_PASSENGERS = 6;

	BoardingGroup group;
	string name;
	int businessCount = 0, priorityCount = 0, standardCount = 0, assistedCount = 0, businessPriorityCount = 0;
	double totalCredit = 0.0;

	cout << fixed << setprecision(2);

	for (int i = 1; i <= NUM_PASSENGERS; ++i)
	{
		cout << "\nPassenger " << i << " name: ";
		getline(cin, name);

		group = readingBoardingGroup();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		if (group <= PRIORITY)
			businessPriorityCount++;

		switch (group)

		{
		case BUSINESS: businessCount++; break;
		case PRIORITY: priorityCount++; break;
		case STANDARD: standardCount++; break;
		case ASSISTED: assistedCount++; break;
		}

		double credit = loungeCredit(group);
		totalCredit += credit;

		cout << left << setw(22) << name << setw(12) << groupToString(group) << "Credit: R" << credit << endl;
	}

	cout << "\n==========BOARDING SUMMARY==========" << endl;
	cout << left << setw(20) << "Business" << ": " << businessCount << endl;
	cout << left << setw(20) << "Priority" << ": " << priorityCount << endl;
	cout << left << setw(20) << "Standard" << ": " << standardCount << endl;
	cout << left << setw(20) << "Assisted" << ": " << assistedCount << endl;
	cout << left << setw(20) << "Business/Priority" << ": " << businessPriorityCount << endl;
	cout << left << setw(20) << "Total Lounge Credit" << ": R" << totalCredit << endl;

	cout << "\nNote: An enum gives each boarding category a readable name "
		<< "(BUSINESS, PRIORITY) instead of unexplained codes like 1 or 2. "
		<< "This makes the code self-documenting, reduces mistakes from "
		<< "mistyped numbers, and lets the compiler help check values. "
		<< "Because enumerators are ordered, comparisons such as "
		<< "group <= PRIORITY remain simple and meaningful." << endl;

	return 0;
}