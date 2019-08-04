#include <iostream>
using namespace std;

#define count 10
//1.1 khai bao cau truc cay nhi phan
struct node 
{
	int info;
	node *left;
	node *right;
};
node *root;
//1.2 khoi tao cay rong
void init()
{
	root = NULL;
}
//1.3 them 1 phan tu vao cay nhi phan
void them(node *&p, int x)
{
	if(p == NULL){
		p = new node;
		p->info = x;
		p->left = NULL;
		p->right = NULL;
	}
	else
	{
		if (p->info == x)
			return;
		else
			if(p->info > x)
				return them(p->left, x);
			else
				return them(p->right, x);
	}

}
//1.4 tim kiem 1 nut trong cay
int tim(node *p, int x)
{
	if(p != NULL)
	{
		if (p->info == x)
			return 1;
		else
			if(p->info < x)
				return tim(p ->right, x);
			else
				return tim(p->left, x);
	}
	return 0;
}
//1.5 xoa 1 nut trong cay
void timDeXoa(node *&p, node *&q)
{
	if (q ->left == NULL)
	{
		p ->info = q ->info;
		p = q;
		q = q->right;
	}
	else
		timDeXoa(p , q->left);

}
int xoa(node *T, int x)
{
	if (T == NULL)
		return 0;
	if (T->info ==x)
	{	
		node *p = T;
		if(T ->left == NULL)
			T = T->right;
		else
			if (T->right ==NULL)
				T = T->left;
			else
				timDeXoa(p, T->right);
		delete p;
		return 1;
	}
	if (T ->info < x)
		xoa(T->right,x);
	if (T ->info > x)
		xoa(T->left,x);
}
//1.6 duyet cay theo NLR
void duyetNLR(node *p)
{
	if (p != NULL)
	{
		cout << p->info << " ";
		duyetNLR(p->left);
		duyetNLR(p->right);
	}
}
//1.6 duyet cay theo LNR
void duyetLNR(node *p)
{
	if (p != NULL)
	{
		duyetLNR(p->left);
		cout << p->info << " ";
		duyetLNR(p->right);
	}
}
//1.6 duyet cay theo LRN
void duyetLRN(node *p)
{
	if (p != NULL)
	{
		duyetLRN(p->left);
		duyetLRN(p->right);
		cout << p->info << " ";
	}
}
//OUTPUTTREE
void print(node *p, int space)
{
	if (p == NULL)
		return;
	space += count;
	print(p->right, space);
	cout << endl;
	for (int i = count; i < space; i++)
		cout << " ";
	cout << p->info << endl;
	print(p->left, space);
}
void printTree()
{
	print(root, 0);
}
//MENU
void menu()
{
	cout << "--------Bai 1 - Chuong 4 --------" << endl;
	cout << "1.Khoi tao cay rong" << endl;
	cout << "2.Them 1 phan tu vao cay" << endl;
	cout << "3.tim 1 phan tu trong cay" << endl;
	cout << "4.Xoa mot nut trong cay" << endl;
	cout << "5.Duyet cay theo thu tu NLR "<< endl;
	cout << "6.Duyet cay theo thu tu LNR " << endl;
	cout << "7.Duyen cay theo thu tu LRN " << endl;
	cout << "0.Thoat" << endl;
}


void main()
{
	int choice;
	int x, kq;

	menu();
	do{
		cout << "chon 1 so de thuc hien: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			init();
			cout << "Khoi tao rong thanh cong" << endl;
			break;
		case 2:
			cout << "Nhap ptu muon them: ";
			cin >> x;
			them(root, x);
			cout << "Them ptu x = " << x << " thanh cong" << endl;
			cout << "Cay NPTK sau khi them la: ";
			printTree();
			break;
		case 3:
			cout << "Nhap ptu can tim: ";
			cin >> x;
			kq = tim(root, x);
			if (kq == 1)
				cout << "Ptu x = " << x << " duoc tim thay trong cay" << endl;
			else
				cout << "Ptu x = " << x << " khong ton tai trong cay" << endl;
		case 4:
			cout << "nhap ptu muon xoa: ";
			cin >> x;
			kq = xoa(root, x);
			if (kq == 1)
			{
				cout << "Xoa ptu x = " << x << " thanh cong" << endl;
				cout << "Cay NPTK sau khi xoa la: ";
				printTree();
			}
			else
				cout << "Xoa ptu khong thanh cong" << endl;
			break;
		case 5:
			cout << "Duyet theo thu tu NLR: ";
			duyetNLR(root);
			break;
		case 6:
			cout << "Duyet theo thu tu LNR: ";
			duyetLNR(root);
			break;
		case 7:
			cout << "Duyet theo thu tu LRN: ";
			duyetLRN(root);
			break;
		default:
			cout << "GOODBEY!...." << endl;
		}
	} while(choice != 0);
}