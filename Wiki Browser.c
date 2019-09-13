#include <stdio.h>
#include <string.h>
/*
Takes a filenname as its first argument
Reads that file and then finds strings that match the pattern
<a href="/wiki/PageName" ... title="...">...</a>
and for every match it should output PageName on a line on the terminal
*/

int main(int argc, char *argv[]) {

	if (argc != 2) {
		printf("ERROR: Wrong Number of arguments. One required.\n");
		return 1;
	}

	FILE* fp = fopen( argv[1], "r");

	if (fp == NULL) {  // must ALWAYS check if the pointer fp is null
		printf("ERROR: Problem with opening file.\n");
		return 1;
	} else {  // if fp is not null then can proceed
		// Next  few lines stores how large the file is in sz
		size_t sz;
		fseek(fp, 0L, SEEK_END);
		sz = ftell(fp);
		rewind(fp);

		char file_data_array[sz+1]; // one more for the \0
		fread(file_data_array, 1, sz+1, fp);  // storing file contents into file_data_structure
		//printf("%ld\n", sz);  // for checking total size

		char *ptr = file_data_array;
		char * needle1 = "<a href=\"/wiki/";  // start of files we want
		char * needle2 = "</a>"; // ending of files we want
		char *p1;  // store contents from parsing with strstr using ptr needle1
		char *p2;  // store contents from parsing with strstr using p1 and needle 2

		while (*ptr) {  // The while condition becomes false when we hit \0
			p1 = strstr(ptr, needle1); // will hold first occurrence of  <a href="/wiki/ ... </a> ...... to end of file
			if (p1) {
				p2 = strstr(p1, needle2);   // will hold </a>... to end of file
			} else {
				break; // break out if p1 not found
			}

			if (p2) {
				long int length = strlen(p1) - strlen(p2) +4;  // add 4 (for "</a>") to get full length of this link 
				char str[length + 1];
				//memcpy: Copies the values of length bytes from the location pointed to by p1 directly to the memory block pointed to by str.
				memcpy(str, p1, length); 
				str[length] = '\0';  // add the \0

				if (strstr(str, "title=\"")) {  // parse str which stores <a href="/wiki/ ... </a> for links with title="" included in between
					char * n1 = "<a href=\"/wiki/";
					char * n2 = "\"";  // the PAGENAME is stored between the end of n1 and start of n2
					char * start = strstr(str,n1);
					char * end = strstr(start+15, n2);  // point to the beginning of PAGENAME
					long int newStringLength = strlen(start) - strlen(end) -15; //holds the size of PAGENAME (subtract 15 to take off <a href="/wiki/)
					char newString[newStringLength+1]; // for the \0
					start = start +15; // move pointer to start of PAGENAME
					memcpy(newString, start, newStringLength); 
					newString[newStringLength]='\0';
					printf("%s\n", newString);
				}
			}
			
			ptr = p2 +4;  // do all this again but from the first character after the </a> stored in p2
		}
		return 0;
	}
	return 0;
}