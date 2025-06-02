#include <stdio.h>
 void discknapsack(int n, float w[],float p[],float rc);
 void contknapsack(int n, float w[],float p[],float rc);	
	int main()
	{
		int n;
	    float w[10];
	    float p[10];
	    float c;
	    int i,j;
		float pw[10],Tot_p,temp;
		
		printf("Enter the number of items\n");
		scanf("%d",&n);
		printf("Enter the weights of items\n");
		for(i=0;i<n;i++)
		  scanf("%f",&w[i]);
		printf("Enter the values of items\n");
		for(i=0;i<n;i++)
		  scanf("%f",&p[i]);
	    printf("Enter the Capacity\n");
		scanf("%f",&c); 
		
		for(i=0;i<n;i++)
			pw[i]=(float)p[i]/w[i];
			
		for(i=0;i<n-1;i++)
         for(j=0;j<n-i-1;j++)
			if(pw[j]<pw[j+1])
			{
				temp=pw[j];
				pw[j]=pw[j+1];
				pw[j+1]=temp;

				temp=w[j];
				w[j]=w[j+1];
				w[j+1]=temp;

				temp=p[j];
				p[j]=p[j+1];
				p[j+1]=temp;
			}
			
		printf("\nAfter sorting Ratio\n");	
		for(i=0;i<n;i++)
		  printf("%f\t",pw[i]);
	
		printf("\nAfter sorting weights as per Ratio array\n");	
		for(i=0;i<n;i++)
		    printf("%f\t",w[i]);
		    
		printf("\nAfter sorting profit as per Ratio array\n");	
		for(i=0;i<n;i++)
		    printf("%f\t",p[i]);
		    
		printf("\nDiscrete Knapsack\n");     
		 discknapsack(n,w,p,c);  
	 	printf("\nContinuous Knapsack\n");  
		 contknapsack(n,w,p,c);
		 
		 return(0);
	}
 		
	void discknapsack(int n, float w[],float p[],float rc)
		{
		 int x[10];
		 int i,j;
		 float Tot_p;
		for(i=0;i<n;i++)
                    x[i]=0;
		for(i=0;i<n;i++)
		{
			if (w[i]>rc)
				break;
			x[i]=1;
			Tot_p+=p[i];
			rc=rc-w[i];
		}
		printf("\nItem selected are\n");
		for(i=0;i<n;i++)
			printf("%d\t",x[i]);
		
		printf("\nThe Maximum profit is %f\n",Tot_p);
        }
    void contknapsack(int n, float w[],float p[],float rc)
		{
		 float x[10];
		 int i,j;
		 float Tot_p;
		for(i=0;i<n;i++)
                    x[i]=0;
		for(i=0;i<n;i++)
		{
			if (w[i]>rc)
				break;
			x[i]=1;
			Tot_p+=p[i];
			rc=rc-w[i];
		}
		if(i<=n)
		    x[i]=rc/w[i];
		    
		Tot_p=Tot_p+(x[i]*p[i]);
		
		printf("\nItem selected are\n");
		for(i=0;i<n;i++)
			printf("%f\t",x[i]);
		
		printf("\nThe Maximum profit is %f\n",Tot_p);
        }
