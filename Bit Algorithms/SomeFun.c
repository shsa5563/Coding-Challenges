/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#define CHAR_BIT 8
int main()
{/*
 0000 0000  0000 0000  0000 0000  0000 0000
                                   1
        1      

    int v = -256;           // we want to find the absolute value of v
unsigned int r;  // the result goes here 
int const mask = v >> sizeof(int) * CHAR_BIT - 1;
int a = -170;
printf("%x %d \n", a,a);
a = a>> 1; 
printf("%x %d", a, a);


r = (v + mask) ^ mask;
printf("\n%d %d %x", r, v, mask);
r = (v ^ mask) - mask;
printf("\n%d %d", r, v);*/

int num = 64; 
printf("%x\n", num&(-num));

num = ((num >> 1) & (0x55555555)) | (( num & (0x55555555) ) <<1);
num = ((num >> 2) & (0x33333333)) | (( num & (0x33333333) ) <<2);
num = ((num >> 4) & (0x0F0F0F0F)) | (( num & (0x0F0F0F0F) ) <<4);
num = ((num >> 8) & (0x00FF00FF)) | (( num & (0x00FF00FF) ) <<8);
num = (num >> 16) | (num  <<16);
printf("%x", num);
}
