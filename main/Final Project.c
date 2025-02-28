#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void Calc1();
void Calc2();
void fileWrite();
void readFile();

int main(){
	srand(time(NULL));
	time_t current_time;
	char* c_time_string;
	/*obtaincurrent time. */
	current_time = time(NULL);
	c_time_string = ctime(&current_time);
	printf("Current time is %s", c_time_string);
		char title[] = "SDC255 Final Project"; //title of the program
	puts(title); //displays the title
	
	char selection; //declares selection variable
	while (1) {
		printf("\nEnter 1 for Calculation 1\nEnter 2 for Calculation 2\nEnter 3 to write to a file\nEnter 4 to read a file\nEnter 5 to exit the program\n\n"); //creates menu with choices
		scanf_s(" %c", &selection, 1);
		selection = toupper(selection);
		
		while(selection != '1' && selection != '2' && selection != '3' && selection != '4' && selection != '5'){
			printf("Invalid Input, Please select a number from the menu: ");
			scanf_s(" %c", &selection, 1);
			selection = toupper(selection);
		}
		
		int numChoices = 0; //tracks number of choices selected
		
		switch (selection) { //allows user to input the selection based off the menu choices
			case '1': 
			Calc1();
			numChoices++; //increment number of choices
				break;
				
				case '2':
				Calc2();
				numChoices++; //increment number of choices
					break;
				
				case '3':
					fileWrite();
					numChoices++; //increment number of choices
					break;
					
				case '4':
				readFile();
				numChoices++; //increment number of choices
					break;
							
				
				case '5':
					printf("\nExiting the program\n\n"); //exits the progam
					return 0;
					
				default:
					printf("Choose again: \n\n"); //asks user to choose again if anything other than a menu option is chosen
					break;
		}
		
	
}
			
return 0;
}

void Calc1() { //Calculation1 function
	int number1, number2;
	printf("Enter the First Number: \n");
	scanf("%d", &number1);
	printf("Enter the Second Number: \n");
	scanf("%d", &number2);
	int answer = number1 +number2;
	int userinput;
	printf("%d + %d = ?\n",number1, number2); //prints equation
	printf("What is the answer?\n"); //asks user to answer
	scanf("%d", &userinput);
	if(userinput == answer) { //if input is correct, it says so and if not it says its not
		printf("Correct!\n");
	
	}else {
		printf("Incorrect!\n");
	}
}

void Calc2() { //Calculation2 function
	int number1, number2;
	printf("Enter the First Number: \n");
	scanf("%d", &number1);
	printf("Enter the Second Number: \n");
	scanf("%d", &number2);
	int answer = number1 - number2;
	int userinput;
	printf("%d - %d = ?\n",number1, number2); //prints equation
	printf("What is the answer?\n"); //asks user to answer
	scanf("%d", &userinput);
	if(userinput == answer) { //if input is corredt, it says so and if not it says its not
		printf("Correct!\n");
		
	}else {
		printf("Incorrect!\n");
	}
}

void fileWrite() { //Write to File function
	FILE *file = fopen("output.txt", "w");
	if(file == NULL) {
		printf("Error opening file.\n");
		
	}
	char input[256];
	printf("Enter the text to be written to a file (type 'exit' to stop)\n"); //asks the user to enter the text to be written to a file
	while (1) {
		printf(">");
		fgets(input, sizeof(input), stdin);
		if(strncmp(input, "exit", 4) ==0){
			break;
		}
		fprintf(file, "%s", input);
	}
	fclose(file);
	printf("Text succesfully written to output.txt (find in same directory as the program)\n");
	
	return;
}

void readFile() { //Read File function 

		char filename[100];
		printf("Enter the name of the text file (with .txt extension): "); //asks the user to enter a file name 
		scanf("%99s", filename);
		FILE *file = fopen(filename, "r");
		if (file == NULL) {
			printf("Error: Could not open file %s\n", filename);
			
		}
		printf("\nContents of %s:\n", filename);
		char ch;
		while ((ch = fgetc(file))!= EOF) {
			putchar(ch);
		}
		fclose(file);
		printf("\nFile reading complete.\n");
}

