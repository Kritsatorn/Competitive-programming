#include<bits/stdc++.h>
using namespace std ;
int penalty , MoreP ,Can ;
void getMinimumPenalty(string x, string y, int pxy, int pgap) 
{ 
    int i, j; // intialising variables 
      
    int m = x.length(); // length of gene1 
    int n = y.length(); // length of gene2 
      
    // table for storing optimal substructure answers 
    int dp[n+m+1][n+m+1] = {0}; 
  
    // intialising the table  
    for (i = 0; i <= (n+m); i++) 
    { 
        dp[i][0] = i * pgap; 
        dp[0][i] = i * pgap; 
    }     
  
    // calcuting the minimum penalty 
    for (i = 1; i <= m; i++) 
    { 
        for (j = 1; j <= n; j++) 
        { 
            if (x[i - 1] == y[j - 1]) 
            { 
                dp[i][j] = dp[i - 1][j - 1]; 
            } 
            else
            { 
                dp[i][j] = min({dp[i - 1][j - 1] + pxy ,  
                                dp[i - 1][j] + pgap    ,  
                                dp[i][j - 1] + pgap    }); 
            } 
        } 
    } 
  
    // Reconstructing the solution 
    int l = n + m; // maximum possible length 
      
    i = m; j = n; 
      
    int xpos = l; 
    int ypos = l; 
  
    // Final answers for the respective strings 
    int xans[l+1], yans[l+1]; 
      
    while ( !(i == 0 || j == 0)) 
    { 
        if (x[i - 1] == y[j - 1]) 
        { 
            xans[xpos--] = (int)x[i - 1]; 
            yans[ypos--] = (int)y[j - 1]; 
            i--; j--; 
        } 
        else if (dp[i - 1][j - 1] + pxy == dp[i][j]) 
        { 
            xans[xpos--] = (int)x[i - 1]; 
            yans[ypos--] = (int)y[j - 1]; 
            i--; j--; 
        } 
        else if (dp[i - 1][j] + pgap == dp[i][j]) 
        { 
            xans[xpos--] = (int)x[i - 1]; 
            yans[ypos--] = (int)'_'; 
            i--; 
        } 
        else if (dp[i][j - 1] + pgap == dp[i][j]) 
        { 
            xans[xpos--] = (int)'_'; 
            yans[ypos--] = (int)y[j - 1]; 
            j--; 
        } 
    } 
    while (xpos > 0) 
    { 
        if (i > 0) xans[xpos--] = (int)x[--i]; 
        else xans[xpos--] = (int)'_'; 
    } 
    while (ypos > 0) 
    { 
        if (j > 0) yans[ypos--] = (int)y[--j]; 
        else yans[ypos--] = (int)'_'; 
    } 
  
    // Since we have assumed the answer to be n+m long,  
    // we need to remove the extra gaps in the starting  
    // id represents the index from which the arrays 
    // xans, yans are useful 
    int id = 1; 
    for (i = l; i >= 1; i--) 
    { 
        if ((char)yans[i] == '_' && (char)xans[i] == '_') 
        { 
            id = i + 1; 
            break; 
        } 
    } 
  

    // Printing the final answer 
    // cout << "Minimum Penalty in aligning the genes = "; 
    // cout << dp[m][n] << "\n"; 
    // cout << "The aligned genes are :\n"; 
    penalty = dp[m][n];
    int A=0 , B = 0 ;    
    for (i = id; i <= l; i++) 
    { 
        // cout<<(char)xans[i]; 
        if ((char)xans[i] == '_' ) A++;
    } 
    cout << "\n"; 
    for (i = id; i <= l; i++) 
    { 
        // cout << (char)yans[i]; 
        if ((char)yans[i] == '_' ) B++;
    } 
    MoreP = A > B ? 1: 0 ;
    //--
 Can = true;
      int isS = false ,isB = false;
    for (i = id; i <= l; i++) {
      if ((char)xans[i] =='*' ) isS = true ;
      else if ((char)xans[i] == '_' ) isB = true ;
      else if (isB == true && isS==false) {
        Can =false;
      }
      else {isB = false ; isS = false ;}
      //printf("f %c %d\n",(char)xans[i] , Can);
    }
    if ( isB) {
      if (!isS) Can=false;
    }
    // printf("Can %d",Can);
    if( !Can) return ;
      Can = true;
      isS = false ;isB = false;
    for (i = id; i <= l; i++) {
      if ((char)yans[i] =='*' ) isS = true ;
      else if ((char)yans[i] == '_' ) isB = true ;
      else if (isB == true && isS==false) {
        Can =false;
      }
      else {isB = false ; isS = false ;}
      // printf("f %c %d\n",(char)yans[i] , Can);
    }
    if ( isB) {
      if (!isS) Can=false;
    }
    // printf("Can %d",Can);
    //---
    return;

} 
main() {
  int test_case ,count_case = 0;
  scanf("%d",&test_case);
  while (count_case++ < test_case ) {
    int n ,index[52] , longest = 0;
    char s[52][110] ;
    scanf("%d",&n);
    for(int i=0 ; i <n ; i++) {
      scanf("%s",s[i]);
      int k = strlen(s[i])  ;
      longest = max(longest , k);
    }

    int King = 0 ;
    for(int i=1 ; i <n ; i++) {
      // ---

      // ---
      penalty = 0 ; MoreP = 0 ; Can = true;
      getMinimumPenalty(s[King], s[1],
        999, 1);
        // moreP = 1 change king
      if ( MoreP) King = i ;
      if ( !Can) continue ;
      //---
    }
    printf("Case #%d: ",count_case);
    if (Can)
      for(int i=0 ; i < strlen(s[King]) ; i ++) {
        if ( s[King][i] == '*') printf("A");
        else printf("%c",s[King][i]);
      }
    else printf("*");
    printf("\n");
  }
}