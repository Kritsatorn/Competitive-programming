#include <iostream>
using namespace std;

void dosomething(int** x,int* y)
{
  // int (*x)[110] = (int(*)[110])new int[110];
  
  *x = y ;
}

main()
{
  int* x = 0;

  dosomething(&x,&(new int[110])[0] );
  for(int i=0; i<100; i++) {
    x[i] = i*2;
  }
  cout << x[1] + x[20] + x[99] << endl;

  delete [] x;
}