/*
 ============================================================================
 Name        : JLiuHTMLSrc.c
 Author      : Jacob Liu
 Version     :
 Copyright   : October 2016
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int numSRC(char *html); //number of valid src attributes in the HTML
int freq(char *html);	//print tag names and tag counts
int getUrl(char *html); //Each time a valid src attribute is found, print the associated URL with /n
void printTags(char *html); //When a valid src attribute is found, print the associated tag name with /n

//Asks user for a url, and then can comes html status
int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0); //first executable line to turn off output buffering
	printf("URL:\n"); // print out the url
	char input; // the input character
	char buffer[BUFSIZ + 1];
	char *html = (char*) malloc(260000); //html char size pointers
	char *url = (char*) malloc(100000); //url char size pointers

	strcat(url, "curl -s "); // puts url in the command line
	gets(buffer);
	strcat(url, buffer); // buffers the url

	FILE *fp; // pointers the FILE
	fp = popen(url, "r"); // opens the url file and read it
	int i = 0; // set variable to 0

	while (fgets(buffer, BUFSIZ, fp) != NULL) {

		html = strcat(html, buffer);
	}

	printf("Ready\n");

	int end = 0;

	do {

		switch (getc(stdin)) { //prints out Ready from each status
		case 'c':
			numSRC(html);
			printf("Ready\n");
			break;
		case 't':
			printTags(html);
			printf("Ready\n");
			break;
		case 'u':
			getUrl(html);
			printf("Ready\n");
			break;
		case 'f':
			freq(html);
			printf("Ready\n");
			break;
		case 'q':
			end = 1;
			break;
		default:
			break;
		}
	} while (end == 0);
	printf("Complete\n");
	return 0;
}

//Calculates the number of valid src tags in htlm
int numSRC(char *html) {
	int num = 0;
	while ((html = strstr(html, "src=\"")) != NULL) {
		if (isspace(*(html - 1))) {
			num++;
		}
		html++;
	}
	printf("%d\n", num);
	return 0;
}

//Finds and prints out all url related and url tags
int getUrl(char *html) {
	while ((html = strstr(html, "src=\"")) != NULL) {
		if (isspace(*(html - 1))) {
			html += 5;
			while (*html != '\"') {
				//prints letter by letter
				printf("%c", *html);
				html++;
			}
			printf("\n");

		}
		html++;
	}
	return 0;
}

//Prints all tags with src tags
void printTags(char *html) {
	int position = 0;
	char tag[BUFSIZ];
	char *pTag;
	while ((html = strstr(html, "src=\"")) != NULL) {
		if (isspace(*(html - 1))) {
			pTag = html++;
			while (*(pTag - 1) != '<')
				pTag--;
			position = 0;
			while (!isspace(*pTag))
				tag[position++] = *(pTag++);
			tag[position] = '\0';
			printf("%s\n", tag);
		}
		html++;
	}

}
//Calculates and prints the freq of every tag
int freq(char *html) {
	int length = 0;
	char pTr[500][100]; //assigning the array amount for
	int strLen[500];

	while ((html = strstr(html, "src=\"")) != NULL) {
		if (isspace(*(html - 1))) {
			char *at = html;
			html++;
			while (*at != '<') {
				at--;
			}

			int x = 0;
			while (!isspace(*at)) {
				at++;
				pTr[length][x] = *at;
				x++;
			}

			strLen[length] = x;
			length++;
		}
	}
	int i;
	for (i = 0; i < length; i++) {
		pTr[i][strLen[i] - 1] = '\0';
	}
	int numUnq = 1; //setting the variable to 1
	char unqTags[100][100]; //setting the variable to arrays contain 100
	strcpy(unqTags[0], pTr[0]); //copying the first index
	for (i = 0; i < length; i++) {

		int j;
		int count = 0;
		for (j = 0; j < numUnq; j++) {
			if (!strcmp(unqTags[j], pTr[i])) {
				count++;
			}

		}
		if (count == 0) {

			strcpy(unqTags[numUnq], pTr[i]);
			numUnq++;
		}
	}

	for (i = 0; i < numUnq; i++) {

		int num;
		num = 0;
		int j;
		for (j = 0; j < length; j++) {

			if (!strcmp(unqTags[i], pTr[j])) {
				num++;
			}
		}

		printf("%s\t%d\n", unqTags[i], num);

	}

	return 0;
}

