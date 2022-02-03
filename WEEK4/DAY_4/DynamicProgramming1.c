
// Online IDE - Code Editor, Compiler, Interpreter

#include <stdio.h>
#include <stdlib.h>

#define BIG_NUMBER 10000

void setTheValues(int,int*);
void inputValues(int, int*);

int
main()
{
/* w is for small weights*/
/* v is to keep the track of what have we added*/
/* p is to keep track of previous values */
/* min is for minimum number of small weights that would keep sub problems */
int *w,*v,*p,*min;

/* e is to stop the screen */
/* s is the weight we need to reach */
/* n is the number of coins*/
int  e, s, n;

printf("Input the number of small weights->");
scanf("%d",&n);

w=(int*)calloc((n+1),sizeof(int));
v=(int*)calloc((n+1),sizeof(int));
p=(int*)calloc((n+1),sizeof(int));
min=(int*)calloc((n+1),sizeof(int));

printf("Input the big weight to reach->");
scanf("%d",&s);

setTheValues(s,min);

inputValues(n,w);

for(int i=1; i<=s; i++)
  for(int j=0; j<n; j++)
       if(w[j]<=i)
	      if(min[i-w[j]]+1<min[i])
		  {
			  min[i]=min[i-w[j]]+1;
			  v[i]=w[j];
			  p[i]=i-w[j];
		  }

printf("\nThe minmum number of small weights is=%d\n",min[s]);

printf("\nWe have added this small weights!!!\n\n");

for(int j=s; j>0;j=p[j])
	printf("%d+",v[j]);

scanf("%d",&e);

free(w);free(v);free(p);free(min);

return 0;
}

void 
setTheValues(int s, int* min)
{
	*min=0;
	for(int i=1; i<=s;*(min+i)=BIG_NUMBER,i++);	
}

void inputValues( int n, int* w)
{
   int temp;
   printf("Input the values of weights\n");
   *w=1;
  for(int i=1; i<n; i++)
   {
     printf("\nNext value pleas->");
     scanf("%d",&temp);
     *(w+i)=temp;
   }
}