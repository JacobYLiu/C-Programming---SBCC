/*
 ============================================================================
 Name        : jLiuNucleotideCounter.c
 Author      : Jacob Liu
 Version     :
 Copyright   : September 2016
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);
	int numA = 0;
	int numC = 0;
	int numG = 0;
	int numT = 0;

	char filenameI[101];
	char filenameO[101];
	char nextChar;
	FILE *fpInput;
	FILE *fpOutput;

	//input file
	printf("Enter input filename:\n");
	fgets(filenameI, 100, stdin);

	int nameLengthI = strlen(filenameI); //removes newline character
	filenameI[nameLengthI - 1] = '\0';
	//output file
	printf("Enter output filename:\n");
	fgets(filenameO, 100, stdin);

	int nameLengthO = strlen(filenameO); //remove newline character
	filenameO[nameLengthO - 1] = '\0';
	fpOutput = fopen(filenameO, "w");
	printf("Complete\n");

	//open the file
	fpInput = fopen(filenameI, "r");
	if (fpInput == NULL) {
		printf("File could not be opened.\n");
	} else {

		while ((nextChar = fgetc(fpInput)) != EOF) {
			//looking for upper and lower case just in case
			switch (toUpper(nextChar)) {
			case 'A':
				numA++;
				break;
			case 'C':
				numC++;
				break;
			case 'G':
				numG++;
				break;
			case 'T':
				numT++;
				break;
			case '\n':
				fprintf(fpOutput, "%d %d %d %d\n", numA, numC, numG, numT);
				numA = 0, numC = 0, numG = 0, numT = 0;
				break;
			}
		}
		fclose(fpInput);
		fclose(fpOutput);
	}


	return EXIT_SUCCESS;
}

