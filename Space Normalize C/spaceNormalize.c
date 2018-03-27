// This code tests which method is better to normalize spaces with constant space. 

#include <stdio.h>
#include <sys/time.h>
#include <string.h>

int remSpace1(char * str)
{
    int i = 0, j =0, flag = 0;
    if (str != NULL)
    {
        while(str[i] != '\0')
        {
            
            if(str[i] !=' ')
            {
                str[j] = str[i]; 
                j++;
                i++;
                flag = 1;
            }else if (flag){
                flag = 0;
                str[j] = ' ';
                j++;
            }
            i++;
            
        }
        str[j] = '\0';
        return 1;
    }
        return 1;
}

int remSpace2(char * str)
{
    int i = 0, j =0, first = 0;
    if (str != NULL)
    {
        while(str[i] != '\0')
        {
            if(first)
            {
                first = 0;
                str[j] = ' ';
                j++;
            }
            while((str[i] != '\0')&&(str[i] !=' '))
            {
                str[j] = str[i]; 
                j++;
                i++;
                first = 1;
            }
            i++;
        }
        str[j] = '\0';
        return 1;
        
    }
        return 1;
}
int main()
{
    
struct timeval  tv1, tv2;
gettimeofday(&tv1, NULL);

for(int i =0; i < 10000 ; i ++){
    char abc[] = "  Hello    bye   my name is !!!!!";
    remSpace1(abc);
}
    
gettimeofday(&tv2, NULL);

printf ("Total time = %f seconds\n",
         (double) (tv2.tv_usec - tv1.tv_usec)+
        ( (double) (tv2.tv_sec - tv1.tv_sec) * 1000000 ));
         
gettimeofday(&tv1, NULL);

for(int i =0; i < 10000 ; i ++){
    char abc[] = "  Hello    bye   my name is !!!!!";
    remSpace2(abc);
}
    
gettimeofday(&tv2, NULL);

printf ("Total time = %f microseconds\n",
         (double) (tv2.tv_usec - tv1.tv_usec)+
        ( (double) (tv2.tv_sec - tv1.tv_sec) * 1000000 ));
         
         
    return 0;
}
