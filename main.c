#include <stdio.h>
#include <time.h>
#include <stdlib.h>
typedef struct BSTnode
{
	int bdata;
	struct BSTnode *bleft, *bright;
}bst;
bst *broot=NULL;
int ascarr[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};
	int descarr[]={25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
	int randarr[]={5,3,12,13,22,15,9,3,8,7,16,19,20,24,1,18,17,133,4,22,11,23,12,21,45};
	
void insertbst(int key)
{
	bst *p , *q , *r;
	r=(bst *)malloc(sizeof(bst));
	r->bdata=key;
	r->bleft=r->bright=NULL;
	if(broot==NULL)
	{
		broot=r;
	}
	else
	{
		p=broot;
		while(p!=NULL)
		{
			q=p;
			if(key>p->bdata)
			{
				p=p->bright;
			}
			else
			{
				p=p->bleft;
			}
		}
		if(key>q->bdata)
		{
			q->bright=r;
		}
		else
		{
			q->bleft=r;
		}
	}
}
void bstsearch(int key)
{	
	bst *p=broot;
	while(p->bdata!=key)
	{
		if(key<p->bdata)
		{
			p=p->bleft;
		}
		else
		{
			p=p->bright;
		}
	}
}
void binaryst()
{
	clock_t bstart, bend, bstart2, bend2,bstarts,bends;
	int i;
	double asctotal, desctotal, randtotal,asctotals,desctotals,randtotals;
	printf("\t\t\tBINARY SEARCH TREE\n\n");
	printf("The computer will generate a set of 25 numbers to demonstrate time complexity of Binary Search Tree\n\n");
	//ascending
	bstart=clock();
	for(i=0;i<25;i++)
	{
		insertbst(ascarr[i]);
	}
	bend=clock();
	asctotal = (double)(bend - bstart)*1000000 / CLOCKS_PER_SEC;
	printf("\tASCENDING ARRAY:\n Insertion Time:%f x10^-6 seconds\n",asctotal);
	bstarts=clock();
	bstsearch(1);
	bends=clock();
	asctotals = (double)(bends - bstarts)*1000000 / CLOCKS_PER_SEC;
	printf("Time taken to search smallest element:\t%f x10^-6 seconds\n",asctotals);
	bstarts=clock();
	bstsearch(25);
	bends=clock();
	asctotals = (double)(bends - bstarts)*1000000 / CLOCKS_PER_SEC;
	printf("Time taken to search largest element:\t%f x10^-6 seconds\n\n",asctotals);
	broot=NULL;
	//descending
	bstart2=clock();
	for(i=0;i<25;i++)
	{
		insertbst(descarr[i]);
	}
	bend2=clock();
	desctotal = (double)(bend2 - bstart2)*1000000 / CLOCKS_PER_SEC;
	printf("\tDESCENDING ARRAY:\n Insertion Time:%f x10^-6 seconds\n",desctotal);
	bstarts=clock();
	bstsearch(1);
	bends=clock();
	desctotals=(double)(bends - bstarts)*1000000 / CLOCKS_PER_SEC;
	printf("Time taken to search for the smallest number: %f x10^-6 seconds\n",desctotals);
	bstarts=clock();
	bstsearch(25);
	bends=clock();
	desctotals=(double)(bends - bstarts)*1000000 / CLOCKS_PER_SEC;
	printf("Time taken to search for the largest number: %f x10^-6 seconds\n\n",desctotals);
	//random
	broot=NULL;
	bstart=clock();
	for(i=0;i<25;i++)
	{
		insertbst(randarr[i]);
	}
	bend=clock();
	randtotal = (double)(bend - bstart)*1000000 / CLOCKS_PER_SEC;
	printf("\tRANDOM ARRAY:\n Insertion Time:%f x10^-6 seconds\n",randtotal);
	bstarts=clock();
	bstsearch(1);
	bends=clock();
	randtotals=(double)(bends - bstarts)*1000000 / CLOCKS_PER_SEC;
	printf("Time taken to search the smallest element: %f x10^-6 seconds\n",randtotals);
	bstarts=clock();
	bstsearch(133);
	bends=clock();
	randtotals=(double)(bends - bstarts)*1000000 / CLOCKS_PER_SEC;
	printf("The time taken to search the largest element: %f x10^-6 seconds\n\n",randtotals);
	
}
//heap tree
void heapify(int arr[],int i)
{
	int parent=(i-1)/2;
	int temp;
	if(arr[parent]>0)
	{ 
		if(arr[i]>arr[parent])
		{
      temp=arr[i];
			arr[i]=arr[parent];
			arr[parent]=temp;
			heapify(arr,parent);
		}
	}
}
void minheapify(int arr[],int i)
{
	int parent=(i-1)/2;
	int temp;
	if(arr[parent]>0)
	{ 
		if(arr[i]<arr[parent])
		{
      temp=arr[i];
			arr[i]=arr[parent];
			arr[parent]=temp;
			minheapify(arr,parent);
		}
	}
}
void heap()
{
	clock_t start, end;
	double total;
	int i, heap[25], dheap[25], rheap[25];
	printf("\t\t\tMAX HEAP TREE\n\n");
	printf("The computer will generate a set of 25 numbers to demonstrate time complexity of Max Heap Tree\n\n");
	printf("The Insertion times are:\n");
	start=clock();
	for(i=0;i<25;i++)
	{
		heap[i]=ascarr[i];
		heapify(heap, i);
	}
	end=clock();
	total=(double)(end - start)*1000000 / CLOCKS_PER_SEC;
	printf("ASCENDING ARRAY:   %f x10^-6 seconds\n", total);
	//descending
	start=clock();
	for(i=0;i<25;i++)
	{
		dheap[i]=descarr[i];
		heapify(dheap, i);
	}
	end=clock();
	total=(double)(end - start)*1000000 / CLOCKS_PER_SEC;
	printf("DESCENDING ARRAY:   %f x10^-6 seconds\n", total);
	//random
	start=clock();
	for(i=0;i<25;i++)
	{
		rheap[i]=randarr[i];
		heapify(rheap, i);
	}
	end=clock();
	total=(double)(end - start)*1000000 / CLOCKS_PER_SEC;
	printf("RANDOM ARRAY:   %f x10^-6 seconds\n\n", total);
	
}
void minheap()
{
	clock_t start, end;
	double total;
	int i, heap[25], dheap[25], rheap[25];
	printf("\t\t\tMIN HEAP TREE\n\n");
	printf("The computer will generate a set of 25 numbers to demonstrate time complexity of Min Heap Tree\n\n");
	printf("The Insertion times are:\n");
	start=clock();
	for(i=0;i<25;i++)
	{
		heap[i]=ascarr[i];
		minheapify(heap, i);
	}
	end=clock();
	total=(double)(end - start)*1000000 / CLOCKS_PER_SEC;
	printf("ASCENDING ARRAY:   %f x10^-6 seconds\n", total);
	//descending
	start=clock();
	for(i=0;i<25;i++)
	{
		dheap[i]=descarr[i];
		minheapify(dheap, i);
	}
	end=clock();
	total=(double)(end - start)*1000000 / CLOCKS_PER_SEC;
	printf("DESCENDING ARRAY:   %f x10^-6 seconds\n", total);
	//random
	start=clock();
	for(i=0;i<25;i++)
	{
		rheap[i]=randarr[i];
		minheapify(rheap, i);
	}
	end=clock();
	total=(double)(end - start)*1000000 / CLOCKS_PER_SEC;
	printf("RANDOM ARRAY:   %f x10^-6 seconds\n\n", total);
	
}

int main(void) 
{
  int ch;
	printf("\t\t\tANALYSIS OF TIME COMPLEXITY\n");
	printf("----------------------------------------------------------------------------------------------------\n");
	do
	{
		printf("Enter: \n1)Binary Search Tree\n2)Minimum Heap Tree\n3)Maximum Heap Tree\n4)Exit\n");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1:
				binaryst();
				break;
			case 2:
				minheap();
				break;
			case 3:
				heap();
				break;
			case 4:
				break;
			default:
				printf("Invalid option\n");
		}
	}while(ch!=4);
}