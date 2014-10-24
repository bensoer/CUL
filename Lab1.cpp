#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

void loadTopBottomBar();
void loadSpaceRow();
void loadMessage();
void loadRowStartEndDecals();
void printMessage(string message);
void loadRowTask();

const int Columns = 91; //number of columns in the string images
const int BorderWidth = 2; //number of columns taken by the border
const int Rows = 12; //number of rows in the string image
const int SpaceRow[] = { 1, 6, 10 }; //rows that are used as paragraph breaks
const int TopRow = 0;
const int BottomRow = 11;
const int AtRatio = 3;
const string At = "@";
const string Bar = "|";
int row;

const string line1 = "  Eomer. Take Eored down the left flank. Gamling, follow the King's banner down";
const string line2 = "  the center. Grimbold, take your company right, after you pass the wall. Forth, and";
const string line3 = "  fear no darkness! Arise! Arise, Riders of Theoden! Spears shall be shaken, shields";
const string line4 = "  shall be splintered! A sword day ... a red day ... ere the sun rises!";
const string line5 = "  Ride now! ... Ride now! ... Ride! Ride to ruin and the world's ending!";
const string line6 = "  -King Theoden and his army join the battle for Mina Tirith in the";
const string line7 = "  Lord of the Rings - Return of the King";

int main(void){

	//cycle through increasing the rows and determining the loading the task for that row
	for (row = 0; row < Rows; row++){
		loadRowTask();
		cout << endl;
	}
	cin.get();

	return 0;
}
//decides what is being printed on the row based on row number
void loadRowTask(){
	
	if (row == TopRow || row == BottomRow){
		loadTopBottomBar();
	}else if (row == SpaceRow[0] || row == SpaceRow[1] || row == SpaceRow[2]){
		loadSpaceRow();
	}
	else{
		loadMessage();
	}
}
//load top and bottom bar
void loadTopBottomBar(){
	const int AtSegments = 29;
	const string BarPattern = "==@";
	
	loadRowStartEndDecals();
	
	for (int i = 0; i < AtSegments; i++){
		cout << BarPattern;
	}
	//does extra on the end as ending is dealt with by loadRowStartEndDecal()
	cout << "==";
	loadRowStartEndDecals();
}
//determine and print appropriate decal for sides edge of string image
void loadRowStartEndDecals(){
	if (row == BottomRow){
		cout << At;
	}
	else if (row % AtRatio == 0){
		cout << At;
	}else{
		cout << Bar;
	}

	return;
}
//creates the rows that are used as paragraph break lines in the string image and between the top and bottom border
void loadSpaceRow(){
	loadRowStartEndDecals();
	cout << setw(Columns-BorderWidth) << left << "";
	loadRowStartEndDecals();
}
//based on row select the appropriate message to print
void loadMessage(){
	
	switch (row){
		case 2: 
			printMessage(line1);
			break;
		case 3: 
			printMessage(line2);
			break;
		case 4: 
			printMessage(line3);
			break;
		case 5: 
			printMessage(line4);
			break;
		case 7:
			printMessage(line5);
			break;
		case 8: 
			printMessage(line6);
			break;
		case 9: 
			printMessage(line7);
			break;
	}
}
void printMessage(string message){
	loadRowStartEndDecals();
	cout << setw(Columns - BorderWidth) << left << message;
	loadRowStartEndDecals();
}