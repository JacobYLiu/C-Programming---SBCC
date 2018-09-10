/*
 ============================================================================
 Name        : JLiuTestScoreStats.c
 Author      : Jacob Liu
 Version     :
 Copyright   : August 2016
 Description : Test Score Stats program, calculates count of scores, the min score, the max score, the average score, and the standard deviation
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);
	float score; //current score
	int counter = 0; // vari. to hold the times that user put in the scores
	float total = 0;
	float min = 9999;
	float max = 0;
	float stnDev; //standard deviation
	float sumSquares = 0;
	float average;
	char buffer[BUFSIZ];

	printf("Enter a test score (press enter to end):\n");
	do { // gathering information

		score = atof(fgets(buffer, BUFSIZ, stdin));
		if (buffer[0] == '\n') {
			break;
		}

			if (score < min) { //setting min
				min = score;
			}
			if (score > max) { //setting max
				max = score;
			}
			sumSquares = sumSquares + (score * score); // Sum of the squares
			total = total + score; //total of the sums
			counter = counter + 1; //counters


	} while (buffer[0] != '\n');
	if (counter == 0) { //calculating average and Standard Deviation when the user hits enter
		average = 0;
		stnDev = 0;
		min = 0;
	} else { // when the user puts random values or test scores
		average = total / counter;
		stnDev = sqrt(((sumSquares - (total * total) / counter)) / (counter));

	}
	printf("%d\t%f\t%f\t%f\t%f\n", counter, min, max, average, stnDev); //calculating everything

	return EXIT_SUCCESS;
}
