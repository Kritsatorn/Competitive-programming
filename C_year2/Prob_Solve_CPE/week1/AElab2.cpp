#include <stdio.h> 
#include <string.h> 
using namespace std;
// A function to check if a string str is palindrome 
void isPalindrome(char str[]) 
{ 
    // Start from leftmost and rightmost corners of str 
    int l = 0; 
    int h = strlen(str) - 1; 
  
    // Keep comparing characters while they are same 
    while (h > l) 
    { 
        if (str[l++] != str[h--]) 
        { 
            printf("no"); 
            return; 
        } 
    } 
    printf("yes"); 
} 
  
// Driver program to test above function 
int main() 
{ 
    char s[1000];
    scanf("%s",s) ;
    isPalindrome(s);
    return 0; 
}