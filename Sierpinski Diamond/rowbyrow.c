#include <stdio.h>
#include <stdlib.h>
int printTriangle(int n, int row);

int main(int argc, char *argv[]) {
  int n = atoi(argv[1]);

  for (int row = 1; row<=(n+1)/2; row++) {
    printTriangle(n,row);
    printf("\n");
  }

  

}

int printTriangle(int n, int row) { 
  int space = n/2 - row +1;
  int c = 1;
    for (int c = 1; c <= space; c++) {
      printf(" ");
    }
 
 
    for (c = 1; c <= 2*row-1; c++)
      printf("*");
    
    for (int pos = space+c; pos <= n; pos++) {
      printf("9");
    }
  
}