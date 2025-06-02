//This program for selection sort time calculation
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int a[10000],n,count,i,j;
void selection_sort()
{
for( i=0;i<n-1;i++)
{
int min = i;
for(j=i+1;j<n;j++)
{
count++;
if(a[j]<a[min])
min=j;
}
int temp=a[i]; a[i]=a[min]; a[min]=temp;
}
}

int main()
{
printf("Enter the number of elements in an array:");
scanf("%d",&n);
printf("All the elements:"); 
for(i=0;i<n;i++)
{
a[i]=rand();
printf("%d ",a[i]);
}
clock_t t;
t=clock();
selection_sort();
t=clock()-t;
double time_taken=(double)t/CLOCKS_PER_SEC;
getchar();
printf("\ntime taken by sorting=%f\n", time_taken);
//printf("\nAfter sorting\n");
//for(i=0;i<n;i++)
//printf("%d ", a[i]);----
//printf("\nNumber of basic operations = %d\n",count);
}

/* get the following values
  N                                        time
1000
2000
3000
4000
5000
6000
7000
8000
9000
10000              */
