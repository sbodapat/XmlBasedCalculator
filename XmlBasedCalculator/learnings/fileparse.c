/* Learning curve for xml parsing based calculator. */
/* This is for file parsing and how do we do it.    */
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main() {
	FILE* fp;
	char file_name[100];
	char c;

	printf("Enter the filename: ");
	scanf("%s",file_name);

	fp = fopen(file_name,"r"); /* Needs to have double quote to work */

	if (!fp) {
		printf("Nothing in file\n");
		printf("something went wrong: %s", strerror(errno));
		exit(1);
	}
	c = fgetc(fp);

	while (c!=EOF) {
		printf ("%c",c);
		c = fgetc(fp);
	}
	fclose (fp);
	return 0;
}