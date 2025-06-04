//SUM OF SUBSET PROBLEM
#include<stdio.h>
#include<stdbool.h>

bool subset(int set[], int n, int sum)
{
    if(sum==0)
        return true;
    if(n==0)
        return false;
    if(set[n-1]>sum)
        return
             subset(set, n-1,sum);
   return
       subset(set,n-1, sum)||subset(set, n-1, sum-set[n-1]);
}

int main()
 {
     int set[10],sum,n,i;
     printf("\nenter number of elements\n");
     scanf("%d", &n);
     printf("\nenter the set elements\n");
     for(i=0;i<n;i++)
        scanf("%d", &set[i]);
     printf("\n enter the sum\n");
        scanf("%d", &sum);
    if(subset(set,n,sum)==true)
        printf("set found");
        else
            printf("set not found");
     return 0;
 }
