#include <stdio.h>

#define MAX 100

int b[MAX], c[MAX], nb, nc;

int min(int a, int b) 
{
	return (a>b)? b : a;
}

void Distribute(int a[],int N,int *nb, int *nc,int k) 
{
	int i,pa,pb,pc;
	pa=pb=pc=0;
	while(pa<N) 
	{
		for(i=0;(pa<N)&&(i<k);i++,pa++,pb++)
			b[pb]=a[pa];
		for(i=0;(pa<N)&&(i<k);i++,pa++,pc++)
			c[pc]=a[pa];
	}
	*nb=pb; *nc=pc;
}

void Merge(int a[],int nb,int nc,int k) 
{
	int p,pb,pc,ib,ic,kb,kc;
	p=pb=pc=0;
	ib=ic=0;
	while((nb>0)&&(nc>0)) 
	{
		kb=min(k,nb);
		kc=min(k,nc);
		if(b[pb+ib]<=c[pc+ic])
	 	{
			a[p++]=b[pb+ib];
			ib++;
			if(ib==kb) 
			{
				for(;ic<kc;ic++)
					a[p++]=c[pc+ic];
				pb+=kb; pc+=kc;
				ib=ic=0;
				nb-=kb; nc-=kc;
			}
	 	}
		else
		{
			a[p++]=c[pc+ic]; ic++;
			if(ic==kc)
			{
				for(;ib<kb;ib++)
					a[p++]=b[pb+ib];
				pb+=kb; pc+=kc; ib=ic=0;
				nb-=kb; nc-=kc;
			}
		}
 	}
}

void MergeSort(int a[],int N) 
{
	int k;
	for(k=1;k<N;k*=2) 
	{
		Distribute(a,N,&nb,&nc,k);
		Merge(a,nb,nc,k);
	}
}

int main()
{
	int arr[] = {8,23,74,17,9,43,36};
	int N = sizeof(arr) / sizeof(arr[0]);
	printf("Array before sorting:\n");
	int i;
	for(i=0;i<N;i++)
		printf("%d ", arr[i]);
	printf("\n");
	MergeSort(arr,N);
	printf("Array after sorting:\n");
	for(i=0;i<N;i++)
		printf("%d ",arr[i]);
	printf("\n");
	return 0;
}
