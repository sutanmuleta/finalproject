
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "FinalHeaders.h"


void Calc1();
void Calc2();
void writeFile();
void readFile();
void mainLoop();
void menu();



int main(){
	
	system("cls");
	printf("Kyler Wimbush\nBenjamin 'Signy' Levitt\nSutan Tadese\n");
	mainLoop();
	return 0;
	
}

void mainLoop(){
	while (1) {
		menu();
	}
}

void menu() {

	char selection; //declares selection variable
	

		printf("\nEnter 1 for Calculation 1\nEnter 2 for Calculation 2\nEnter 3 to write to a file\nEnter 4 to read a file\nEnter 5 to exit the program\n\n"); //creates menu with choices
		scanf_s(" %c", &selection, 1);
		selection = toupper(selection);
		
		while(selection != '1' && selection != '2' && selection != '3' && selection != '4' && selection != '5'){
			printf("Invalid Input, Please select a number from the menu: ");
			scanf_s(" %c", &selection, 1);
			selection = toupper(selection);
		}

	
		switch (selection) { //allows user to input the selection based off the menu choices
			case '1': 
			Calc1();
				break;
				
				case '2':
				Calc2();
					break;
				
				case '3':
					writeFile();
					break;
					
				case '4':
				readFile();
					break;
							
				
				case '5':
					printf("\nExiting the program\n\n"); //exits the progam
					return 0;
					
				default:
					printf("Choose again: \n\n"); //asks user to choose again if anything other than a menu option is chosen
					break;
		}
		
}
			





