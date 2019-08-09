#include <iostream>
using namespace std;
#define COUNT 10
struct Node
{
	int info;
	Node *left;
	Node *right;
};
Node *root;
void tree_empty()
{
	root = NULL ;
}
void InsertNode( Node *&p, int x)
{
	if(p!=NULL)
	{
		p  = new Node;
		p->info = x;
		p->left = NULL;
		p->right = NULL;
	}
	else
	{
		if(p->info == x)
			return ;
		else if(p->info > x)
			return InsertNode(p->left, x);
		else
		return InsertNode(p->right,x);
	}
}
Node *Search(Node *p, int x)
{
	while(p!=NULL)
	{
		if(p->info == x)
			return p;
		else
			if(p->info > x)

				p= p->left;
			else
				p = p->right;
	}
	return NULL;
}
void searchStandFor(Node *&p, Node *q)
{
	if(q->left ==NULL)
	{
		p->info == q->info;
		p = q;
		q = q->right;
	}
	else
		searchStandFor(q,p->left);
}
int Delete(Node *&T, int x)
{
	if( T==NULL ) return 0;
	if(T->info == x)
	{
		Node *p = T;
		if(T->left == NULL)
			T= T->left;
		else if (T->right == NULL)
			T= T->left;
		else // co 2 con
			searchStandFor(p, T->right);
		delete p;
		return 1;
	}
	if(T->info < x)
		return Delete(T->right,x);
	if(T->info > x) 
		return Delete(T->left,x);
}
//NLR
void duyetNLR(Node *p)
{
	if(p!= NULL)
	{
		cout <<p->info <<"\t";
		duyetNLR(p->left);
		duyetNLR(p->right);
	}
}
//LNR
void duyetLNR(Node *p)
{
	if(p!= NULL)
	{
		duyetLNR(p->left);
		cout <<p->info << "\t";
		duyetLNR(p->right);
	}
}
//LRN
void duyetLRN(Node *p)
{
	if(p!= NULL)
	{
		duyetLNR(p->left);
		duyetLNR(p->right);
		cout <<p->info << "\t";
	}
}
void print2DUtil(Node *p, int space)
{
	if( p ==NULL)
		return;
	space += COUNT;
	print2DUtil(p->right,space);
	cout <<endl;
	for(int i= COUNT;i<space;i++)
		cout << " ";
	cout << p->info <<"\n";
	print2DUtil(p->left,space);
}
void Process_tree()
{
	print2DUtil(root,0);
}

int main()
{
	int choice= 0;
	int x, i;
	Node *p;
	system("cls");
	cout <<" ----------   BAI TAP 1, CHUONG 4, CAY NPTK   ----------" <<endl;
	cout <<"1. Khoi tao cay NPTK rong"<<endl;
	cout <<"2. Them phan tu vao cay NPTK" <<endl;
	cout <<"3. Tim phan tu co gia tri x trong cay NPTK " <<endl;
	cout <<"4. Xoa phan tu co gia tri X trong cay NPTk " <<endl;
	cout <<"5. Duyet cay NPTK theo LNR"<<endl;
	cout <<"6. Duyet cay NPTK theo NLR"<<endl;
	cout <<"7. Duyet cay NPTK theo LRN"<<endl;
	cout <<"8. Xuat cay NPYK " <<endl;
	cout <<"9.Thoat" <<endl;
	do{
		cout<<"chon so thuc hien " << endl;
		cin >> choice;
	switch(choice)
	{
	case 1:
		tree_empty();
		cout <<"ban vua khoi tao cay NPTK thanh cong \n";
		break;
	case 2:
		cout <<"Vui long nhap gia tri x can them \n";
		cin >> x;
		InsertNode(root,x);
		cout <<" Cay NPTK sau khi them la: \n";
		Process_tree();
		break;
	case 3:
		cout <<"Vui long nhap gia tri x can tim \n";
		cin >> x;
		p = Search(root,x);
		if(p!=NULL)
			cout << "Tim thay x= " << x << " trong cay NPTK " <<endl;
		break;
	case 4:
		cout << "Vui long nhap gia tri x can xoa" <<endl;
		cin >> x;
		i = Delete(root, x);
		if(i == 0)
			cout << "khong tim thay x de xoa "<<endl;
		else
		{
			cout <<"Da xoa thanh cong phan tu trong cay NPTK "<<endl;
			cout <<"Cay NPTK sau khi xoa la: "<<endl;
			Process_tree();
		}
		break;
	case 5:
		cout <<" Cay NPTK duyet theo LNR la :" <<endl;
		duyetLNR(root);
		break;
	case 6:
		cout <<" Cay NPTK duyet theo NLR la :" <<endl;
		duyetNLR(root);
		break;
	case 7:
		cout <<" Cay NPTK duyet theo LRN la :" <<endl;
		duyetLRN(root);
		break;
	case 8:
		cout << "Cay NPTK nhu sau: "<<endl;
		Process_tree();
		break;
	case 9:
		cout <<"Goodbye    @ ! @ " <<endl;
		break;
	default:
		break;
	}
	}while(choice != 9);
	system("pause");
	return 1;

}