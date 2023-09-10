#include <stdio.h>
#include <stdlib.h>

#define MAX 50

typedef struct LIST {
	int num; //So nut hien co trong danh sach
	int nodes[MAX];//Moi nut cua danh sach la mot phan tu tren array
} list;

//Khoi dong danh sach ke
void Init(list *l) {
	l->num = 0;
}

//Xac dinh so nut trong danh sac
int ListSize(list *l) {
	return l->num;
}

//Kiem tra danh sach co empty khong
int Empty(list *l) {
	return (l->num == 0 ? 1 : 0);
}

void append(list *l, int x) {
	if(!Full(l)) {
		l->nodes[l->num] = x;
		(l->num)++;
	}
	else
		printf("Danh sach day!\n");
}

//Kiem tra danh sach co full khong
int Full(list *l) {
	return (l->num == MAX ? 1 : 0);
}

//Add mot nut vao danh sach
void Insert(list *l, int pos, int x) {
	int i;
	if(pos < 0 || pos > l->num) 
		printf("Vi tri %d khong hop le!\n", pos);
	else if(Full(l))
		printf("Danh sach bi day!\n");
	else {
		//Doi cac nut tu vi tri num-1 den vi tri pos xuong 1 vi tri
		for(i = l->num-1; i>=pos; i--) 
			l->nodes[i+1] = l->nodes[i];
		l->nodes[pos] = x;//Them x vao vi tri cua pos
		l->num++; //Tang so luong nut len 1
	}
}

//Delete mot nut ra khoi danh sach
int Remove(list *l, int pos) {
	int i, x;
	if(pos < 0 || pos > l->num) {
		printf("Vi tri %d khong hop le!\n", pos);
		return -1;
	}
	else if(Empty(l)) {
		printf("Danh sach bi rong!\n");
		return -2;
	}
	else {
		x = l->nodes[pos];
		//Doi cac nut tu vi tri pos+1 den vi tri num-1 len 1 vi tri
		for(i = pos; i < l->num-1; i++)
			l->nodes[i] = l->nodes[i+1];
		l->num--;//Giam so nut di 1 nut
		return x;
	}
}

void Replace(list *l, int pos, int x) {
	if(Empty(l))
		printf("Danh sach bi rong!\n");
	else if(pos < 0 || pos > l->num)
		printf("Vi tri %d khong hop le!\n", pos);
	else 
		l->nodes[pos] = x;
}

void HoanVi(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp; 
}

//Sap xep danh sach tang dan
void QuickSort(list *l, int left, int right)
{
	int i,j,x;
	x= l->nodes[(left+right)/2];
	i=left, j=right;
	do
	{
		while(l->nodes[i] < x) i++;
		while(l->nodes[j] > x) j--;
		if(i<=j)
		{
			HoanVi(&(l->nodes[i]), &(l->nodes[j]));
			i++; j--;
		}
	}while(i < j);
	if(left < j) QuickSort(l, left, j);
	if(i < right) QuickSort(l, i, right);
}

//Tim kiem nhi phan phan tu x 
int BinarySearch(list *l,int x) {
	int dau = 0;
	int cuoi = l->num-1;
	int giua;
	while(dau <= cuoi) {
		giua = (dau + cuoi) / 2;
		if(x == l->nodes[giua])
			return giua;//Tim thay tai vi tri giua
		if(x < l->nodes[giua])
			cuoi = giua -1;
		else 
			dau = giua + 1;
	}
	return -1;
}

//Duyet qua tat ca cac phan tu cua danh sach
void Traverse(list *l) {
	if(Empty(l))
		printf("Danh sach rong!\n");
	else {
		int i;
		for(i = 0; i < l->num; i++)
			printf("%d ", l->nodes[i]);
		printf("\n");
	}
}

//Del tat ca cac nut trong danh sach
void ClearList(list *l) {
	l->num = 0;
}

int main()
{
	list l;
	Init(&l);
	int x, pos;
	//Nhap cac phan tu vao list
	do{
		printf("Nhap phan tu thu %d cua danh sach: ",l.num);
		scanf("%d", &x);
		if(x!=0)
			append(&l, x);
	}while(x!=0);
	//Show phan tu
	printf("Danh sach sau khi nhap:\n");
	Traverse(&l);
	
	//Tim phan tu co gia tri x
	QuickSort(&l, 0, l.num-1);
	printf("Danh sach sau khi sap xep la:\n");
	Traverse(&l);
	printf("Nhap gia tri cua phan tu can tim:");
	scanf("%d", &x);
	printf("Vi tri cua phan tu can tim la: %d\n", BinarySearch(&l,x));
	
	return 0;
}
