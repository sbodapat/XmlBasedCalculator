/* Learning curve for xml parsing based calculator. */
/* This is for file parsing and how do we do it.    */

/* This file only deals on how to parse the file and re print them.*/
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
int compareString (char* tempStorage);


int main() {
	FILE* fp;
	char file_name[100];
	char c;
	char tempStorage[10];
	int whiteSpaceCounter,carriageReturnCounter,i,numberOfCounts,countWordCount;
	/* Initializing all the variables */
	whiteSpaceCounter = 0;
	carriageReturnCounter = 0;
	i=0;
	numberOfCounts = 0;
	countWordCount = 0;

	printf("Enter the filename: ");
	/*scanf("%s",file_name);*/

	fp = fopen("a.txt","r"); /* Needs to have double quote to work */

	if (!fp) {
		printf("Nothing in file\n");
		printf("something went wrong: %s", strerror(errno));
		exit(1);
	}
	c = fgetc(fp);

	while (c!= EOF) {
		printf ("%c",c);
		/* This is to count white spaces in the text file */
		/*if (c == 32U) {
			whiteSpaceCounter++;
		}
		/* It ends here 
		if (c == 13U) {
			carriageReturnCounter++;
		}*/
		/*if (c == '<') {
		    printf("\n From Code: Am I entering here\n");
			tempStorage[i] = c;
			i++;
			if (c == 32U){
				numberOfCounts = compareString (tempStorage);
				i = 0;
			}
			if (numberOfCounts){
				countWordCount++;
			}
		}*/
		c = fgetc(fp);
	}
	fclose (fp);
	/*printf("\nWhitespaces are: %d\n",whiteSpaceCounter);
	printf("Carriage Return are: %d\n",carriageReturnCounter);
	printf("number of count in the text file are: %d\n",countWordCount);*/
	return 0;
}

/*int compareString (char* tempStorage) {
    int i;
	for (i=0;i<10;i++) {
		printf("%c",tempStorage[i]);
		printf(" index:%d ",i);
	}
	if (tempStorage[0] == 'c' && tempStorage[1] == 'o' && tempStorage[2] == 'u'
	    && tempStorage[3] == 'n' && tempStorage[4] == 't' /*&& (tempStorage[5] == ' ' || 
		tempStorage[5] == 13U || tempStorage[5] == '.')*/){
	/*		printf ("\nFrom code: Entering the true part of the function\n");
			
			return 1;
		}
	else {
		return 0;
	}
}*/