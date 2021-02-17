#include<stdio.h>
// #include<vector>
#include<queue>
using namespace std;
int n ,b[110][100],g[110][100];
int engaged[100] ,check_man[110];
queue<int> q[110];
main() {
  scanf("%d",&n);
  // input boys
  for(int i=1 ; i<=n ; i++)
    for(int j=0 ; j<n ; j++) {
      int temp ;
      scanf("%d",&temp);
      q[i].push(temp);
    }
    // input girls
  for(int i=1 ; i<=n ; i++)
    for(int j=0 ; j<n ; j++)
      scanf("%d",&g[i][j]);


  int date = -1;
  // arr[ g ] [ b ];
  while(++date < n) {
    // b 0 to n
    for(int i=1 ;i<=n ;i++) {
      // printf("mer %d and date %d : %dn\n",i,date,b[i][date]);
      if(check_man[i]) continue;
      int girl = q[i].front();  q[i].pop();
      // printf("free -- mannn   =  %d\n",i);
      if( engaged[girl] != 0) {
        for (int j=0 ;j <n ;j++)
        // i or arr[b[i][date]]
          if (i == g[girl][j]) {
            check_man[engaged[girl]] = 0;
            engaged[girl] = i;
            check_man[i] = 1;
            break ;
          }
          else if (engaged[girl] == g[girl][j])
            break;
      } else {
        engaged[girl] = i;
        check_man[i] = 1;
      }
      // printf("Date %d \n",date);
    }
  }
  for(int i=1 ; i<=n ; i++)
       printf("%d %d\n",i,engaged[i]);
}