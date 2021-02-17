#include<stdio.h>
#include <stdlib.h>
struct color {
  int R ,G ,B ;
};
void main () {
  int n ,m ,t;
  n = 10  ; m = 4 ; t = 5 ;
  struct color ***array = (struct color***)malloc(n*sizeof(struct color**));
  int i, j;

  for (i = 0; i < 3; i++) {
    array[i] = (struct color**)malloc(m*sizeof(struct color*));
    for (j = 0; j < 3; j++) {
      array[i][j] = (struct color*)malloc(t*sizeof(struct color));
    }
  }

  // array[1][2][1].;

  return ;
}