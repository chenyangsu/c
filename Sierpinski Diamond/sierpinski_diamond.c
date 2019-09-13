#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// Think of this question as building up large diamond with smaller diamonds
// instead of removing

int isPowerOfTwo(int n); // need to either 1. declare function before main method or will get "Implicit Function declaration error" OR
					     // 2. Have the function up here before main method
int power(int x, unsigned int y); 

int printRow(int row, int height, int level);
int printTriangle(int n, int row);

int main(int argc, char *argv[]) {  // arg[1] = height of triangle, arg[2]= fractal level (L)
	
	// check that 2 inputs are given
	if (argc<3 || argc > 3) {
		printf("ERROR: Wrong number of arguments. Two required.\n");
		return -1;
	}
	// check that the height of diamond is positive odd integer
	int height = atoi(argv[1]);
	//printf("%d\n", height);  // for testing if height is really storing the integer
	if (height%2 == 0 || height < 0) {
		printf("ERROR: Bad argument. Height must be positive odd integer.\n");
		return -1;
	}	
	int level = atoi(argv[2]);
	if (level < 1) {
		printf("ERROR: Height does not allow evenly dividing requested number of levels.\n");
		return -1;
	}	
	int h = ((height+1)/2) ; // same as ceil() function because we already checked that height is a positive odd integer
	//printf("The value of h is: %d\n", h);  // for checking value of h
	if (isPowerOfTwo(h) == 0 || h < power(2, level-1)) {  
	// h must be power of 2 and also greater than or equal to power(2,level-1), if not we cannot proceed
		printf("ERROR: Height does not allow evenly dividing requested number of levels.\n");
		return -1;
	}
	
	/* Actual CODE */
	// print top half of sierpinski diamond
	// h holds the top rows (e.g. diamond = 15 rows; h = 8)
	for (int row = 1; row<=h; row++) {
		printRow(row, h, level);
		printf("\n");
	}

	// print bottom half of sierpinski diamond
	for (int bRow = h-1; bRow > 0 ; bRow--) {
		printRow(bRow, h, level);
		printf("\n");
	}
	return 0;
}


/* Function for printing each row of sierpinski triangle */
int printRow(int row, int height, int level) {
	// if level = 1, we are just doing Q1a
	if (level == 1) {
		printTriangle(height*2-1, row);  // pass the original diamond height
		return 0;
	}
	// if we are in top row
	if (row <= height/2) {
		//printf("%d", row);
		for (int i = 0; i< height/2; i++) {
			printf(" ");
		}
		printRow(row, height/2, level-1);
		for (int i = 0; i<height/2; i++) {
			printf(" ");
		}

	}

	// bottom half rows of sierpinski diamond
	else if (row > height/2) {
		printRow(row - height/2, height/2, level-1);  // print the bottomleft triangle
		printf(" ");  // print the single space betwen the left and right triangle
		printRow(row- height/2, height/2, level-1);  // print the bottom right triangle

	}

	return 0;
}


// function to print level 1 triangle
int printTriangle(int n, int row) { 
  	int space = n/2 - row +1;

  //printf("%d\n", space);
  	// print spaces on left
  	int c = 1;
  	for (c = 1; c <= space; c++) {
      printf(" ");
    }
 	// print the stars
    for (c = 1; c <= 2*row-1; c++)
      printf("*");
    // print the spaces on the right
    for (int pos = space+c; pos <= n; pos++) {
      printf(" ");
    }
  	return 0;
}

/* Function to check if x is power of 2*/
// ewturns 1 if is power of 2 and returns 0 otherwise
int isPowerOfTwo(int n) 
{ 
  if (n == 0) 
    return 0; 
  while (n != 1) 
  { 
      if (n%2 != 0) 
         return 0; 
      n = n/2; 
  } 
  return 1; 
} 




/* Function to get the power of something */
int power(int x, unsigned int y) { 
    if (y == 0) 
        return 1; 
    else if (y%2 == 0) 
        return power(x, y/2)*power(x, y/2); 
    else
        return x*power(x, y/2)*power(x, y/2); 
} 