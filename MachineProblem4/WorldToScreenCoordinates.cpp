
#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <string>

using namespace std;

/** Global Variables to store data*/
string arrayHolder[165];
int counter;


class WorldCoordinates {
public:
	string dash = "-";
	string straightLine = "|";
	int xCoordinate = 5;
	int yCoordinate = 5;
	int endpointHorizontal;
	int endpointVertical;

	WorldCoordinates(int xCoordinate, int yCoordinate) {
		this->xCoordinate = xCoordinate;
		this->yCoordinate = yCoordinate;
	}

};

void fileReader() {

	ifstream inFile;
	inFile.open("PIXA.txt");

	//check for error: 
	if (inFile.fail()) {
		cerr << "ERROR OPENING FILE." << endl;
		exit(1);
	}
	string line;
	counter = 0;

	//Read from a file until you've reached the end and store values in an array:
	while (!inFile.eof()) {
		inFile >> line;
		arrayHolder[counter] = line; //Store each value inside the array variable.
		counter++; //increment the counter variable to store length of array.
	}
	cout << "Number of total coordinates found: " << counter << endl;


}
//Generic method to convert String to Integers
int stringToIntConverter(string word) {
	int num;
	num = stoi(word);
	
	return num;

}
//function to output the values that are stored inside the array:
void outputArray(string arrayHolderr[]) {
	for (int i = 0; i < counter; i++) {
		if (i % 3 == 0) {
			cout << endl;
		}
		string currentNum = arrayHolder[i];
		int currentIntNum = stringToIntConverter(currentNum);
		cout << "values are: " << currentIntNum << " \t";
	}
	cout << endl;

	cout << "*************************************************************" << endl;


}

//This is the algorithm that converts the xCoordinate to Screen Coordinate using the array we have
int worldtoScreenCoordConversion(int xValue) {
	//The data will be displayed on a 320 by 200px screen.
	//get the xValue by doubling the xCoordinate. Then multiply the xValue with (320-1) \ 2000
	//draw a line for that 
	int coordinateX = 1000;
	int coordinateY = 1000;
	coordinateX = coordinateX * 2;
	int displayDataX = 320;
	int displayDataY = 200;
	int newXValue = 0;
	newXValue = xValue * (displayDataX - 1) / coordinateX;

	cout << endl;
	cout << "THE CONVERSION  for: " << xValue << " IS: " << newXValue << endl;

	return xValue;
}

//This function takes every third array value and calls the Coordinating function to that variable:
void initializeXVal(string arrayHolderr[]) {
	for (int i = 0; i < counter; i += 3) {
		string currentNum = arrayHolder[i];
		int currentIntNum = stringToIntConverter(currentNum);

		worldtoScreenCoordConversion(currentIntNum);
	}
}
WorldCoordinates coordinates(20, 10);

void printSquare() {

	//Print the first dash line on the top
	for (int i = 0; i < coordinates.xCoordinate; i++) {
		cout << coordinates.dash;
		coordinates.endpointHorizontal = i; //set the value for the horizontal total count
	}
	cout << endl;
	//print the 2 vertical lines separated by specific numbered spaces:
	for (int i = 0; i < coordinates.yCoordinate; i++) {
		std::cout << coordinates.straightLine + " " + std::string(coordinates.endpointHorizontal - 1, ' ') + coordinates.straightLine << std::endl;

		coordinates.endpointVertical = i;
	}
	//Print the last line
	for (int i = 0; i <= coordinates.endpointHorizontal; i++) {
		cout << coordinates.dash;
		//endpointHorizontal = i;
	}

	cout << endl;
}

//Function to perform world to screen coordinations:
void performRightMoveActions() {
	cout << "Moving the Object Left:" << endl;
	
	cout << "\t";
	for (int i = 0; i < coordinates.xCoordinate; i++) {
		cout  <<coordinates.dash;
		coordinates.endpointHorizontal = i; //set the value for the horizontal total count
	}
	cout << endl;
	//print the 2 vertical lines separated by specific numbered spaces:
	for (int i = 0; i < coordinates.yCoordinate; i++) {
		std::cout << " \t" + coordinates.straightLine  + std::string(coordinates.endpointHorizontal - 1, ' ') +"\t" +coordinates.straightLine  << std::endl;

		coordinates.endpointVertical = i;
	}
	cout << "\t";
	//Print the last line
	for (int i = 0; i <= coordinates.endpointHorizontal; i++) {
		cout  << coordinates.dash;
		//endpointHorizontal = i;
	}

	cout << endl;

}

void moveObjectDown() {
	cout << endl;
	cout << endl;
	cout << endl << endl << endl << endl;
	printSquare();
}

void moveObjectInOrOut(int xCoord, int yCoord) {
	
	//Print the first dash line on the top
	for (int i = 0; i < xCoord; i++) {
		cout << coordinates.dash;
		coordinates.endpointHorizontal = i; //set the value for the horizontal total count
	}
	cout << endl;
	//print the 2 vertical lines separated by specific numbered spaces:
	for (int i = 0; i < yCoord; i++) {
		std::cout << coordinates.straightLine + " " + std::string(coordinates.endpointHorizontal - 1, ' ') + coordinates.straightLine << std::endl;

		coordinates.endpointVertical = i;
	}
	//Print the last line
	for (int i = 0; i <= coordinates.endpointHorizontal; i++) {
		cout << coordinates.dash;
		//endpointHorizontal = i;
	}

	cout << endl;
}
void conversions() {
	cout << "ALTERING FILE DATA:" << endl;
	fileReader(); //function to read data from File and store it in an array:
	outputArray(arrayHolder); //Function to output data from array to the console/ window:
	initializeXVal(arrayHolder); //This function will call the conversion function for every xCoordinate
}



int main() {
	
	int option;
	
	while (true) {

		cout << "Enter 2 to move the Object left" << endl;
		cout << endl;

		cout << "Enter 3 to move the Object Right" << endl;
		cout << endl;


		cout << "Enter 4 to move the Object up" << endl;
		cout << endl;

		cout << "Enter 5 to move the Object DOWN" << endl;
		cout << endl;

		cout << "Enter 6 to Move the Object In" << endl;
		cout << endl;

		cout << "Enter 7 to Move the Object out" << endl;
		cout << endl;

		cout << " Enter 1 to Reset to the beginning state" << endl;
		cout << endl;

		cout << "Enter 8 to Read the PIX data from file and store it in Array. As well as output data from array to the console window, and apply conversion to xCoordinate" << endl;
		cout << endl;

		cout << "Press 0 to Exit the Program" << endl;
		cout << endl;
		cin >> option;

		if (option == 1) {
			printSquare();
			cout << endl;
		}
		if (option == 2) {
			printSquare();
			cout << endl;
		}
		if (option == 3) {
			performRightMoveActions();
			cout << endl;
		}
		if (option == 4) {
			printSquare();
			cout << endl;
		}
		if (option == 5) {
			moveObjectDown();
			cout << endl;
		}
		if (option == 6) {
			moveObjectInOrOut(5, 10);
			cout << endl;
		}
		if (option == 7) {
			moveObjectInOrOut(20, 5);
			cout << endl;
		}
		if (option == 8) {
			conversions();
			cout << endl;
		}

		if (option == 0) {
			break;
		}

	}
		
	//system("pause");
	return 0;
}