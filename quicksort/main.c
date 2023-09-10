#include <stdio.h>
#include <string.h>

void HoanVi(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp; 
}

void QuickSort(int a[], int left, int right)
{
	int i,j,x;
	x=a[(left+right)/2];
	i=left, j=right;
	do
	{
		while(a[i]<x) i++;
		while(a[j]>x) j--;
		if(i<=j)
		{
			HoanVi(&a[i], &a[j]);
			i++; j--;
		}
	}while(i<j);
	if(left<j) QuickSort(a, left, j);
	if(i<right) QuickSort(a, i, right);
}

int main()
{
	int arr[] = {15, 7,9, 10, 6, 20, 6, 9, 12, 30};
	int N = sizeof(arr) / sizeof(arr[0]);
	
	printf("Array before sorting:\n");
	int i;
	for(i=0;i<N;i++)
		printf("%d ",arr[i]);
	printf("\n");
	
	QuickSort(arr, 0, N-1);
	
	printf("Array after sorting:\n");
	for(i=0;i<N;i++)
		printf("%d ",arr[i]);
	printf("\n");
	
	return 0;
}
