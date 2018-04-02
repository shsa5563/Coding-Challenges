#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void swap(int* a,int* b )
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
// N* (N+1) /2 sOLUTION 
void bubbleSort(int * arr, int size)
{
    for(int i =0; i<size-i; i++)
    {
        for(int j=i; j<size-i ; j++)
        {
            if(arr[j] > arr[j+1])
            {
                swap(&arr[j], &arr[j+1]); 
            }
        }
    }
}

// N * N sOLUTION 
void bubbleSortN2(int * arr, int size)
{
    for(int i =0; i<size; i++)
    {
        for(int j=i; j<size ; j++)
        {
            if(arr[j] > arr[j+1])
            {
                swap(&arr[j], &arr[j+1]); 
            }
        }
    }
}

int main()
{

  int array[100000];
  
  int size = sizeof(array)/sizeof(array[0]);
  for(int i=0;i<100000; i++)
  {
      array[i] = (int)rand();
  }
  int temp1[100000];
  for(int i=0;i<100000; i++)
  {
      temp1[i]= array[i];
  }
  
  double seconds;
  time_t started=time(NULL);
  bubbleSort(temp1, size);
  seconds=difftime(time(NULL),started);
  
  printf("the val with O( n(n+1)/2 ):%lf\n", seconds);
    
  for(int i=0;i<100000; i++)
  {
      temp1[i]= array[i];
  }
  started=time(NULL);
  bubbleSortN2(temp1, size);
  seconds=difftime(time(NULL),started);
  
  printf("the val with O( n^2 ):%lf", seconds);
  
  return 0;
}

/****************** OutPut with 100000 entries ***************
the val with O( n(n+1)/2 ):11.000000                                                                                                         
the val with O( n^2 ):16.000000
