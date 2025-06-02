#include<stdio.h>
#include<math.h>
#include<stdlib.h>	//for abs() function
int i, j;
int place(int x[],int k)
{
  for(i=1;i<k;i++)
   {
     if( (x[i] == x[k]) || ( abs(x[i]-x[k]) == abs(i-k)) )
        return 0;
   }
     return 1; //feasible
}
int nqueens(int n)
{
   int x[10], k, count=0;
   k=1;// select the first queen
   x[k]=0; //no positions allocated
 while(k != 0) // until all queens are present
 {
  x[k]++;	// place the kth queen in next column
  while((x[k] <= n) && (!place(x,k)))
  x[k]++;	// check for the next column to place queen
  if(x[k] <= n)
   {
     if(k == n) // all queens are placed
        {
          printf("\nSolution %d\n",++count);
          for(i=1;i <= n;i++)
            {
              for(j=1;j <= n;j++)
               printf("%c\t ",  j==x[i]? 'Q': '*');
               printf("\n\n");
            }
        }
     else
       {
           ++k;	//select the next queen
           x[k]=0;	// start from the next column
       }
   }
    else
       k--;	// backtrack
  }
     return count;
}

void main()
{
    int n;
    printf("Enter the size of chessboard: ");
    scanf("%d",&n);
    printf("\nThe number of possibilities are %d",nqueens(n));
}
