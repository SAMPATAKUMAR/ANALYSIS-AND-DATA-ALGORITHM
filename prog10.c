#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int count=0;
int partition(int a[], int low,int high)
{
int pivot=a[low],temp,i=low+1,j=high; while(1)
{
//Traverse i from left to right, segregating element of left group
while(i<=high && a[i]<=pivot)            //a[i]<=pivot used for avoiding multiple duplicates
{
i++;
count++;
}
//Traverse j from right to left, segregating element of right group
while(j>0 && a[j]>pivot)
{
j--; count++;
}
count+=2;
//If grouping is incomplete
if(i<j)
{
temp = a[i]; a[i] = a[j]; a[j] =temp;
}
else if(i>j)//If grouping is completed
{
temp = a[low]; a[low] = a[j]; a[j] = temp; return j;
}
else //Duplicate of Pivot found
    return j;
}
}
void quicksort(int a[],int low, int high)
{
int s;
if(low<high)
{
//partition to place pivot element in between left and right group
s = partition(a,low,high);
quicksort(a,low,s-1); quicksort(a,s+1,high);
}
}

int main()
{
int a[10000],n, i;
printf("Enter the number of elements in an array:"); scanf("%d",&n);
printf("All the elements:"); srand(time(0));
for( i=0;i<n;i++)
{
a[i]=rand();
printf("%d ",a[i]);
}
clock_t t;
t=clock();
quicksort(a,0,n-1);
t=clock()-t;
double time_taken=(double)t/CLOCKS_PER_SEC;
printf("\ntime taken by sorting=%f\n", time_taken);
getchar();
/*printf("\nAfter sorting\n");
for( i=0;i<n;i++)
printf("%d ", a[i]);
printf("\nNumber of basic operations = %d\n",count);*/
}

/* get the following values
  N          time
5000
6000
7000
8000
9000
10000              */

