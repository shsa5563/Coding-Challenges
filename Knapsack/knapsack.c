// A Dynamic Programming based solution for 0-1 Knapsack problem - using memoization 
#include<stdio.h>
 
// A utility function that returns maximum of two integers
int max(int a, int b) { return (a > b)? a : b; }
 
int row =0; column =0;
int knapSack_Recursion(int W,  int n, int wt[], int val[], int memoization [row][column])
{
    int result =0 ; 
    if(memoization[n][W] != 0)
    {
        return memoization[n][W]; 
    }
    if(W==0 || n==0)
    return 0;
    if(wt[n] > W)
    {
       result =  knapSack_Recursion( W,   n-1, wt, val, memoization);
    }else{
        int temp1 = knapSack_Recursion( W, n-1, wt, val, memoization);
        int temp2 = knapSack_Recursion( (W -wt[n]), n-1, wt, val, memoization);
       result =  max( temp1, (val[n] + temp2 ));
    }
    memoization[n][W] = result;
    return result;
}


// Returns the maximum value that can be put in a knapsack of capacity W
int knapSack(int W,int n, int wt[], int val[])
{
   int i, w;
   int K[n+1][W+1];
 
   // Build table K[][] in bottom up manner
   for (i = 0; i <= n; i++)
   {
       for (w = 0; w <= W; w++)
       {
           if (i==0 || w==0)
               K[i][w] = 0;
           else if (wt[i-1] <= w)
                 K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);
           else
                 K[i][w] = K[i-1][w];
       }
   }
 
   return K[n][W];
}
 
int main()
{
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int  W = 50;
    int n = sizeof(val)/sizeof(val[0]);
    printf("without knapSack_Recursion=%d\n", knapSack(W, n,wt, val));
    int memoization[n][W+1];
    int len = (n*(W+1)) * sizeof(int);
    memset(memoization, '\0', len);
    row = n; column = W+1;
    printf("with knapSack_Recursion=%d\n", knapSack_Recursion(W, n-1, wt, val, memoization));
    
    return 0;
}
