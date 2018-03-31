#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
int max(int a, int b){
    return (a>b ? a :b);
}
int* longestCommonSubsequence(int m, int* X, int n, int* Y, int *result_size) {
   int L[m+1][n+1];
  
   /* Following steps build L[m+1][n+1] in bottom up fashion. Note 
      that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
   for (int i=0; i<=m; i++)
   {
     for (int j=0; j<=n; j++)
     {
       if (i == 0 || j == 0)
         L[i][j] = 0;
  
       else if (X[i-1] == Y[j-1])
         L[i][j] = L[i-1][j-1] + 1;
  
       else
         L[i][j] = max(L[i-1][j], L[i][j-1]);
     }
   }
    
   /* L[m][n] contains length of LCS for X[0..n-1] and Y[0..m-1] */
    int index =  *result_size = L[m][n];
    int * result = (int *) malloc( ( *result_size + 1) * sizeof(int));
    result[index] = '\0';
    int i = m , j = n;
     while ( i>0 && j>0)
     {     

           if(X[i-1] == Y[j-1])
           {
             result[index - 1] = X[i-1];
               i--; j--; index --;
           }
           else if (L[i-1][j] > L[i][j-1]) {
               i--;
           }
           else 
               j --;
     }
    return result; 
    
}

int main() {
    int n; 
    int m; 
    scanf("%i %i", &n, &m);
    int *a = malloc(sizeof(int) * n);
    for (int a_i = 0; a_i < n; a_i++) {
       scanf("%i",&a[a_i]);
    }
    int *b = malloc(sizeof(int) * m);
    for (int b_i = 0; b_i < m; b_i++) {
       scanf("%i",&b[b_i]);
    }
    int result_size;
    int* result = longestCommonSubsequence(n, a, m, b, &result_size);
    for(int result_i = 0; result_i < result_size; result_i++) {
        if(result_i) {
            printf(" ");
        }
        printf("%d", result[result_i]);
    }
    puts("");


    return 0;
}
