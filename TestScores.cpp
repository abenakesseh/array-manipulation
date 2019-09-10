#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

const int NUM_TESTS = 8;

//*****************************************************************************************************

void readTestScores(ifstream& f, int scores[][NUM_TESTS]);

//*****************************************************************************************************

void displayTestScores(const int scores[][NUM_TESTS]);

//*****************************************************************************************************

int totalOneTest(const int scores[][NUM_TESTS], int testNumber);

//*****************************************************************************************************

int totalOneStudent(const int scores[][NUM_TESTS], int studentNumber);

//*****************************************************************************************************

float averageOneTest(int scores[][NUM_TESTS], int testNumber);

//*****************************************************************************************************

float averageOneStudent(int scores[][NUM_TESTS], int studentNumber);

//*****************************************************************************************************

int highestOneStudent(const int scores[][NUM_TESTS], int studentNumber);

//*****************************************************************************************************

int topStudent(const int scores[][NUM_TESTS]);

//*****************************************************************************************************

int main()
{
	int testScores[10][8];
	int testNumber,
		studentNumber;
	int total = 0;
	ifstream tests("Assignment1Data.txt");

	readTestScores(tests, testScores);

	displayTestScores(testScores);
	cout << "Press Enter to continue";
	cin.get();

	totalOneTest(testScores, testNumber);
	cout << "Enter test number" << endl;
	cin >> testNumber;

	cout << "Total for Test # " << testNumber << " is: " << total << endl;
	cout << "Press Enter to continue";
	cin.get();

	totalOneStudent(testScores, studentNumber);
	cout << "Total for Student # " << studentNumber << " is: " << total << endl;
	cout << "Press Enter to continue";
	cin.get();

}

//*****************************************************************************************************

void readTestScores(ifstream& f, int scores[][NUM_TESTS])
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			f >> scores[i][j];
		}
	}
}

//*****************************************************************************************************

void displayTestScores(const int scores[][NUM_TESTS])
{
	cout << "All Test Scores: " << endl;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cout << setw(4) << scores[i][j] << " ";
		}
		cout << endl;
	}
}

//*****************************************************************************************************

int totalOneTest(const int scores[][NUM_TESTS], int testNumber)
{
	int total = 0;
	for (int i = 0; i < 10; i++)
	{
		total += scores[i][testNumber];
	}
	
	return total;
}

//*****************************************************************************************************

int totalOneStudent(const int scores[][NUM_TESTS], int studentNumber)
{
	int total = 0;
	for (int i = 0; i < 8; i++)
	{
		total += scores[studentNumber][i];
	}

	return total;
}

//*****************************************************************************************************

float averageOneTest(const int scores[][NUM_TESTS], int testNumber)
{
	double average;
	int total = 0;

	for (int i = 0; i < 8; i++)
	{
		total += (scores[i][testNumber]);
	}

	average = total / 8.0;
	cout << "Average for Test #" << testNumber << "is: " << average << endl;

	cout << "Press Enter to continue";
	cin.get();

	return average;
}

//*****************************************************************************************************

float averageOneStudent(const int scores[][NUM_TESTS], int studentNumber)
{
	double average;
	int total = 0;

	for (int i = 0; i < 10; i++)
	{
		total += (scores[i][studentNumber]);
	}

	average = total / 10.0;
	cout << "Average for Student #" << studentNumber << "is: " << average << endl;

	cout << "Press Enter to continue";
	cin.get();

	return average;
}

//*****************************************************************************************************

int highestOneStudent(const int scores[][NUM_TESTS], int studentNumber)
{
	int highest = 0;
	studentNumber--;

	for (int i = 0; i < 8; i++)
	{
		if (scores[studentNumber][i] > highest)
		{
			highest = scores[studentNumber][i];
		}

	}

	return highest;
}

//*****************************************************************************************************

int topStudent(const int scores[][NUM_TESTS])
{
	int top=0,
		position,
		temporaryAverage;
	int averageArr[10];

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			temporaryAverage += scores[i][j];
		}

		averageArr[i] = temporaryAverage / 8;
		temporaryAverage = 0;
	}

	for (int i = 0; i < 10; i++)
	{
		if (averageArr[i] > top)
		{
			top = averageArr[i];
			position = i;
		}
	}

	return position + 1;
}