#include <iostream>
using namespace std;

struct Node								//khai bao cau truc danh sach 
{
	int info;
	Node *next,
		*previous;
};

Node *first, *last;

void init()								//khoi tao danh sach rong
{
	first = NULL;
	last = NULL;
}

void output()							//xuat danh sach
{
	Node *p;
	p = first;
	while (p != NULL)
	{
		cout << p->info << endl;
		p = p->next;
	}
}

void insert_first(int x)				//them dau danh sach
{
	Node *p;
	p = new Node;
	p->info = x;
	p->next = first;
	p->previous = NULL;
	if (first != NULL)
		first->previous = p;
	else
		last = p;
	first = p;
}

void insert_last(int x)					//them cuoi danh sach
{
	Node *p;
	p = new Node;
	p->info = x;
	p->next = NULL;
	p->previous = last;
	if (last != NULL)
		last->next = p;
	else
		first = p;
	last = p;
}

int delete_first()						//xoa phan tu dau danh sach
{
	if (first != NULL)
	{
		Node *p = first;
		first = first->next;
		delete p;
		if (first != NULL)
			first->previous = NULL;
		else
			last = NULL;
		return 1;
	}
	return 0;
}

int delete_last()						//xoa phan tu cuoi danh sach
{
	if (last != NULL)
	{
		Node *p = last;
		last = last->previous;
		if (last != NULL)				//TH ds khac rong~ nao`
			last->next = NULL;
		else
			first = NULL;				//TH ds khong con phan tu nao
		delete p;
		return 1;
	}
	return 0;
}

Node *search(int x)					//tim kiem phan tu x
{
	Node *p;
	p = first;
	while ((p != NULL)) && (p->info != x))
	p = p->next;
	return p;
}

int del(int x)
{
	Node *p = search(x);
	if (p != NULL)
	{
		if (p == first())
		{
			if (delete_first())
				return 1;
			else
				return 0;
		}
		else if (p == last)
		{
			if (delete_last())
				return 1;
			else
				return 0;
		}
		else
		{
			Node *q;
			q = p->previous;
			q->next = p->next;
			(p->next)->previous = q;
			delete p;
			return 1;
		}
	}
	return 0;
}

int main()
{
	char tt;
	int chon;
	do {
		cout << "1. Khai bao\n2. Khoi tao\n3. Xuat phan tu\n4. Them vao dau danh sach\n5. Them vao cuoi danh sach\n6. Xoa phan tu dau ds\n7. Xoa phan tu cuoi ds\n8. Tim phan tu trong ds va xoa\nBan chon: \n";
		cin >> chon;
		switch (chon)
		{
		case 1:
			cout << "Khai bao ds lk doi thanh cong\n";
			break;
		case 2:
			break;
		}
	}
}