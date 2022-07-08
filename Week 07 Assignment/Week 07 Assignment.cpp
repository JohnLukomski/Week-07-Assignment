//***************************************
//	Week 07 Assignment
// 
//	Author: John Lukomski
//	Date: 07/08/22
//***************************************

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

//declare constant variables
const int NUM_OF_COLUMNS = 5,
NUM_OF_ROWS = 10,
NAME_SPACING = 15,
SCORE_SPACING = 10,
NAME_TITLE_SPACING = NAME_SPACING - (NUM_OF_COLUMNS / 2), 
SCORE_TITLE_SPACING = SCORE_SPACING * NUM_OF_COLUMNS;

//structure that holds each bowler's name, scores, and average scores
struct bowlerType
{
	string bowlerName;
	int bowlerScores[NUM_OF_COLUMNS];
	int avgScore;
};

//prototypes of the functions
bool GetBowlingData(bowlerType bData[], ifstream& inData);
int GetAverageScore(bowlerType bData[], int currRow);
void PrettyPrintResults(bowlerType bData[]);

int main()
{
	//declare structure variable
	bowlerType bowlerData[NUM_OF_ROWS];

	//declare variables
	ifstream inFile;
	bool successful;

	//open input file
	inFile.open("BowlingScores.txt");

	//call GetBowlingData and assign the returning bool value to the variable successful
	successful = GetBowlingData(bowlerData, inFile);
	//test if the input is valid
	if (successful == true)
	{
		//assign every value returned by GetAverageScore to its appropriate avgScore variable in bowlerData
		for (int i = 0; i < NUM_OF_ROWS; i++)
		{
			bowlerData[i].avgScore = GetAverageScore(bowlerData, i);
		}
		//call the function PrettyPrintResults
		PrettyPrintResults(bowlerData);
	}
	//if the input isn't valid, terminate the program
	else
	{
		cout << "Input Failure" << endl;
		system("pause");
		return 1;
	}
	//close the open input file
	inFile.close();

	system("pause");
	return 0;
}

//function to input the name and scores from the input file to the appropriate variables and arrays in the structure bData
bool GetBowlingData(bowlerType bData[], ifstream& inData)
{
	for (int i = 0; i < NUM_OF_ROWS; i++)
	{
		//input the bowlers' names into bowlerName in bData
		inData >> bData[i].bowlerName;
		for (int j = 0; j < NUM_OF_COLUMNS; j++)
		{
			//input the bowlers' scores into bowlerScores in bData
			inData >> bData[i].bowlerScores[j];
		}
	}
	//test if the data inputed correctly
	if (inData)
		return true;
	else
		return false;

}

//function to calculate the average of the bowlers' scores and input them
int GetAverageScore(bowlerType bData[], int currRow)
{
	//declare local variables
	double sumScores = 0.0;
	int avgScores = 0;

	{
		for (int j = 0; j < NUM_OF_COLUMNS; j++)
		{
			//add each score to the total sum of each individual bowler
			sumScores += bData[currRow].bowlerScores[j];
		}
		//round the average score up or down (adding 0.5 will result in the appropriate integer truncating)
		avgScores = (sumScores / NUM_OF_COLUMNS) + 0.5;

		return avgScores;
	}

}

//function to output the data in the array of structures to the screen in an organized format
void PrettyPrintResults(bowlerType bData[])
{
	//display the catagories with the correct spacing
	cout << left << setw(NAME_TITLE_SPACING) << "Name:" << setw(SCORE_TITLE_SPACING) << "Scores:" << "Average:" << endl;

	//display the name, scores, and score average spaced under their appropriate catagory
	for (int i = 0; i < NUM_OF_ROWS; i++)
	{
		cout << left << setw(NAME_SPACING) << bData[i].bowlerName;
		for (int j = 0; j < NUM_OF_COLUMNS; j++)
		{
			cout << setw(SCORE_SPACING) << bData[i].bowlerScores[j];
		}
		cout << bData[i].avgScore << endl;
	}
}




/*Code I Didn't Use:

//This is leftover code from week 06. None of it is leftover code from week 07.

//		FIRST_POS = 0,

//		cout << bNames[i] << endl;

//		cout << bScores[i][j]<< "      ";

//		cout << endl;

//		cout << "Row number " << currRow << " column number " << j << " and sum =  " << sumScores << " " << endl;

//		cout << "average =  "<< sumScores / NUM_OF_COLUMNS<<endl;

*/

