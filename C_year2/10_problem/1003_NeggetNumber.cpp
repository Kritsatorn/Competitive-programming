#include<stdio.h>

int arr_nugget[102], n;

void find_negget(int num){
  if (arr_nugget[num] == 1 || num > n)
    return ;

  arr_nugget[num] = 1;

  find_negget(num+6) ;
  find_negget(num+9) ;
  find_negget(num+20) ;
  return ;
}

int main(int argc, char const *argv[])
{
  bool no = true;
  scanf("%d",&n);
  find_negget(0);
  for(int i = 1 ; i <= n ; i++ ){
    if(arr_nugget[i] == 1){
      printf("%d\n",i);
      no = false;
    }
  }
  if (no)
    printf("no");
  return 0;
}
