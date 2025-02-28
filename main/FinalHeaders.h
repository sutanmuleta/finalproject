
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

void writeFile() { //Write to File function
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
