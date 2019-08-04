#include <iostream>
using namespace std;
//1.1 khai bao cau truc cay 
struct Node
{
	int info;									//luu tru gia tri cua phan tu, gia tri cua node
	Node *left;									//left luu dia chi phan tu ben trai(cay con trai)
	Node *right;								//right luu dia chi phan tu ben phai(cay con phai)
};
Node *root;

//1.2 Khoi tao cay rong
void tree_empty()
{
	root = NULL;								//root la bien toan cuc
}

void init()
{
	root = NULL;
}
Node *p = root;

//xuat cay nhi phan
void print(Node *p, int space)
{
	int COUNT = 10;
	if (p == NULL)
		return ;
	space += COUNT;
	print(p->right, space);
	cout << endl;
	for (int i = COUNT; i < space; i ++)
		cout << " ";
	cout << p->info << endl;
	print(p->left, space);
}
void Process_print()
{
	print(root, 0);
}

//1.3 Them phan tu vao cay (de quy)
void insert_Node(Node *&p, int x)
{
	if (p == NULL)
	{
		p=new Node;
		p->info = x;
		p->left = NULL;
		p->right = NULL;
	}
	else 
	{
		if (p->info == x)
			return;
		else if (p->info > x)
			return insert_Node(p->left, x);
		else
			return insert_Node(p->right, x);
	}
}
int insert_Node1(Node *p, int x)
{
	if(p->info > x)
		return 0;
	else if(p->info > x)
	{
		if(p->left == NULL)
		{
			Node *y = new Node;
			y->info = x;
			y->left = NULL;
			y->right = NULL;
			p->left = y;
			return 1;
		}
		else return insert_Node1(p->left, x);
	}
	else
	{
		if(p->right == NULL)
		{
			Node *y = new Node;
			y->info = x;
			y->left = NULL;
			y->right = NULL;
			p->right = y;
			return 1;
		}
		else
			return insert_Node1(p->right, x);
	}
}

//1.4 Tim phan tu trong cay (de quy)
Node *search(Node *p, int x)
{
	if(p != NULL)
	{
		if (p->info == x)
			return p;
		else
			if(x > p->info)
				return search(p->right, x);
			else
				return search(p->left, x);
	}
	return NULL;
}

//1.5 Xoa mot nut trong cay (de quy)
void searchStandFor(Node *&p, Node *&q)
{
	if(q->left == NULL)
	{
		p->info = q->info;
		p = q;
		q = q -> right;
	}
	else
		searchStandFor(p, q->left);
}

int Delete(Node *&T, int x)
{
	if(T == NULL) 
		return 0;
	if (T->info == x)
	{
		Node *p = T;
		if(T->left == NULL)
			T = T->right;
		else if(T->right == NULL)
			T=T->left;
		else													//co 2 con
			searchStandFor(p, T->right);
		delete p;
		return 1;
	}
	if(T->info < x) 
		return Delete(T->right, x);
	if(T->info > x)
		return Delete(T->left, x);
}

//1.6 Duyet cay the thu tu NLR (de quy)
void duyetNLR(Node *p)
{
	if(p != NULL)
	{
		cout << p->info << " ";
		duyetNLR(p->left);
		duyetNLR(p->right);
	}
}

//1.7 Duyet cay the thu tu LNR (de quy)
void duyetLNR(Node *p)
{
	if(p != NULL)
	{
		duyetLNR(p->left);
		cout << p->info << " ";
		duyetLNR(p->right);
	}
}

//1.8 Duyet cay the thu tu LRN (de quy)
void duyetLRN(Node *p)
{
	if(p != NULL)
	{
		duyetLNR(p->left);
		duyetLNR(p->right);
		cout << p->info << " ";
	}
}

//dem so Node
int countNode(Node *p)
{
	if (p == NULL)
		return 0;
	else
		return 1 + countNode(p->left) + countNode(p->right);
}

//tim Max cua cay nhi phan
int timMax(Node *p)
{
	if (p == NULL)
		return INT_MIN;
	else
	{
		while (p->right != NULL)
			p = p->right;
		return p->info;
	}
}

//dem node nhanh trai
int countNodeLeftTree(Node *p)
{
	if (p == NULL || p -> left == NULL)
		return 0;
	else 
		return countNode(p->left);
}

int main()
{
	int x;
	int choose;
	char cont;
	do{
		cout << "MENU:\n"
			<< "1. Khoi tao cay rong\n"
			<< "2. Them 1 node vao cay\n"
			<< "3. Tim 1 phan tu trong cay\n"
			<< "4. Xoa 1 phan tu trong cay \n"
			<< "5. Duyet NLR\n"
			<< "6. Duyet LNR\n"
			<< "7. Duyet LRN\n"
			<< "Ban chon: ";
		cin >> choose;
		switch(choose)
		{
		case 1:
			init();
			cout << "Khoi tao thanh cong\n";
			break;
		case 2:
			cout << "Nhap gia tri can them: ";
			cin >> x;
			insert_Node(root, x);
			cout << "Phn tu nhi phan sau khi them: \n";
			Process_print();
			break;
		case 3:
			cout << "Nhap phan tu can tim: ";
			cin >> x;
			search(root, x);
			break;
		case 4:
			break;
		case 5:
			cout << "Ket qua duyet NLR: ";
			duyetNLR(root);
			cout << endl;
			break;
		case 6:
			cout << "Ket qua duyet LNR: ";
			duyetLNR(root);
			cout << endl;
			break;
		case 7:
			cout << "Ket qua duyet LRN: ";
			duyetLRN(root);
			cout << endl;
			break;
		case 8:
			cout << "Cay nhi phan co " << countNode(root) << " node\n";
			break;
		case 9:
			if (timMax(root) == INT_MIN)
				cout << "cay rong, nen khong co gia tri lon nhat\n";
			else
				cout << "gia tri lon nhat trong cay laf: " << timMax(root) << endl;
			break;
		case 10:
			cout << countNodeLeftTree(root) << endl;
			break;
		}
		cout << "Ban co muon tiep tuc (y/n): ";
		cin >> cont;
	} while (cont == 'y' || cont == 'Y');
}

