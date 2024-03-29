﻿//bai tap 4 _bai lam them
#include <iostream>
using namespace std;

//4.1 khai bao cau truc danh sach
struct Node
{
	int info;
	Node* link;
};
//4.2 Khoi tao danh sach rong
Node* first;
void Init()
{
	first = NULL;
}
//4.3 Them phan tu vao danh sach
void Insert(int x)
{
	Node* p;
	p = new Node;
	p->info = x;
	p->link = first;
	first = p;
}

void Inserts(int x)
{
	Node* p, * q, * before;
	p = new Node;
	p->info = x;
	q = first;
	while (q != NULL && q->info > x)
	{
		before = q;
		q = q->link;
	}
	if (q == first)
		first = p;
	else
		before->link = p;
	p->link = q;
}
// 4.4 Xuat cac phan tu trong danh sach
void process_list()
{
	Node* p;
	p = first;
	while (p != NULL)
	{
		cout << p->info << "\t";
		p = p->link;
	}
	cout << endl;
}

// 4.5 Tim mot phan tu trong danh sach
Node* Search(int x)
{
	Node* p = first;
	while (p != NULL && p->info != x)
	{
		p = p->link;
	}
	return p;
}

int del_f()
{
	if (first != NULL)
	{
		Node* p = first;
		first = first->link;
		delete p;
		return 1;
	}
	return 0;
}

int del_l()
{
	if (first != NULL)
	{
		Node* p, * q;
		p = first;
		q = first;
		while (p->link != NULL)
		{
			q = p;
			p = p->link;
		}
		if (p != first)
			q->link = NULL;
		else
			first = NULL;
		delete p;
		return 1;
	}
	return 0;
}
// 4.6 Tim va xoa phan tu neu co
int Search_Del(int x)
{
	if (Search(x) != NULL)
	{
		Node* t = Search(x);
		if (t == first)
		{
			if (del_f())
				return 1;
		}
		else
			if (t->link == NULL)
			{
				if (del_l())
					return 1;
			}
			else
			{
				Node* q = first, * p = first;
				while (p != t)
				{
					q = p;
					p = p->link;
				}
				q->link = t->link;
				delete t;
				return 1;
			}
	}
}

int main()
{
	int choice = 0;
	int x, i;
	Node* p;
	Insert(1);
	Insert(4);
	Insert(6);
	Insert(8);
	Insert(9);
	Insert(11);
	system("cls");
	cout << "-------BAI TAP 4 CHUONG 2------" << endl;
	cout << "1.Khoi tao ds rong" << endl;
	cout << "2.Them 1 phan tu vao vi tri phu hop" << endl;
	cout << "3.Xuat ds" << endl;
	cout << "4.Tim 1 phan tu trong danh sach" << endl;
	cout << "5.Tim va xoa 1 phan tu trong danh sach" << endl;
	cout << "6.Thoat " << endl;
	do {
		cout << "Vui long chon so de thuc hien: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			Init();
			cout << "Ban vua khoi tao danh sach rong thanh cong! " << endl;
			break;
		case 2:
			cout << "Nhap phan tu can them: ";
			cin >> x;
			Inserts(x);
			cout << "Danh sach sau khi them phan tu vao vi tri phu hop la: ";
			process_list();
			break;
		case 3:
			cout << "Danh sach hien tai la: ";
			process_list();
			break;
		case 4:
			cout << "Vui long nhap gia tri can tim ";
			cin >> x;
			p = Search(x);
			if (p != NULL)
				cout << "Tim thay phan tu co gia tri x = " << x << endl;
			else
				cout << "Khong tim thay phan tu co gia tri x = " << x << endl;
			break;
		case 5:
			cout << "Nhap gia tri x: ";
			cin >> x;
			i = Search_Del(x);
			if (i == 1)
			{
				cout << "Tim thay x = " << x << " va da xoa thanh cong " << endl;
				cout << "Danh sach sau khi xoa: ";
				process_list();
			}
			else
				cout << "Khong tim thay phan tu co gia tri x = " << x << endl;
			break;
		case 6:
			cout << "Goodbye.....!" << endl;
			break;
		default:
			break;
		}
	} while (choice != 6);
	return 0;
}