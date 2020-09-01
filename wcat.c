// Programmer:			Zachary William Preston
// Date:			2020 August 31
// Course:			Intro to Operating Systems
// Description:			A recreation of the cat linux command, will print the contents of a file to the screen

// Preprocessor Directives
#include <stdio.h>
#include <stdlib.h>
#define FILE_ERROR "wcat: cannot open file"

// Function Prototypes
int getLength(char *);
void getContents(char *, char *, int);

// Main function - function invocation happens here
// if 1 or less arguements are typed, then there are no files to view
// so return nothing
// otherwise traverse the list and print contents for all files found
int main(int numFiles, char *fileList[]) {
	if (numFiles <= 1) {
		exit(0);
	} else {
		for (int i = 1; i < numFiles; i++) {
			int length = getLength(fileList[i]);
			char *contents = (char *) malloc (length * sizeof(char));
			getContents(fileList[i], contents, length);
			printf( "                           File Name = %s\n", fileList[i] );
			printf( "-----------------------------------------------------------------------------\n" );
			printf( "%s\n\n\n", contents );
		}
	}
	return EXIT_SUCCESS;
}

// Returns the length of the file (how many characters there are, used for memory
// allocation to save as much space as possible
int getLength(char *fileName) {
	FILE *file = fopen(fileName, "r");
	if (file == NULL) {
		printf( "%s\n", FILE_ERROR );
		exit(1);
	} else {
		int length = 0;
		while (getc(file) != EOF)
			length++;
		fclose(file);
		return length;
	}
}

// Uses the allocated memory from getLength() to write the contents from the file
// to the allocated memory locations, then adds a null character
void getContents(char *fileName, char *contents, int length) {
	FILE *file = fopen( fileName, "r" );
	if (file == NULL) {
		printf( "%s\n", FILE_ERROR );
		exit(1);
	} int i = 0;
	while (i < length) {
		contents[i] = getc(file);
		i++;
	} fclose(file);
	contents[i] = '\0';
}
