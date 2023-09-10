#include <stdio.h>
#include <stdlib.h>

struct ttNode
{
	int data;
	struct ttNode *pNext;
};
typedef struct ttNode Node;

struct ttList
{
	Node *pHead,*pTail	
};
typedef struct ttList List;

void init(List *l)
{
	l->pHead = l->pTail = NULL;
	
}

int isEmpty(List *l)
{
	return (l->pHead == NULL && l->pTail == NULL)?1:0;
}

void addHead(List *l,Node *pNew)
{
	if(isEmpty(l))
	{
		l->pHead = l-> pTail = pNew;
	}	
	else
	{
		pNew->pNext = l->pHead;
		l->pHead = pNew;
	}
}

void addTail(List *l,Node *pNew)
{
	if(isEmpty(l))
	{
		l->pHead = l->pTail = pNew;
	}
	else
	{
		l->pTail->pNext = pNew;
		l->pTail = pNew;
	}
}

Node* createNode(int x)
{
	Node *p;
	p = (Node *)malloc(sizeof(Node));
	if(p==NULL)
	{
		printf("Out of storage!\n");
	}
	p->data = x;
	p->pNext=NULL;
	return p;
}

void ThemXVaoSauMax(List *l,Node x)
{
	Node pNew = createNode(x);
	Node *tmp = l->pHead;
	//tim max
	Node *pMax;
	int max = l->pHead->data;
	while(tmp != NULL)
	{
		if(tmp->data > max)
		{
			max = tmp->data;
			pMax = tmp;
		}
		tmp = tmp->pNext;
	}
	//tao node max va gan gia tri sau max
	if(l->pTail == pMax)
	{
		addTail(l, pNew);
	}
	else
	{
		Node *pSau = pMax->pNext;
		pNew->pNext = pSau;
		pMax->pNext = pNew;
	}
}

Node *PrevNodeP(List list, Node *p)
{
	
}



void Output(const List *list)
{
	Node *p = list->pHead;
	while(p!=NULL)
	{
		printf("%d\t",p->data);
		p = p->pNext;
	}
	printf("\n");
}

int main(void) 
{
	List ds;
	init(&ds);
	int x;
	Node* pNew;
	do
	{
		printf("Enter varible: ");
		scanf("%d",&x);
		if(x != 0)
		{
			pNew = createNode(x);
			if(pNew != NULL)
			{
				addHead(&ds,pNew);
			}
		}
	}while(x!=0);
	printf("List after adding: \n");
	Output(&ds);
	return 0;	
}