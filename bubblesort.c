#include<stdbool.h>
#include<stdio.h>
void swap(int*xp,int*yp)
{
	int temp=*xp;
	*xp=*yp;
	*yp=temp;
}
void bubblesort(int arr[],int n)
{
	int i,j;
	bool swapped;
	for (i=0;j<-1;i++)
	{
	swapped=false;
	for(j=0;j<n-1-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				swap(&arr[j],&arr[j+1]);
				swapped=true;
			}
		}
		if(swapped==false)
		break;
	}
}
void printArray(int arr[],int size)
{
	int i;
	for (i=0;i<size;i++)
	printf("%d",arr[i]);
}
int main()
{
	int arr[]={64,34,25,12,22,11,90};
	int n=sizeof(arr)/sizeof(arr[0]);
	bubblesort(arr,n);
	printf("sorted array:\n");
	printArray(arr,n);
	return 0;
}
