#include <stdio.h>
#include <stdlib.h>
/*
takes 1 argument, the height H of the diamond 
Prints a diamond which is made up of H rows of asterisk (a.k.a star, *) characters and spaces
*/

int main(int argc, char *argv[]) {
	if (argc<2 || argc > 2) {
		printf("ERROR: Wrong number of arguments. One required.\n");
		return -1;
	}

	int height = atoi(argv[1]);
	//printf("%d\n", height);  // for testing if height is really storing the integer
	if (height%2 == 0 || height < 0) {
		printf("ERROR: Bad argument. Height must be positive odd integer.\n");
		return -1;
	}


	int counter = 1; // to keep track of # of stars to print
	for (int i=0; i< height; i++) {


		if (i < height/2) {  // Top half of diamond
			for (int j=i; j<height/2; j++) {  // print the spaces
				printf(" ");
			}
			int k =0;
			while (k < counter) {
				printf("*");
				k++;
			}
			counter = counter +2;

		}

		else if (i == height/2) {  // Middle line of diamond
			for (int j=0; j< height; j++) {
				printf("*");
			}
		}

		else if (i > height/2) {  // bottom half of diamond
			for (int j=height/2; j<i; j++) {
				printf(" ");  // print the spaces (Opposite of "top half of diamond" spaces)
			}
			int k =0;
			counter = counter -2;
			while (k < counter) {
				printf("*");
				k++;
			}
			
		}

		printf("\n");
	}
	
	return 0;
}