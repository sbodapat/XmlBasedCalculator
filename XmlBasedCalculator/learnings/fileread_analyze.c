#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FILENAMELENGTH 100
#define MAXSIZE 1000

void processXmlFile (char* fileName);
int checkValidXml (char* storeElementData);

void main(){
	char fileName[FILENAMELENGTH];
	
	printf ("File Name: ");
	/*scanf ("%s",fileName);*/
	strcpy (fileName,"a.xml");

	for (int i=0;i<FILENAMELENGTH;i++) {
		/*Check for period in the file*/
		if (fileName[i] == 46U) {
			/*Check if the file given as input is an xml file*/
			if (fileName[i+1] == 'x' && fileName[i+2] == 'm' && fileName[i+3] == 'l') {
				printf ("The file is xml file \n");
				processXmlFile(fileName);
			}
			else {
				printf ("Enter an xml file \n");
			}
		}
	}
	/*fileElementRead = getc(fp);*/
}

void processXmlFile (char* fileName) {
	/*Process the XML input file.*/
	/* Declarations Begin*/
	FILE *fp;
	char fileElementRead;
	char storeElementData[MAXSIZE];
	int element;
	int initialCheck = 0;

	element = 0;
	
	printf("I am here HI \n");
	fp = fopen(fileName,"r");
	/*Checks for Null File Pointer*/
	if (fp == NULL) {
		/*File pointer returned NULL; hence exiting the prog.*/
		printf("Read unsuccessful.\n");
		exit(1);
	}
	fileElementRead = getc(fp);
	/*Iterate through the XML file and analyze*/
	while (fileElementRead != EOF) {
		storeElementData [element] = fileElementRead;
		element ++;
		/*Check for the XML end tag and initially check for the catalog.*/
		if (initialCheck == 0) {
			if(fileElementRead == '>'){
				/*Check for catalog*/
				initialCheck = checkValidXml(storeElementData);
			}
			element = 0;
		}
		printf ("initialCheck val: %d\n",initialCheck);
		fileElementRead = getc(fp);
	}
}

int checkValidXml (char* storeElementData) {
	int element = 0;
	for (element = 0; element < MAXSIZE; element++) {
	    printf ("element: %c\t",storeElementData[element]);
		if (storeElementData[element] == 'c') {
			if (storeElementData[element + 1] == 'a' && storeElementData[element + 2] == 't' &&
			    storeElementData[element + 3] == 'a' && storeElementData[element + 4] == 'l' &&
		        storeElementData[element + 5] == 'o' && storeElementData[element + 6] == 'g' &&
				storeElementData[element + 7] == '>'){
					printf ("Found catalog \n");
					return 1;
				}
		}
		else{
			return 0;
		}
	}
}