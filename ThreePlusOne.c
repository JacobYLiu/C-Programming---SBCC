/*
 ============================================================================
 Name        : JLiuThreeNPlusOne.c
 Author      : Jacob Liu
 Version     :
 Copyright   : September 2016
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
We declare the function that we are going to use in the beginning of the C program file.
We define the functions in the end of the main function.
 */
int computeMaxSequenceLength(int one, int two);
int computeSequenceLength();
int computeNextValue();
int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);

	char filename[101];
	char buffer1[101];
	char buffer2[101];
	FILE *fpOutput;

	printf("Enter output filename:\n"); //Asks user for output filename
	fgets(filename, 100, stdin);

	int nameLengthO = strlen(filename);
	filename[nameLengthO - 1] = '\0'; // deletes the first slot of the string
	fpOutput = fopen(filename, "w"); // opens the file name, fpOutput, and writing inside of it.
	if (fpOutput == NULL) { // if the file can not be found or comes out a error, then the sends out the message, "File could not be opened."
		printf("File could not be opened.\n");
	} else {
		fpOutput = fopen(filename, "w");
	}

	do {
		int firstValue = atoi(fgets(buffer1, 100, stdin)); // getting every character in the first input and turning that into a integer
		if (buffer1[0] != '\n') {
			int firstLength = strlen(buffer1);
			buffer1[firstLength - 1] = '\0'; // deletes the 0 of the memory slot, so it begins counting (1,2,3,4,5) instead of (0,1,2,3,4).

		// same thing from firstValue and firstLength
		int lastValue = atoi(fgets(buffer2, 100, stdin));
			int lastLength = strlen(buffer2);
			buffer2[lastLength - 1] = '\0';
			int maxSequence = computeMaxSequenceLength(firstValue, lastValue);
			fprintf(fpOutput, "%d\t%d\t%d\n", firstValue, lastValue, maxSequence);
		}
	} while (buffer1[0] != '\n'); // when the first value is not a enter then it calculates the whole thing.

	printf("Complete\n");
	return EXIT_SUCCESS;
}
// The computeMaxSequenceLength is taking any values from firstValue and lastValue and calculates the number of sequences to get to 1.
int computeMaxSequenceLength(int one, int two) {
	int max = 0;
	int i;
	for (i = one; i <= two; i++) {
		int length = computeSequenceLength(i);
		if (length > max) {
			max = length;
		}
	}

	return max;
}
// The computeSequenceLength is taking the values from the algorithm in computeNextValue and solving HOW to calculate the sequence if the result is not equal to 1.
int computeSequenceLength(int current) {
	int result = current;
	int count = 1;
	while (result != 1) {
		result = computeNextValue(result);
		count++;
	}
	return count;
}
// computeNextValue function is the function that solves the natural number if it is even or odd number.
int computeNextValue(int natural) {
	if (natural % 2 == 0) {
		natural = natural / 2;
	} else {
		natural = natural * 3 + 1;
	}
	return natural;
}
