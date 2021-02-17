#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
  int n , m;
  scanf("%d %d",&m,&n);
  bool prime[n+1] ;
  memset(prime, true, sizeof(prime));
  for (int p=2; p*p <= n ; p++)
    if (prime[p] == true)
      for (int i = p*2; i<=n ; i+=p)
        prime[i] = false ;
  int count = 0 ; prime[1] = false;
  for (int p=m; p<= n - 2; p++)
       if (prime[p] && prime[p+2])
        count++;
  printf("%d",count);
  return 0;
}
