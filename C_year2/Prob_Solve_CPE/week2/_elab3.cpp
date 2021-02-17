#include <iostream>
using namespace std;
char* write_chars(char* dest, const char* st) {

  while ( true) {
    if(*st == '\0') break;
    *dest++ = *st++;
  }
  *dest--;
  return dest;
}
void escape(char* src, char *dest) {
   while ( true)
  {
    if ( *src == '\0' ) {
      *dest = '\0';
      break;
    }
    *dest = *src ;
    switch(*dest) {
      case '<' : dest = write_chars(dest,"&lt;");
      break ;
      case '>' : dest =  write_chars(dest,"&gt;");
      break ;
      case '\"' : dest = write_chars(dest,"&quot;");
      break ;
    }

    *dest++;
    *src++;

  }
}
main()
{
  char st[1000];
  char out[1000];
  int l;

  cin.getline(st,1000);
  escape(st,out);

  cout << out << endl;
}