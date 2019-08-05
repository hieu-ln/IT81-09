#include <iostream>
using namespace std;

#define COUNT 5
//1.1
struct node{
	int info;
	node *left, *right;
};
node *root;
//1.2
void init()
{
	root = NULL;
}
//1.3
void insert(node *&p, int x)
{
	if (p == NULL)
	{
		p = new node;
		p->info = x;
		p->left = NULL;
		p->right = NULL;
	}
	else
		if (p->info == x)
			return;
		else
			if (p->info > x)
				return insert(p->left, x);
			else
				return insert(p->right, x);
}
//1.4
int search(node *p, int x)
{
	if (p != NULL)
		if (p->info == x)
			return 1;
		else
			if (p->info > x)
				return search(p->right, x);
			else
				return search(p->left, x);
	return 0;
}
//1.5
void searchStandFor(node *&p, node *&q)
{
	if (q->left == NULL)
	{
		p->info = q->info;
		p = q;
		q = q->right;
	}
	else
		searchStandFor(p, q->left);
}
int deleteNode(node *&T, int x)
{
	if (T == NULL)
		return 0;
	if (T->info == x)
	{
		node *p = T;
		if (T->left == NULL)
			T = T->right;
		else
			if (T->right == NULL)
				T = T->left;
			else
				searchStandFor(p, T->right);
		delete p;
		return 1;
	}
	if (T->info < x)
		return deleteNode(T->right, x);
	if (T->info > x)
		return deleteNode(T->left, x);
}
//1.6
void duyetNLR(node *p)
{
	if (p != NULL)
	{
		cout << p->info;
		duyetNLR(p->left);
		duyetNLR(p->right);
	}
}
//1.7
void duyetLNR(node *p)
{
	if (p != NULL)
	{
		duyetLNR(p->left);
		cout << p->info;
		duyetLNR(p->right);
	}
}
//1.8
void duyetLRN(node *p)
{
	if (p != NULL)
	{
		duyetLRN(p->left);
		duyetLRN(p->right);
		cout << p->info;
	}
}
//output tree
void output(node *p, int space)
{
	if (p == NULL)
		return;
	space += COUNT;
	output(p->right, space);
	cout << endl;
	for (int i = COUNT; i < space; i++)
		cout << " ";
	cout << p->info << endl;
	output(p->left, space);
}
void outputTree()
{
	output(root, 0);
}
//menu
void menu()
{
	cout << "------BAI 1 - CHUONG 4------" << endl;
	cout << "1. Khoi tao cay rong" << endl;
	cout << "2. Them 1 phan tu vao cay" << endl;
	cout << "3. Tim 1 phan tu trong cay" << endl;
	cout << "4. Xoa 1 phan tu trong cay" << endl;
	cout << "5. Duyet cay theo thu tu NLR" << endl;
	cout << "6. Duyet cay theo thu tu LNR" << endl;
	cout << "7. Duyet cay theo thu tu LRN" << endl;
	cout << "0. Thoat" << endl;
}
void main()
{
	int choice;
	int x, kq;

	menu();
	do{
		cout << "Chon so de thuc hien: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			init();
			cout << "Khoi tao rong thanh cong" << endl;
			break;
		case 2:
			cout << "Nhap gtri muon them: ";
			cin >> x;
			insert(root, x);
			cout << "Them gtri x = " << x << " vao cay thanh cong" << endl;
			cout << "Cay NPTK sau khi them la: ";
			outputTree();
			break;
		case 3:
			cout << "Nhap ptu can tim: ";
			cin >> x;
			kq = search(root, x);
			if (kq == 1)
				cout << "Gtri x = " << x << " khong ton tai trong cay" << endl;
			else
				cout << "Gtri x = " << x << " duoc tim thay trong cay" << endl;
			break;
		case 4:
			cout << "Nhap phan tu muon xoa: ";
			cin >> x;
			kq = deleteNode(root, x);
			if (kq == 1)
			{
				cout << "Da xoa thanh cong gtri x = " << x << endl;
				cout << "Cay NPTK sau khi xoa la: ";
				outputTree();
			}
			else
				cout << "Khong tim thay gtri x = " << x << " trong cay de xoa" << endl;
			break;
		case 5:
			cout << "Danh sach sau khi duyet NLR: ";
			duyetNLR(root);
			break;
		case 6:
			cout << "Danh sach sau khi duyet LNR: ";
			duyetLNR(root);
			break;
		case 7:
			cout << "Danh sach sau khi duyet LRN: ";
			duyetLRN(root);
			break;
		default:
			cout << "GOODBEY!..." << endl;
		}
	} while(choice != 0);
}