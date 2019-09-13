
#include <stdio.h>
#include <stdlib.h>

/* For printing full diamond
https://www.programmingsimplified.com/c/source-code/c-program-print-diamond-pattern
*/

int printTriangle(int n);

int main(int argc, char *argv[]) {
  int n = atoi(argv[1]);
  printTriangle(n);

}

int printTriangle(int n) { 
  int space = n/2;
  int c = 1;

  for (int k = 1; k <= (n+1)/2; k++) {
    for (c = 1; c <= space; c++) {
      printf(" ");
    }
 
    space--;
 
    for (c = 1; c <= 2*k-1; c++)
      printf("*");
    
    for (int pos = space+c; pos <= n; pos++) {
      printf("9");
    }
    printf("\n");
  }
}