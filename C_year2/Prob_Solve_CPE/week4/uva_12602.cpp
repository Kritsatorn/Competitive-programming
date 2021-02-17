#include<iostream>
#include<math.h>
using namespace std ;
main() {
  int n;
  cin >> n ;
  while ( n-- > 0 )
  {
    char s[10];
    cin >> s ;
    int cal_first_part = 0 ;
    cal_first_part = (s[0] - 'A')*26*26 + (s[1] - 'A')*26 + (s[2] - 'A') ;
    int cal_second_part = 0 ;
    cal_second_part = (s[4] - '0')*1000 + (s[5] - '0')*100 + (s[6] - '0')*10 + (s[7] - '0')*1 ;
    int cal_ans = 0 ;
    cal_ans = abs(cal_first_part - cal_second_part) ;
    // cout << s << " " << cal_first_part << " " << cal_second_part << endl;
    if ( cal_ans <= 100)
      cout << "nice" << endl;
    else
      cout << "not nice" << endl ;
  }
}